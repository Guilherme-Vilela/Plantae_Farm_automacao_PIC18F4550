#include "global.h"
#include "LCD_I2C.h"
#include "IHM.h"
#include "cultivo.h"
#include "timer.h"
#include "verificacaoAnalise.h"
#include "conversao.h"
#include "ESP_I2C.h"
#include "WS2812.h"
#include "atuadores.h"

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

void main()
{
  unsigned short int time_erro;
  unsigned short int endereco_i2c = 0, teste_i2c, erro_I2C = 0;
  char teste[3];
  /*delay_ms(500);*/
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
  LCD_Init();
  LCD_Clear();
  LCD_Out(1, 1, "PLANTAE SOLUCOES");
  LCD_Out(2, 1, "*******-********");
  delay_ms(1000);
  iniciaTeclado();
  atualizar = atualizaLCD;
  atualizarInformacoes();
   desliga_led(100);
   delay_ms(1000);
   ligar_led(100);
   ligar_led(100);



  while (cultivoSelecionado == 0)
  { // espera o cultivo ser selecionado
    verificaPressionamentoTeclado();
   // verificarEspNotificacoes();
  }

  enviarParametros();
  startTimer0();
  verificarSensores();
  for (;;) // LOOP
  {
    if (timer0 > 10)
    {
      timer0 = 0;
      verificarSensores(); // Verifica sensores
      analisarVariaveis();
      time_erro++;
      atualizar = atualizaLCD;

      // if (time_erro > 3)
      // {
      //   verificarErros();
      //   time_erro =0;
      // }
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