#include "DHT11.h"
#include "LCD_I2C.h"
#include "global.h"
#include "timer.h"
unsigned short int leituraByteDht11(){
  unsigned short int i = 8, dht11_byte = 0;
  //O padrao do DHT11 É 50us entre bits
  //BIT 1 é linha  de dados em vcc por 70us
  //BIT 0 é a linha de dados em GND por 25us
  // 50us baixo 70us ou 25us alto depois 50us baixo ...
  
  //Start TIMER 1
  startTimer1();
  
  while(i-- && timer1 <= 1 ){
    while(!DHT11_PIN && timer1 <= 1);
    delay_us(40);

    if( DHT11_PIN && timer1 <= 1){
      dht11_byte |= (1 << i);  // << desloca bits para esquerda
      while( DHT11_PIN && timer1 <= 1);
    }
  }
  T1CON = 0x30;
  return(dht11_byte);
}

void leituraDht11(unsigned short int *dht11_humi, unsigned short int *dht11_temp){
  char teste[15];
  // INICIANDO COMUNICAÇÃO
  DHT11_PIN_DIR = 0;   // CONFIGURA SAIDA
  DHT11_PIN     = 0;   // LINHA DE DADOS PARA LOW
  delay_ms(25);        // DELAY 25 ms
  DHT11_PIN     = 1;   // SOLTA A LINHA DE DADOS
  delay_us(30);        // DELAY 30 us
  DHT11_PIN_DIR = 1;   // CONFIGURA COMO ENTRADA
  //Start TIMER 1
  startTimer1();
  // Inicialização do DHT
  while( DHT11_PIN  && timer1 <= 1);  //AGUARDA INCIALIZAÇÃO DO DHT
  while( !DHT11_PIN && timer1 <= 1);
  while( DHT11_PIN && timer1 <= 1);
  //Stop TIMER 1
  stopTimer1();
  // Leitura das infomrações
  if(timer1 == 0){
  *dht11_humi = leituraByteDht11();  // LEITURA DO PRIMEIRO BYTE DE UMIDADE 1
  leituraByteDht11();               // LEITURA DO SEGUNDO BYTE TEMPERATURA
  *dht11_temp = leituraByteDht11();  // LEITURA DO PRIMEIRO BYTE DE TEMPERATURA 1
  leituraByteDht11();               // LEITURA DO SEGUNDO BYTE TEMPERATURA
  leituraByteDht11();               // LEITURA DO DADO DE VERIFIÇÃO
  }else{
  *dht11_humi= 0;
  *dht11_temp= 99;
  }
}