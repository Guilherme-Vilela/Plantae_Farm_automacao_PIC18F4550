#include "DS18B20.h"
#include "timer.h"
void leituraDs18b20(float *temperaturaAgua){
 unsigned int temp_;
 float tempo__;
 char t1_,t2_,td__;
 float sensor_temp_;
 short int i = 0;
 startTimer1();
 while(i == 0 && timer1 <= 3){
    Ow_Reset(DS128B20_PORT, DS128B20_PIN);                         //
    Delay_ms(1);
    Ow_Write(DS128B20_PORT, DS128B20_PIN, 0xCC);                   //DIRECIONA SENSORES
    Delay_ms(1);
    Ow_Write(DS128B20_PORT, DS128B20_PIN, 0x44);                   //NIICIA CONVERSÃO
    Delay_ms(30);

    Ow_Reset(DS128B20_PORT, DS128B20_PIN);
        Delay_ms(1);
    Ow_Write(DS128B20_PORT, DS128B20_PIN, 0xCC);                   // COMANDO SKIP_ROM
        Delay_ms(1);
    Ow_Write(DS128B20_PORT, DS128B20_PIN, 0xBE);                   // COMANDO READ_SCRATCHPAD
    Delay_ms(30);

    t1_ =  Ow_Read(DS128B20_PORT, DS128B20_PIN);        //PEGA PARTE BAIXA
    Delay_ms(1);
    t2_ =  Ow_Read(DS128B20_PORT, DS128B20_PIN);       //PEGA PARTE ALTA
    Delay_ms(30);

    td__=t1_ & 0xf;    //PEGA PARTE DECIMAL
    //ANALIZA PARTE DECIMAL
    tempo__=1;
    if (td__.b3==1) tempo__=tempo__*2;
    if (td__.b2==1) tempo__=tempo__*4;
    if (td__.b1==1) tempo__=tempo__*8;
    if (td__.b0==1) tempo__=tempo__*16;

    t1_=t1_>>4;   //PEGA PARTE BAIXA
    t2_=t2_ & 7;
    t2_=t2_<<4;    //PEGA PARTE ALTA
    temp_=(t2_ |t1_);

    if (tempo__!=1)  {
    sensor_temp_=temp_+ (2.0/tempo__);
    }  //SIM TEM PARTE DECIMAL
    else {
    sensor_temp_=temp_;
    } //SEM PARTE DECIMAL
    *temperaturaAgua = temp_;

    if(*temperaturaAgua > 10 && *temperaturaAgua < 40){
    i++;
    }else{
      delay_us(100);
    }
   }
   stopTimer1();
   if(timer1 >= 3){
    *temperaturaAgua = 99;
   }
}