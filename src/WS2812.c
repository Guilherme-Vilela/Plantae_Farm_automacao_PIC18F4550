#include "WS2812.h"
//bliblioteca para funcionamento dos leds
void enviarBit1(){
 RE1_bit = 1;
 RE1_bit = 1;
 RE1_bit = 1;
 RE1_bit = 1;
 RE1_bit = 0;
 RE1_bit = 0;
}
void enviarBit0(){
 RE1_bit = 1;
 RE1_bit = 1;
 RE1_bit = 0;
 RE1_bit = 0;
 RE1_bit = 0;
 RE1_bit = 0;

}
 void vermelho(){
 unsigned short int i;
 for(i=0; i < 8; i++){
  enviarBit0();
 }
  for(i=0; i < 8; i++){
  enviarBit1();
 }
  for(i=0; i < 8; i++){
  enviarBit0();
 }
}
void azul(){
 unsigned short int i;
 for(i=0; i < 16; i++){
  enviarBit0();
 }
  for(i=0; i < 8; i++){
  enviarBit1();
 }
 }
void preto(){
 unsigned short int i;
 for(i=0; i < 24; i++){
  enviarBit0();
 }
 }
