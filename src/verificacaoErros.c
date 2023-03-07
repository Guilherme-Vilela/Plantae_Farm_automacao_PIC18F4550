#include "verificacaoErros.h"
#include "global.h"
#include "atuadores.h"
#include "ESP_I2C.h"
#include "LCD_I2C.h"
unsigned short int erros[5];
void verificarLeds()
{
  //char topic[5] = topicLuminosidade;
   sendTopic(topicLuminosidade, luminosidade);
  // envia luminosidade para o ESP publicar
  ////sendTopic(topic, luminosidade);

  if (luminosidade >= luminosidadeMAX)
  {
    // controleLed(0);
  }
  else if (luminosidade <= luminosidadeMIN)
  {
    // controleLed(0);
  }
}
void verificarTemperaturaAgua()
{
  unsigned short int temperaturaIdeal = 0;
  sendTopic(topicTemperaturaAgua, temperaturaAgua);
  if (temperaturaAgua != 99)
  {
    temperaturaIdeal = (temperaturaAguaMAX + temperaturaAguaMIN) / 2;
    if (temperaturaAgua > temperaturaIdeal)
    {
      controleCoolerAgua(0,LIGAR);
    }
    else if (temperaturaAgua == temperaturaIdeal)
    {
      // controleResistencia();
      controleCoolerAgua(0,DESLIGAR);
    }
    else if (temperaturaAgua < temperaturaIdeal)
    {
      // controleResistencia();
      controleCoolerAgua(0,DESLIGAR);
    }
  }
}
void verificarTemperatura()
{
  // envia luminosidade para o ESP publicar
  unsigned short int temperaturaIdeal = 0;
  
  sendTopic(topicTemperatura, temperatura);
  if (temperatura != 99)
  {
    temperaturaIdeal = (temperaturaMAX + temperaturaMIN) / 2;
    if (temperatura > temperaturaIdeal)
    {
      controleCoolerAmbiente(0,LIGAR);
    }
    else if (temperatura == temperaturaIdeal)
    {
      controleCoolerAmbiente(0,DESLIGAR);
    }
    else if (temperatura < temperaturaIdeal)
    {
      controleCoolerAmbiente(0,DESLIGAR);
    }
  }
}
void verificarUmidade()
{
  // envia luminosidade para o ESP publicar
  sendTopic(topicUmidade, umidade);
  // unsigned short int umidadeIdeal = 0;
  // umidadeIdeal = (umidadeMAX+umidadeMIN)/2;
  // if (umidade >= umidadeIdeal)
  // {
  //   // enviar mensagem de erro ou setar bit
  // }
  // else if (umidade == umidadeIdeal)
  // {
  //   // enviar mensagem de erro ou setar bit
  // }
  // else if (umidade <= umidadeIdeal)
  // {
  //   // enviar mensagem de erro ou setar bit
  // }
}
void verificarPh()
{

  // envia luminosidade para o ESP publicar
  sendTopic(topicPh, ph);

  //       if(ph >= phMAX){
  // enviar mensagem de erro ou setar bit
  //       }else if (ph <= phMIN){
  // enviar mensagem de erro ou setar bit;
  //       }
}
void verificarTensaoBateria()
{
  // envia luminosidade para o ESP publicar
  sendTopic(topicTensaoBateria, tensaoBateria);

  if (tensaoBateria <= tensaoBateriaMIN)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteLeds()
{
  // envia luminosidade para o ESP publicar
  sendTopic(topicCorrenteLeds, correnteLeds);

  if (correnteLeds >= correnteLedsMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarNivelAgua()
{
  // envia luminosidade para o ESP publicar
  sendTopic(topicNivelAgua, nivelAgua);
  if (nivelAgua <= nivelAguaMIN)
  {
    // enviar mensagem de erro ou setar bit
  }
}

void verificarVazaoAgua()
{
}
void verificarCorrenteMotorAuxiliar()
{
  // envia luminosidade para o ESP publicar
  sendTopic(topicCorrenteMotorAuxiliar, correnteMotorAuxiliar);

  if (correnteMotorAuxiliar >= correnteMotorAuxiliarMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteMotorPrincipal()
{

  // envia luminosidade para o ESP publicar
  sendTopic(topicCorrenteMotor, correnteMotorPrincipal);

  if (correnteMotorPrincipal >= correnteMotorPrincipalMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteCooler()
{
// envia luminosidade para o ESP publicar
  sendTopic(topicCorrenteCoolerPlanta, correnteCooler);
  if (correnteCooler >= correnteCoolerMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteCoolerAgua()
{
  // envia luminosidade para o ESP publicar
  sendTopic(topicCorrenteCoolerAgua, correnteCoolerAgua);
  if (correnteCoolerAgua >= correnteCoolerAguaMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void analisarVariaveis()
{
  verificarLeds();
  verificarTemperaturaAgua();
  verificarTemperatura();
  // verificarUmidade();
  // verificarPh();
  // verificarTensaoBateria();
  // verificarCorrenteLeds();
  // verificarNivelAgua();
  // verificarCorrenteMotorAuxiliar();
  verificarCorrenteMotorPrincipal();
  verificarCorrenteCooler();
  verificarCorrenteCoolerAgua();
}

// void mensagemErro(char* mesagem){

/*LCD_Clear();
LCD_Out(1,1,"ERRO");
LCD_Out(2,1,mesagem);
//mensagemExibida = 1;

}*/
void verificarErros()
{
}
void adicionarErro(unsigned short int erroOcorrido)
{
  unsigned short int i;
  while (i < 5 && erros[i] != 0)
  {
    i++;
  }
  if (i != 5)
  {
    erros[i] = erroOcorrido;
  }
}
void mostrarErrosLcd()
{
  unsigned short int i;
  while (i < 5 && erros[i] == 0)
  {
    i++;
  }
  if (i != 5)
  {
    switch (erros[i])
    {
    case ERRO_MOTOR_PRINCIPAL:
      LCD_Out(1, 1, "ERRO_MOTOR_PRINCIPAL");
      break;
    case ERRO_MOTOR_AUXILIAR:
      LCD_Out(1, 1, "ERRO_MOTOR_AUXILIAR");
      break;
    case ERRO_TEMPERATURA_AMBIENTE_MAX:
      LCD_Out(1, 1, "ERRO_TEMPERATURA_AMBIENTE_MAX");
      break;
    case ERRO_TEMPERATURA_AMBIENTE_MIN:
      LCD_Out(1, 1, "ERRO_TEMPERATURA_AMBIENTE_MIN");
      break;
    case ERRO_TEMPERATURA_AGUA_MAX:
      LCD_Out(1, 1, "ERRO_TEMPERATURA_AGUA_MAX");
      break;
    case ERRO_TEMPERATURA_AGUA_MIN:
      LCD_Out(1, 1, "ERRO_TEMPERATURA_AGUA_MIN");
      break;
    case ERRO_LUMINOSIDADE_MAX:
      LCD_Out(1, 1, "ERRO_LUMINOSIDADE_MAX");
      break;
    case ERRO_LUMINOSIDADE_MIN:
      LCD_Out(1, 1, "ERRO_LUMINOSIDADE_MIN");
      break;
    case ERRO_UMIDADE_MAX:
      LCD_Out(1, 1, "ERRO_UMIDADE_MAX");
      break;
    case ERRO_UMIDADE_MIN:
      LCD_Out(1, 1, "ERRO_UMIDADE_MIN");
      break;
    case ERRO_PH_MAX:
      LCD_Out(1, 1, "ERRO_PH_MAX");
      break;
    case ERRO_PH_MIN:
      LCD_Out(1, 1, "ERRO_PH_MIN");
      break;
    case ERRO_COOLER_AMBIENTE:
      LCD_Out(1, 1, "ERRO_COOLER_AMBIENTE");
      break;
    case ERRO_COOLER_AGUA:
      LCD_Out(1, 1, "ERRO_COOLER_AGUA");
      break;
    case ERRO_RESISTENCIA:
      LCD_Out(1, 1, "ERRO_RESISTENCIA");
      break;
    case ERRO_LEDS:
      LCD_Out(1, 1, "ERRO_LEDS");
      break;
    case ERRO_COMUNICACAO_DHT11:
      LCD_Out(1, 1, "ERRO_COMUNICACAO_DHT11");
      break;
    case ERRO_COMUNICACAO_DS18B20:
      LCD_Out(1, 1, "ERRO_COMUNICACAO_DS18B20");
      break;
    case ERRO_LDR:
      LCD_Out(1, 1, "ERRO_LDR");
      break;
    }
    erros[i] = 0;
    LCD_Chr(2, 16, "A");
  }
}
void resetaMensagemErro()
{
  // LCD_Clear();
  // mensagemExibida = 0;
  verificarErros();
}