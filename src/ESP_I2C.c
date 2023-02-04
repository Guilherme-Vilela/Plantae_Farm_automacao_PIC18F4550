#include "ESP_I2C.h"
#include "conversao.h"
#include "global.h"
void sendTopic(char topic[5], int value)
{
  char msg[8];
  char convertion[3];
  int x = 0;
  if(erroI2c == 0){
    // convert int to char
    intToChar(value, &convertion);

    for (x = 0; x < 8; x++)
    {
      if (x <= 4)
      {
        msg[x] = topic[x];
      }
      else if (x > 4)
      {
        msg[x] = convertion[x - 5];
      }
    }
    while (I2C1_Is_Idle() != 1)
    {
    }
    I2C1_Start();           // Inicia I2C
    I2C1_Wr(ADDRESS_ESP_W); // Envia o byte por I2C (endere�o do dispositivo + Write)
    for (x = 0; x < 8; x++)
    {
      I2C1_Wr(msg[x]); // comando para enviar dados para o ESP
    }
    I2C1_Stop();
  }
}
void readTopic()
{
  char msg[8];
  int x = 0;

  while (I2C1_Is_Idle() == 0)
  {
  };                      // VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Start();           // inicia comunicao I2C
  I2C1_Wr(ADDRESS_ESP_R); // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  for (x = 0; x < 8; x++)
  {
    if (x < 7)
    {
      msg[x] = I2C1_Rd(1);
    }
    else
    {
      msg[x] = I2C1_Rd(0);
    }
  }
  I2C1_Stop();
}