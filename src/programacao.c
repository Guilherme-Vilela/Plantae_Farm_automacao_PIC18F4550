
#include "global.h"
#include "DHT11.h"
#include "LCD_I2C.h"
#include "DS18B20.h"
#include "WS2812.h"
#include "atuadores.h"
#include "IHM.h"
#include "ESP_I2C.h"
#include "leituraAD.h"
#include "timer.h"
#include "verificacaoErros.h"
#include "PWM.h"
// #include "plantas.h"
//******************************************************************************
//    VOID DE INTERRUP��ES
//**************************0****************************************************

void interrupt(void)
{ // Interrup��es de alta prioridade
  if (INTCON.TMR0IF)
  {
    timer0++;
    INTCON.TMR0IF = 0;
  }
  if (INTCON.RBIF)
  {
    if (!RB4_bit)
    { // RB4 INT_TECLADO  INTERRUP��O DE TECLADO
      if (flagLeituraTecladoEmAndamento == 0)
      {                         // verifica se uma leitura ja n�o esta ocorrendo
        flagLeituraTeclado = 1; // da start na interrup��o e inicia captura da tecla
      }
    }
    if (!RB5_bit)
    { // RB5 INT_REDE    INTERRUP��O DE REDE ELETRICA, ATIVA NOBREACK
      falhaRedeEnergia = 1;
    }
    if (!RB6_bit)
    {
    }
    if (!RB7_bit)
    { // RB7 INT_ESP   INTERRUP��O ESP, READ I2C ESP
      leituraEspDisponivel = 1;
    }
    INTCON.RBIF = 0;
  }
  if (PIR1.TMR1IF)
  {
    timer1++;
    PIR1.TMR1IF = 0;
  }

  if (PIR1.ADIF)
  {
    PIR1.ADIF = 0;
  }
}
void interrupt_low(void)
{ // Interrup��es de baixa prioridade
}

//******************************************************************************
//   FIM VOID DE INTERRUP��ES
//******************************************************************************
void verificaSensores()
{
  leituraDht11(&umidade, &temperatura); // leitura de valores DHT11
  leituraDs18b20(&temperaturaAgua);     // LEITURA TEMPERATURA DA �GUA

  leituraPortasAnalogicas(); // faz a leitura das 9 entradas analogicas
  //  ligaResistenciaAmbiente();
  //  analisarSensores();
  //  ligaCoolerAgua();

  //   verificaAtuadores();
  //  verificarErros();           //VALIDA��O DE ERROS
}
void atualizarInformacoes()
{
  switch (atualizar)
  {
  case atualizaMenuEntrar:
    movimentaMenu('A');
    break;
  case atualizaMenuSair:
    movimentaMenu('B');
    break;
  case atualizaMenuAvancar:
    movimentaMenu('C');
    break;
  case atualizaMenuVoltar:
    movimentaMenu('D');
    break;
  case atualizaLCD:
    movimentaMenu('X');
    break;
  case atualizarPWM1:
    setPWM1();
    break;
  default:
    break;
  }
  atualizar = 0;
}
void I2C1_TimeoutCallback(char errorCode)
{
  erroI2c = 1;
  I2C1_Stop();
  if (errorCode == _I2C_TIMEOUT_RD)
  {

    // do something if timeout is caused during read
  }

  if (errorCode == _I2C_TIMEOUT_WR)
  {
    // do something if timeout is caused during write
  }

  if (errorCode == _I2C_TIMEOUT_START)
  {
    // do something if timeout is caused during start
  }

  if (errorCode == _I2C_TIMEOUT_REPEATED_START)
  {
    // do something if timeout is caused during repeated start
  }
}
void main()
{
  delay_ms(500);
  //******************************************************************************
  //   CONFIGURA��ES DE INTERRUP��O
  //******************************************************************************
  INTCON = 0b11101000;
  INTCON2 = 0b10000000;
  INTCON3 = 0b00000000;
  PIR1 = 0b00000000;
  PIR2 = 0b00000000;
  PIE1 = 0b00000001;
  PIE2 = 0b00000000;
  IPR1 = 0b00000000;
  IPR2 = 0b00000000;
  RCON = 0b00000000;

  //******************************************************************************
  //   FIM CONFIGURA��ES DE INTERRUP��O
  //******************************************************************************

  //******************************************************************************
  //   CONFIGURA��ES DE TRIS
  //******************************************************************************
  TRISA = 0b11111111;
  TRISB = 0b11111111;
  TRISC = 0b00001110;
  TRISD = 0b00000011;
  TRISE = 0b11111111;
  //******************************************************************************
  //   FIM CONFIGURA��ES DE TRIS
  //******************************************************************************[
  //******************************************************************************
  //   CONFIGURA��ES DE TIMER 0
  //******************************************************************************
  T0CON = 0x07; // CONFIG T0CON PRE ESCALER 256  16BITS
  T1CON = 0x30; // CONFIG PARA TIMER 1
  //******************************************************************************
  //   FIM CONFIGURA��ES DE TIMER 0
  //******************************************************************************
  //******************************************************************************
  //   CONFIGURA��ES CONVERSOR ANALOGICO DIGITAL
  //******************************************************************************

  ADCON0 = 0b00000001; //
  ADCON1 = 0b00000101; // HABILITA DE A0 ATE A9 COMO ENTRADA ANALOGICA
  ADCON2 = 0b00111110;

  //******************************************************************************
  //   FIM CONFIGURA��ES CONVERSOR ANALOGICO DIGITAL
  //******************************************************************************

  //******************************************************************************
  //   Inicializa��o
  //******************************************************************************

  //  flagLeituraTeclado = 0;
  I2C1_Init(100000); // Inicializa comunica��o I2C
  I2C1_SetTimeoutCallback(100, I2C1_TimeoutCallback);
  // set timeout period and callback function

  LCD_Init();
  LCD_Clear();
  LCD_Out(1, 1, "PLANTAE SOLUCOES");
  LCD_Out(2, 1, "*******-********");

  iniciaTeclado();
  iniciarPWM();
  ligaCoolerAmbiente();
  verificaSensores();

  startTimer0();
  delay_ms(100);
  for (;;) // LOOP
  {
    if (timer0 > 10)
    {
      timer0 = 0;
      // erroI2c = 0;
      verificaSensores(); // VALIDA��O DE ERROS
      atualizar = atualizaLCD;
    }
    if (atualizar > 0)
    {
      atualizarInformacoes();
    }
    verificaPressionamentoTeclado();

  } // FINAL LOOP
} // FINAL MAIN