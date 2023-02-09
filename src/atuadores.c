#include "atuadores.h"
#include "WS2812.h"
#include "global.h"
#include "ESP_I2C.h"
// FUN��ES DE AMBIENTE

unsigned short int verificarSolicitante(unsigned short int solicitante)
{
  if (solicitante == MICROCONTROLADOR && modoFuncionamento == AUTOMATICO)
  {
    return 1;
  }
  else if (solicitante == USUARIO && modoFuncionamento == MANUAL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void ligaCoolerAmbiente(unsigned short int solicitante)
{
  char topic[5] = topicStatusCoolerPlanta;
  // sendTopic(topic, 1);

  if (verificarSolicitante(solicitante) == 1)
  {
    COOLER_AMBIENTE_TRIS = 0;
    COOLER_AMBIENTE = 0; // logica invertida
  }
}
void desligaCoolerAmbiente(unsigned short int solicitante)
{
  char topic[5] = topicStatusCoolerPlanta;
  // sendTopic(topic, 0);
  if (verificarSolicitante(solicitante) == 1)
  {
    COOLER_AMBIENTE_TRIS = 0;
    COOLER_AMBIENTE = 1; // logica invertida
  }
}

void ligaResistenciaAmbiente(unsigned short int solicitante)
{
  char topic[5] = topicResistencia;
  // sendTopic(topic, 1);

  if (verificarSolicitante(solicitante) == 1)
  {
    RESISTENCIA_TRIS_AMBIENTE = 0;
    RESISTENCIA_AMBIENTE = 0; // logica invertida
  }
}
void desligaResistenciaAmbiente(unsigned short int solicitante)
{
  char topic[5] = topicResistencia;
  // sendTopic(topic, 0);
  if (verificarSolicitante(solicitante) == 1)
  {
    RESISTENCIA_TRIS_AMBIENTE = 0;
    RESISTENCIA_AMBIENTE = 1; // logica invertida
  }
}
// FUN��ES DE AMBIENTE

void ligaCoolerAgua(unsigned short int solicitante)
{
  char topic[5] = topicStatusCoolerAgua;
  // sendTopic(topic, 1);
  if (verificarSolicitante(solicitante) == 1)
  {
    COOLER_AGUA_TRIS = 0;
    COOLER_AGUA = 0; // logica invertida
  }
}
void desligaCoolerAgua(unsigned short int solicitante)
{
  char topic[5] = topicStatusCoolerAgua;
  // sendTopic(topic, 0);
  if (verificarSolicitante(solicitante) == 1)
  {
    COOLER_AGUA_TRIS = 0;
    COOLER_AGUA = 1; // logica invertida
  }
}

void ligaLed()
{
  char topic[5] = topicStatusLeds;
  // sendTopic(topic, 1);
  //   stopTimer0();
  /*azul();
   vermelho();
   azul();
   vermelho();
   azul();*/
  /*T0CON = 0x87;*/
}

void desligaLed()
{
  char topic[5] = topicStatusLeds;
  // sendTopic(topic, 0);
  // stopTimer0();

  /*preto();
    preto();
    preto();
    preto();
    preto();*/

  /*T0CON = 0x87;*/
}