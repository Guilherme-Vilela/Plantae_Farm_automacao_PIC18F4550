#include "atuadores.h"
#include "WS2812.h"
//FUN��ES DE AMBIENTE
void ligaCoolerAmbiente(){
 COOLER_AMBIENTE_TRIS = 0;
 COOLER_AMBIENTE = 1;
}
void desligaCoolerAmbiente(){
 COOLER_AMBIENTE_TRIS = 0;
 COOLER_AMBIENTE = 0;
}
void ligaResistenciaAmbiente(){
 RESISTENCIA_TRIS_AMBIENTE = 0;
 RESISTENCIA_AMBIENTE = 1;
}
void desligaResistenciaAmbiente(){
 RESISTENCIA_TRIS_AMBIENTE = 0;
 RESISTENCIA_AMBIENTE = 0;
}
//FUN��ES DE AMBIENTE

//FUN��ES DE AGUA
void ligaCoolerAgua(){
 COOLER_AGUA_TRIS = 0;
 COOLER_AGUA = 1;
}
void desligaCoolerAgua(){
 COOLER_AGUA_TRIS = 0;
 COOLER_AGUA = 0;
}
void ligaResistenciaAgua(){
 RESISTENCIA_TRIS_AGUA = 0;
 RESISTENCIA_AGUA = 1;
}
void desligaResistenciaAgua(){
 RESISTENCIA_TRIS_AGUA = 0;
 RESISTENCIA_AGUA = 0;
}
//FUNCOES DE AGUA
//FUNCOES DOS LEDS
void ligaLed(){
   vermelho();
   azul();
   vermelho();
   azul();
   vermelho();
   azul();
   vermelho();
   azul();
}
void desligaLed(){
    preto();
    preto();
    preto();
    preto();
    preto();
    preto();
    preto();
    preto();
}