#include "ESP_I2C.h"
#include "conversao.h"
#include "global.h"
#include "atuadores.h"
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
  I2C1_Wr(topic[0]);      // comando para enviar dados para o ESP
  I2C1_Wr(topic[1]);      // comando para enviar dados para o ESP
  I2C1_Wr(topic[2]);      // comando para enviar dados para o ESP
  I2C1_Wr(topic[3]);      // comando para enviar dados para o ESP
  I2C1_Wr(topic[4]);      // comando para enviar dados para o ESP
  I2C1_Wr(convertion[0]); // comando para enviar dados para o ESP
  I2C1_Wr(convertion[1]); // comando para enviar dados para o ESP
  I2C1_Wr(convertion[2]); // comando para enviar dados para o ESP
  I2C1_Wr(0);             // comando para enviar dados para o ESP
  I2C1_Stop();
}
void readTopic(char *topicRecebido, char *valorRecebido)
{
  I2C1_Start();           // inicia comunicao I2C
  I2C1_Wr(ADDRESS_ESP_R); // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  *topicRecebido = I2C1_Rd(1);
  if (*topicRecebido != '0')
  { // verifica se o byte recebido � 0 se for para a comunica��o
    topicRecebido++;
    *topicRecebido = I2C1_Rd(1);
    topicRecebido++;
    *topicRecebido = I2C1_Rd(1);
    topicRecebido++;
    *topicRecebido = I2C1_Rd(1);
    topicRecebido++;
    *topicRecebido = I2C1_Rd(1);
    *valorRecebido = I2C1_Rd(1);
    valorRecebido++;
    *valorRecebido = I2C1_Rd(1);
    valorRecebido++;
    *valorRecebido = I2C1_Rd(1);
    valorRecebido++;
  }
  else
  {
    topicRecebido++;
    *topicRecebido = '\0';
  }
  I2C1_Rd(0);
  I2C1_Stop();
  topicRecebido++;
  *valorRecebido = '\0';
  *topicRecebido = '\0';
}
void verificarEspNotificacoes()
{
  unsigned short int valorInt;
  char topic[6], value[5];
  if (I2C1_Is_Idle)
  {
    readTopic(&topic[0], &value[0]);

    if (topic[0] != '0')
    {
      valorInt = ((value[0] - 48) * 100) + ((value[1] - 48) * 10) + ((value[2] - 48));
      switch (topic[3])
      {
        //------------- TOPICOS SOBRE ATUADORES ------------//

      case 'S':
        if (!strcmp(topic, topicCoolerAguaUser))
        {
          value[2] == '1' ? controleCoolerAgua(1, LIGAR) : controleCoolerAgua(1, DESLIGAR);
        }
        else if (!strcmp(topic, topicCoolerPlantaUser))
        {
          value[2] == '1' ? controleCoolerAmbiente(1, LIGAR) : controleCoolerAmbiente(1, DESLIGAR);
        }
        else if (!strcmp(topic, topicLedsUser))
        {
          value[2] == '1' ? controleLed(1, LIGAR) : controleLed(1, DESLIGAR);
        }
        else if (!strcmp(topic, topicMotorAuxiliarUser))
        {
        }
        else if (!strcmp(topic, topicMotorPrincipalUser))
        {
          dutyCicle1 = valorInt;
          setPWM1();
        }
        else if (!strcmp(topic, topicResistenciaUser))
        {
          value[2] == '1' ? controleResistenciaAmbiente(1, LIGAR) : controleResistenciaAmbiente(1, DESLIGAR);
        }
        break;
      case 'H':
        //------------- TOPICOS VARIAVEIS MAXIMAS DE CONTROLE ATUADORES ------------//

        if (strcmp(topic, topicUmidadeMaxUser) == 0)
        {
          umidadeMAX = valorInt;
        }
        else if (strcmp(topic, topicTemperaturaAguaMaxUser) == 0)
        {
          temperaturaAguaMAX = valorInt;
        }
        else if (strcmp(topic, topicTemperaturaMaxUser) == 0)
        {
          temperaturaMAX = valorInt;
        }
        else if (strcmp(topic, topicLuminosidadeMaxUser) == 0)
        {
          luminosidadeMAX = valorInt;
        }
        else if (strcmp(topic, topicPhMaxUser) == 0)
        {
          phMAX = valorInt;
        }
        else if (strcmp(topic, topicNivelMax) == 0)
        {
          // nivelAguaMAX = valorInt;
        }
        break;
      case 'L':
        //------------- TOPICOS VARIAVEIS MINIMAS DE CONTROLE ATUADORES ------------//
        if (strcmp(topic, topicUmidadeMinUser) == 0)
        {
          umidadeMIN = valorInt;
        }
        else if (strcmp(topic, topicTemperaturaAguaMinUser) == 0)
        {
          temperaturaAguaMIN = valorInt;
        }
        else if (strcmp(topic, topicTemperaturaMinUser) == 0)
        {
          temperatura = valorInt;
        }

        else if (strcmp(topic, topicLuminosidadeMinUser) == 0)
        {
          luminosidadeMIN = valorInt;
        }
        else if (strcmp(topic, topicPhMinUser) == 0)
        {
          phMIN = valorInt;
        }
        else if (strcmp(topic, topicNivelMin) == 0)
        {
          nivelAguaMIN = valorInt;
        }
        break;
      }
    }
  }
}
void enviarParametros(){
sendTopic(topicUmidadeMaxUser,umidadeMAX);
sendTopic(topicUmidadeMinUser,umidadeMIN);
sendTopic(topicTemperaturaAguaMaxUser,temperaturaAguaMAX);
sendTopic(topicTemperaturaAguaMinUser,temperaturaAguaMIN);
sendTopic(topicTemperaturaMaxUser,temperaturaMAX);
sendTopic(topicTemperaturaMinUser,temperaturaMIN);
sendTopic(topicLuminosidadeMaxUser,topicLuminosidadeMax);
sendTopic(topicLuminosidadeMinUser,luminosidadeMIN);
sendTopic(topicPhMaxUser,phMAX);
sendTopic(topicPhMinUser,phMIN);
sendTopic(topicNivelMin,nivelAguaMIN);
sendTopic(topicCultivo,cultivoSelecionado);
}