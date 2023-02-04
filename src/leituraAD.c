#include "global.h"
#include "leituraAD.h"

void leituraTensaoBateria(int *value){
     *value =  ADC_Read(PIN_TENSAO_BATERIA);
}
void leituraCorrenteLeds(int *value){
     *value =  ADC_Read(PIN_CORRENTE_LEDS)-512;      //MENOS 512 POR CAUSA DA RESOLUCAO DO SENSOR QUE VAI DE -5A ATE 5A LOGO 2,5V = 0A
}
void leituraNivelAgua(int *value){
     *value =  ADC_Read(PIN_SENSOR_NIVEL);
}
void leituraVazaoAgua(int *value){
     *value =  ADC_Read(PIN_SENSOR_AGUA);
}
void leituraCorrenteMotorAuxiliar(int *value){
     *value =  ADC_Read(PIN_CORRENTE_MOTOR_AUXILIAR)-512;   //MENOS 512 POR CAUSA DA RESOLUCAO DO SENSOR QUE VAI DE -5A ATE 5A LOGO 2,5V = 0A
}
void leituraCorrenteMotorPrincipal(int *value){
     *value =  ADC_Read(PIN_CORRENTE_MOTOR_PRINCIPAL)-512;  //MENOS 512 POR CAUSA DA RESOLUCAO DO SENSOR QUE VAI DE -5A ATE 5A LOGO 2,5V = 0A
}
void leituraPh(int *value){
     *value =  ADC_Read(PIN_SENSOR_PH)/ 10;
}
void leituraLdr(int *value){
     *value =  ADC_Read(PIN_LDR)/ 10;                       //DIVIDIDO POR 10 PARA FICAR NA GRANDEZA DE 1 A 999
}
void leituraCorrenteCooler(int *value){
     *value =  ADC_Read(PIN_CORRENTE_COOLER)-512;        //MENOS 512 POR CAUSA DA RESOLUCAO DO SENSOR QUE VAI DE -5A ATE 5A LOGO 2,5V = 0A
}
void leituraCorrenteCoolerAgua(int *value){
     *value =  ADC_Read(PIN_CORRENTE_COOLER_AGUA)-512;  //MENOS 512 POR CAUSA DA RESOLUCAO DO SENSOR QUE VAI DE -5A ATE 5A LOGO 2,5V = 0A
}

void leituraPortasAnalogicas(){
  leituraTensaoBateria(&tensaoBateria);
  leituraCorrenteLeds(&correnteLeds);
  leituraNivelAgua(&nivelAgua);
  leituraVazaoAgua(&vazaoAgua);
  leituraCorrenteMotorAuxiliar(&correnteMotorAuxiliar);
  leituraCorrenteMotorPrincipal(&correnteMotorPrincipal);
  leituraPh(&ph);
  leituraLdr(&luminosidade);
  leituraCorrenteCooler(&correnteCooler);
  leituraCorrenteCoolerAgua(&correnteCoolerAgua);
}