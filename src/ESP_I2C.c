#include "ESP_I2C.h"
#include "conversao.h"
#include "global.h"
void sendTopic(char topic[5], int value)
{
  char msg[8];
  char convertion[3];
  char value_recebid[5];
  int x = 0;

    // convert int to char
    intToChar(value, &convertion);
    I2C1_Start();           // Inicia I2C
    I2C1_Wr(ADDRESS_ESP_W); // Envia o byte por I2C (endere�o do dispositivo + Write)
    I2C1_Wr(topic[0]); // comando para enviar dados para o ESP
    I2C1_Wr(topic[1]); // comando para enviar dados para o ESP
    I2C1_Wr(topic[2]); // comando para enviar dados para o ESP
    I2C1_Wr(topic[3]); // comando para enviar dados para o ESP
    I2C1_Wr(topic[4]); // comando para enviar dados para o ESP
    I2C1_Wr(convertion[0]); // comando para enviar dados para o ESP
    I2C1_Wr(convertion[1]); // comando para enviar dados para o ESP
    I2C1_Wr(convertion[2]); // comando para enviar dados para o ESP
    I2C1_Wr(0); // comando para enviar dados para o ESP
    I2C1_Stop();

}
void readTopic(char * topicRecebido,char * valorRecebido )
{
  I2C1_Start();           // inicia comunicao I2C
  I2C1_Wr(ADDRESS_ESP_R); // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  *topicRecebido =I2C1_Rd(1);
   topicRecebido++;
  *topicRecebido =I2C1_Rd(1);
  topicRecebido++;
  *topicRecebido =I2C1_Rd(1);
  topicRecebido++;
  *topicRecebido =I2C1_Rd(1);
  topicRecebido++;
  *topicRecebido =I2C1_Rd(1);
  *valorRecebido =I2C1_Rd(1);
  valorRecebido++;
  *valorRecebido =I2C1_Rd(1);
  valorRecebido++;
  *valorRecebido =I2C1_Rd(1);
  valorRecebido++;
  I2C1_Stop();
  *valorRecebido= '\0';
  
}