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
void controleCoolerAmbiente(unsigned short int solicitante, unsigned short int acao)
{
  sendTopic(topicEstadoCoolerPlanta, acao);
  if (acao == LIGAR)
  {
    COOLER_AMBIENTE_TRIS = 0;
    COOLER_AMBIENTE = 0; // logica invertida
  }
  else
  {
    COOLER_AMBIENTE_TRIS = 0;
    COOLER_AMBIENTE = 1; // logica invertida
  }
}

void controleResistenciaAmbiente(unsigned short int solicitante, unsigned short int acao)
{
  sendTopic(topicEstadoResistencia, acao);
  if (acao == LIGAR)
  {
    RESISTENCIA_TRIS_AMBIENTE = 0;
    RESISTENCIA_AMBIENTE = 0; // logica invertida
  }
  else
  {
    RESISTENCIA_TRIS_AMBIENTE = 0;
    RESISTENCIA_AMBIENTE = 1; // logica invertida
  }
}

// FUN��ES DE AMBIENTE

void controleCoolerAgua(unsigned short int solicitante, unsigned short int acao)
{
  sendTopic(topicEstadoCoolerAgua, acao);
  if (acao == LIGAR)
  {
    COOLER_AGUA_TRIS = 0;
    COOLER_AGUA = 0; // logica invertida
  }
  else
  {
    COOLER_AGUA_TRIS = 0;
    COOLER_AGUA = 1; // logica invertida
  }
}

void controleLed(unsigned short int solicitante, unsigned short int acao)
{
  sendTopic(topicEstadoLeds, acao);
  //   stopTimer0();
  /*azul();
   vermelho();
   azul();
   vermelho();
   azul();*/
  /*T0CON = 0x87;*/
}

void aceleraPWM1(short valor){
    dutyCicle1 += valor;
    PWM1_Set_Duty(dutyCicle1);        // Atualiza Duty cicle PWM1
}
void aceleraPWM2(short valor){
    dutyCicle2 += valor;
    PWM2_Set_Duty(dutyCicle2);        // Atualiza Duty cicle PWM2
}
void desaceleraPWM1(short valor){
    dutyCicle1 -= valor;
    PWM1_Set_Duty(dutyCicle1);        // Atualiza Duty cicle PWM2
}
void desaceleraPWM2(short valor){
    dutyCicle2 -= valor;
    PWM2_Set_Duty(dutyCicle2);        // Atualiza Duty cicle PWM2
}
void setPWM1()
{
  PWM1_Set_Duty(dutyCicle1);
  sendTopic(topicEstadoMotorPrincipal, dutyCicle1);
}

void controlePWM1(unsigned short int solicitante, unsigned short int acao)
{
  if(acao == LIGAR){
  PWM1_Init(15000);          // Configura o PWM para 10Khz
  dutyCicle1 = 150;            // Duty cicle a ser utilizado 0 - 255
  PWM1_Start();              // inicia PWM1   CCP1
  PWM1_Set_Duty(dutyCicle1); // Atualiza Duty cicle PWM1
  sendTopic(topicEstadoMotorPrincipal, dutyCicle1);
  }else{
   dutyCicle1 = 0;
   PWM1_Set_Duty(dutyCicle1);
   PWM1_Stop();
  }
}
void controlePWM2(unsigned short int solicitante, unsigned short int acao)
{
  if(acao == LIGAR){
  PWM2_Init(10000);          // Configura o PWM para 10Khz
  PWM2_Start();              // start PWM2    CCP1
  dutyCicle2 = 255;            // Duty cicle a ser utilizado 0 - 255
  PWM2_Set_Duty(dutyCicle2); // Atualiza Duty cicle PWM2
  }else{
   dutyCicle2 = 0;
   PWM2_Set_Duty(dutyCicle2);
   PWM2_Stop();
  }
  sendTopic(topicEstadoMotorAuxiliar, dutyCicle2);
}