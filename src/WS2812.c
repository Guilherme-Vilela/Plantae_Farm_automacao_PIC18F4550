#include "WS2812.h"
#include "timer.h"
// bliblioteca para funcionamento dos leds
void enviarBit0()
{
unsigned short i;
for(i=0;i<23;i++){
     asm{
     BSF PORTD, 3
     NOP
     NOP
     
     
     BCF PORTD, 3
     NOP
      NOP
       NOP
     }
      }
}

void enviarBit1()
{
}
void vermelho()
{
enviarBit0();


}

void ligaleds()
{
}