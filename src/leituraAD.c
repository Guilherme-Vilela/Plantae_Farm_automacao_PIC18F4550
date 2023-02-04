#include "global.h"
#include "leituraAD.h"
 void leituraAnalogica(unsigned short int *value,unsigned short int canal,unsigned short int compensador ){
      *value = ADC_Read(canal);
      if(*value < compensador){
         *value =0 ;
      }else{
      *value= *value-compensador;
      }
      delay_us(500);
 }

void leituraPortasAnalogicas()
{
     leituraAnalogica(&tensaoBateria,PIN_TENSAO_BATERIA,0);
     leituraAnalogica(&correnteLeds,PIN_CORRENTE_LEDS,512);
     leituraAnalogica(&nivelAgua,PIN_SENSOR_NIVEL,0);
     leituraAnalogica(&vazaoAgua,PIN_SENSOR_AGUA,0);
     leituraAnalogica(&correnteMotorAuxiliar,PIN_CORRENTE_MOTOR_AUXILIAR,512);
     leituraAnalogica(&correnteMotorPrincipal,PIN_CORRENTE_MOTOR_PRINCIPAL,512);
     leituraAnalogica(&ph,PIN_SENSOR_PH,0);
     leituraAnalogica(&luminosidade,PIN_LDR,0);
     leituraAnalogica(&correnteCooler,PIN_CORRENTE_COOLER,512);
     leituraAnalogica(&correnteCoolerAgua,PIN_CORRENTE_COOLER_AGUA,512);
}