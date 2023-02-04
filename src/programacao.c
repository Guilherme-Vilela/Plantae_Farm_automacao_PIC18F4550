
#include "global.h"
#include "DHT11.h"
#include "LCD_I2C.h"
#include "DS18B20.h"
#include "WS2812.h"
#include "atuadores.h"
#include "IHM.h"
#include "plantas.h"
#include "ESP_I2C.h"
#include "leituraAD.h"
#include "timer.h"
//#include "verificacaoErros.c"


//******************************************************************************
//   VOID DE INTERRUP��ES
//**************************0****************************************************

void interrupt(void){        //Interrup��es de alta prioridade

}
 void interrupt_low(void){   //Interrup��es de baixa prioridade


    if(INTCON.RBIF){
      if(!RB4_bit){   //RB4 INT_TECLADO  INTERRUP��O DE TECLADO
      if(flagLeituraTecladoEmAndamento == 0){ //verifica se uma leitura ja n�o esta ocorrendo
        flagLeituraTeclado = 1;    //da start na interrup��o e inicia captura da tecla
       }
      }
      if(!RB5_bit){     //RB5 INT_REDE    INTERRUP��O DE REDE ELETRICA, ATIVA NOBREACK
      }
      if(!RB6_bit){  //verifica se o motor 1 n�o esta em sobre corrente
      }
      if(!RB7_bit){   //RB7 INT_ESP   INTERRUP��O ESP, READ I2C ESP
      }
      INTCON.RBIF = 0;
    }
    if(INTCON.TMR0IF){
     timer0++;
     INTCON.TMR0IF =0;
    }
    if(PIR1.TMR1IF){
     timer1++;
     PIR1.TMR1IF = 0;
    }
 }

//******************************************************************************
//   FIM VOID DE INTERRUP��ES
//******************************************************************************
void verificaSensores()
{
  leituraDht11(&umidade, &temperatura); // leitura de valores DHT11
  leituraDs18b20(&temperaturaAgua);            //LEITURA TEMPERATURA DA �GUA
  leituraPortasAnalogicas(); //faz a leitura das 9 entradas analogicas
  
//  luminosidade = ADC_Read(PIN_LDR)/ 10;           // Captura valor na porta analogica
  

//  verificaAtuadores();
//  verificarErros();           //VALIDA��O DE ERROS
}

void main()
{
  bit inicializacao;
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
  RCON = 0b10000000;

  //******************************************************************************
  //   FIM CONFIGURA��ES DE INTERRUP��O
  //******************************************************************************

  //******************************************************************************
  //   CONFIGURA��ES DE TRIS
  //******************************************************************************
  TRISC0_bit = 1; // CONFIG SENSOR CANO COMO ENTRADA
  //TRISD0_bit = 0;
  TRISD1_bit = 1;
  TRISA = 0b11111111;
  TRISB = 0b11110000;
  //******************************************************************************
  //   FIM CONFIGURA��ES DE TRIS
  //******************************************************************************[
  //******************************************************************************
  //   CONFIGURA��ES DE TIMER 0
  //******************************************************************************
  T0CON = 0x87; // CONFIG T0CON PRE ESCALER 256  16BITS
  T1CON = 0x30;  //CONFIG PARA TIMER 1
  //******************************************************************************
  //   FIM CONFIGURA��ES DE TIMER 0
  //******************************************************************************
  //******************************************************************************
  //   CONFIGURA��ES CONVERSOR ANALOGICO DIGITAL
  //******************************************************************************
  ADCON0 = 0b00000000; //
  ADCON1 = 0b00001011; // HABILITA DE A0 ATE A3 COMO ENTRADA ANALOGICA
  ADCON2 = 0b10000000;

  //******************************************************************************
  //   FIM CONFIGURA��ES CONVERSOR ANALOGICO DIGITAL
  //******************************************************************************

  //******************************************************************************
  //   Inicializa��o
  //******************************************************************************
  delay_ms(500);

  I2C1_Init(100000); // Inicializa comunica��o I2C
  // inciializa��o do LCD
   LCD_Init();
   LCD_Clear();
   LCD_Out(1,1," PLANTACAO");
   LCD_Out(2,1,"****************");
   delay_ms(1000);
  // incializa��o do LCD

  // incializa��o do TECLADO
  I2C1_Start();  // Inicia I2C
  I2C1_Wr(0x40); // Envia o byte por I2C (endere�o do dispositivo + Write)
  I2C1_Wr(0x0F);
  I2C1_Stop();
  //******************************************************************************
  //   FIM inicializa��o
  //******************************************************************************
  verificaSensores();

  
  movimentaMenu(0);

  /*if(planta_cultivada != 255 && inicializacao == 0){
   inicializacao = 1;
   iniciarPWM();
   timer0 = 0;

  }*/

  for (;;)
  { // LOOP
    if (timer0 > 1)
    {
      timer0 = 0;
      verificaSensores();         //VALIDA��O DE ERROS
    }
    if (atualizaMenu)
    {
      atualizaMenu = 0;
    }
     verificaPressionamentoTeclado();

  } // FINAL LOOP
} // FINAL MAIN