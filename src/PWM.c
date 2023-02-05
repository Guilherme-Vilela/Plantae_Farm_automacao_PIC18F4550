#include "PWM.h"
#include "global.h"
#include "ESP_I2C.H"
void setPWM1(){
PWM1_Set_Duty(dutyCicle1);
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
void desligarPWM1(){
 char topic[5] = topicStatusMotor;

  /*while(dutyCicle1 > 0){
    desaceleraPWM1(1);
  }
  PWM1_Stop();*/                     // Desliga PWM1
  MOTOR_1_TRIS = 0;
  MOTOR_1 =0;
  //sendTopic(topic, dutyCicle1);

}
void desligarPWM2(){
char topic[5] = topicStatusMotorAuxiliar;
  /*while(dutyCicle2 > 0){
    desaceleraPWM2(1);
  }
  PWM2_Stop();*/                     // Desliga PWM2
  MOTOR_2_TRIS = 0;
  MOTOR_2 =0;
  //sendTopic(topic, dutyCicle2);
}
void iniciarPWM() {
char topic[5] = topicStatusMotor;
//  desligarPWM2();                    // Desliga PWM2
  PWM1_Init(10000);                 // Configura o PWM para 2Khz
  dutyCicle1 = 0;                 // Duty cicle a ser utilizado 0 - 255
  PWM1_Start();                   // inicia PWM1   CCP1
  PWM1_Set_Duty(dutyCicle1);        // Atualiza Duty cicle PWM1
  while(dutyCicle1 < 255){
    aceleraPWM1(1);
  }

  /*MOTOR_1_TRIS = 0;
  MOTOR_1 =1;*/
  ////sendTopic(topic, dutyCicle1);
}
void iniciarPWM2(){
char topic[5] = topicStatusMotorAuxiliar;

  desligarPWM1();
  /*PWM2_Init(2000);                // Configura o PWM para 2Khz
  PWM2_Start();                   // start PWM2    CCP1
  dutyCicle2 = 0;                 // Duty cicle a ser utilizado 0 - 255
  PWM2_Set_Duty(dutyCicle2);      // Atualiza Duty cicle PWM2
  while(dutyCicle2 < 255){
    aceleraPWM2(1);
  }*/
  MOTOR_2_TRIS = 0;
  MOTOR_2 =1;
    //sendTopic(topic, dutyCicle2);
}