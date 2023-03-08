#include "global.h"
#include "DHT11.h"
#include "LCD_I2C.h"
#include "DS18B20.h"
#include "WS2812.h"
#include "atuadores.h"
#include "IHM.h"
#include "leituraAD.h"
#include "timer.h"
#include "verificacaoErros.h"
#include "conversao.h"
#include "ESP_I2C.h"
unsigned short int erro_I2C;
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
  if (PIR1.TMR1IF)
  {
    timer1++;
    PIR1.TMR1IF = 0;
  }

  if (PIR1.ADIF)
  {
    PIR1.ADIF = 0;
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
  leituraPortasAnalogicas();            // faz a leitura das 9 entradas analogicas
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
  default:
    break;
  }
  atualizar = 0;
}
void verificarEspNotificacoes()
{
  unsigned short int valor;
  char topic[6], value[5];
  if (I2C1_Is_Idle)
  {
    readTopic(&topic[0], &value[0]);

    if (topic[0] != '0')
    {
      LCD_Clear();
      LCD_Out(1, 1, topic);
      LCD_Out(2, 1, value);
      if (!strcmp(topic, topicCoolerAguaUser))
      {
        value[2] == '1' ? controleCoolerAgua(1, LIGAR) : controleCoolerAgua(1, DESLIGAR);
      }
      else if (!strcmp(topic, topicCoolerPlantaUser))
      {
        value[2] == '1' ? controleCoolerAmbiente(1, LIGAR) : controleCoolerAmbiente(1, DESLIGAR);
      }
      else if (!strcmp(topic, topicLedsUser))
      {
        value[2] == '1' ? controleLed(1, LIGAR) : controleLed(1, DESLIGAR);
      }
      else if (!strcmp(topic, topicMotorAuxiliarUser))
      {
         valor= charToInt(value);
      }
      else if (!strcmp(topic, topicMotorPrincipalUser))
      {
        dutyCicle1 = ((value[0]-48)*100)+((value[1]-48)*10)+((value[2]-48));
        setPWM1();
      }
      else if (!strcmp(topic, topicResistenciaUser))
      {
        value[2] == '1' ? controleResistenciaAmbiente(1, LIGAR) : controleResistenciaAmbiente(1, DESLIGAR);
      }
    }
  }
}

void main()
{
  unsigned short int time_erro;
  unsigned short int endereco_i2c = 0, teste_i2c, erro_I2C = 0;
  char teste[3];
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
  modoFuncionamento = AUTOMATICO;
  //******************************************************************************
  //   FIM CONFIGURA��ES CONVERSOR ANALOGICO DIGITAL
  //******************************************************************************

  //******************************************************************************
  //   Inicializa��o
  //******************************************************************************
  //  flagLeituraTeclado = 0;
  I2C1_Init(100000); // Inicializa comunica��o I2C
  // set timeout period and callback function

  LCD_Init();
  LCD_Clear();
  LCD_Out(1, 1, "PLANTAE SOLUCOES");
  LCD_Out(2, 1, "*******-********");
  delay_ms(100);
  iniciaTeclado();
  controlePWM1(1, LIGAR);
  // verificaSensores();
  startTimer0();
  atualizar = atualizaLCD;
  LCD_Clear();
  for (;;) // LOOP
  {
    if (timer0 > 10)
    {
      timer0 = 0;
      verificaSensores(); // Verifica sensores
      analisarVariaveis();
      time_erro++;
      atualizar = atualizaLCD;

      if (time_erro++ > 3)
      {
        verificarErros();
      }
    }
    // else if (timer0 % 2 == 0 && timer0 < 10)
    // {
    if (atualizar > 0)
    {
      atualizarInformacoes();
    }
    // }
    verificaPressionamentoTeclado();
    verificarEspNotificacoes();
  }
} // FINAL LOOP
  // FINAL MAIN