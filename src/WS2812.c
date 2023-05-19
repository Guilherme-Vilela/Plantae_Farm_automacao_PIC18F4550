#include "WS2812.h"
#include "timer.h"
// bliblioteca para funcionamento dos leds

void enviarBit1()
{
   /*
   bit 1 = 1 = 1200ns
   bit 1 = 0 = 1300ns
   */
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
}

void enviarBitFinal(){
  /*
   bit 0 = 1 = 500ns
   bit 0 = 0 = 2000ns
   */
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 0;
}
void enviarBit0()
{
   /*
   bit 0 = 1 = 500ns
   bit 0 = 0 = 2000ns
   */
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;
   LED_PIN = 1;

   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
   LED_PIN = 0;
}
void ligar_led(unsigned short int quantidade)
{
   unsigned short int posicao;
   LED_PIN_DIR = 0;
   LED_PIN = 1;
   LED_PIN = 0;
   delay_us(100);
   for (posicao = 0; posicao < quantidade; posicao++)
   {
      if (posicao % 2 == 0)
      {
       LED_PIN = 0;
       LED_PIN = 0;
       LED_PIN = 0;
       vermelho();
      }
      else
      {
         azul();
      }
   }
   LED_PIN = 1;
   LED_PIN = 0;
   delay_us(100);
}
void desliga_led(unsigned short int quantidade)
{
   unsigned short int posicao;
   LED_PIN_DIR = 0;
   LED_PIN = 1;
   LED_PIN = 0;
   delay_us(50);
   for (posicao = 0; posicao < quantidade; posicao++)
   {
      preto();
   }
   LED_PIN = 1;
   LED_PIN = 0;
   delay_us(50);
}
void vermelho()
{
   // AZUL
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   //  FIM AZUL
   // INICIO VERDE
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   // FIM VERDE
   // INICIO VERMELHO
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBitFinal();
   // FIM VERMELHO
}
void azul()
{
   // AZUL
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   enviarBit1();
   //  FIM AZUL
   // INICIO VERDE
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   // FIM VERDE
   // INICIO VERMELHO
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBitFinal();
   // FIM VERMELHO
}
void preto()
{
   // AZUL
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   //  FIM AZUL
   // INICIO VERDE
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   // FIM VERDE
   // INICIO VERMELHO
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBit0();
   enviarBitFinal();
   // FIM VERMELHO
}