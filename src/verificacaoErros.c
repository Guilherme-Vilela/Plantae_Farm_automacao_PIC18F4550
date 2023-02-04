#include "verificacaoErros.h"
#include "global.h"
#include "atuadores.h"
#include "ESP_I2C.h"

void verificarLeds()
{
  char topic[5] = topicLuminosidade;

  // envia luminosidade para o ESP publicar
  //sendTopic(topic, luminosidade);

  if (luminosidade >= luminosidadeMAX)
  {
    desligaLed();
  }
  else if (luminosidade <= luminosidadeMIN)
  {
    ligaLed();
  }
}
void verificarTemperaturaAgua()
{
  char topic[5] = topicTemperaturaAgua;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, temperaturaAgua);

  if (temperaturaAgua >= temperaturaAguaMAX)
  {
    ligaCoolerAgua();
  }
  else if (temperaturaAgua <= temperaturaAguaMIN)
  {
    desligaCoolerAgua();
  }
}
void verificarTemperatura()
{
  char topic[5] = topicTemperatura;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, temperatura);

  if (temperatura >= temperaturaMAX)
  {
    ligaCoolerAmbiente();
  }
  else if (temperatura <= temperaturaMIN)
  {
    desligaCoolerAmbiente();
  }
}
void verificarUmidade()
{
  char topic[5] = topicUmidade;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, umidade);

  if (umidade >= umidadeMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
  else if (umidade <= umidadeMIN)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarPh()
{
  char topic[5] = topicPh;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, ph);

  //       if(ph >= phMAX){
  // enviar mensagem de erro ou setar bit
  //       }else if (ph <= phMIN){
  // enviar mensagem de erro ou setar bit;
  //       }
}
void verificarTensaoBateria()
{
  char topic[5] = topicTensaoBateria;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, tensaoBateria);

  if (tensaoBateria <= tensaoBateriaMIN)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteLeds()
{
  char topic[5] = topicCorrenteLeds;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, correnteLeds);

  if (correnteLeds >= correnteLedsMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarNivelAgua()
{
  char topic[5] = topicNivelAgua;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, nivelAgua);
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
  char topic[5] = topicCorrenteMotorAuxiliar;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, correnteMotorAuxiliar);

  if (correnteMotorAuxiliar >= correnteMotorAuxiliarMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteMotorPrincipal()
{

  char topic[5] = topicCorrenteMotor;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, correnteMotorPrincipal);

  if (correnteMotorPrincipal >= correnteMotorPrincipalMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteCooler()
{
  char topic[5] = topicCorrenteCoolerPlanta;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, correnteCooler);
  if (correnteCooler >= correnteCoolerMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void verificarCorrenteCoolerAgua()
{
  char topic[5] = topicCorrenteCoolerAgua;
  // envia luminosidade para o ESP publicar
  sendTopic(topic, correnteCoolerAgua);
  if (correnteCoolerAgua >= correnteCoolerAguaMAX)
  {
    // enviar mensagem de erro ou setar bit
  }
}
void analisarSensores()
{
  verificarLeds();
  verificarTemperaturaAgua();
  verificarTemperatura();
  verificarUmidade();
  verificarPh();
  verificarTensaoBateria();
  verificarCorrenteLeds();
  verificarNivelAgua();
  verificarCorrenteMotorAuxiliar();
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
/*void verificarErros(){

//falhas motor
  if (erroMotor.b0 && mensagemExibida == 0){
  mensagemErro("Falha MOTOR-1");
  erroMotor.b0 = 0;
  }else if(erroMotor.b1 && mensagemExibida == 0){
   mensagemErro("Falha MOTOR-2");
   erroMotor.b1 = 0;
  }
   if(SemAguaCano.b0 && mensagemExibida == 0){
     mensagemErro("S/ AGUA BANCA 1");
     SemAguaCano.b0 = 0;

   }else if(SemAguaCano.b1 && mensagemExibida == 0){
     mensagemErro("S/ AGUA BANCA 2");
     SemAguaCano.b1 = 0;

   }else if(SemAguaCano.b2 && mensagemExibida == 0){
     mensagemErro("S/ AGUA BANCA 3");
     SemAguaCano.b2 = 0;

   }else if(SemAguaCano.b3 && mensagemExibida == 0){
     mensagemErro("S/ AGUA BANCA 4");
     SemAguaCano.b3 = 0;

   }else if(SemAguaCano.b4 && mensagemExibida == 0){
     mensagemErro("BANCA 1 TAMPADA");
     SemAguaCano.b4 = 0;

   }else if(SemAguaCano.b5 && mensagemExibida == 0){
     mensagemErro("BANCA 2 TAMPADA");
     SemAguaCano.b5 = 0;

   }else if(SemAguaCano.b6 && mensagemExibida == 0){
     mensagemErro("BANCA 3 TAMPADA");
     SemAguaCano.b6 = 0;

   } else if(SemAguaCano.b7 && mensagemExibida == 0){
     mensagemErro("BANCA 4 TAMPADA");
     SemAguaCano.b7 = 0;

   }
   if(erroSensorCano.b0 && mensagemExibida == 0){
     mensagemErro("2 BANCA S/ AGUA");
     erroSensorCano.b0 = 0;

   }else if(SemAguaCano.b7 && mensagemExibida == 0){
     mensagemErro("FALHA SENSOR CANO");
      SemAguaCano.b7 = 0;
   }

   if(erroTemperatura.b0 && mensagemExibida == 0){
    mensagemErro("TEMP AMB MIN <");
    erroTemperatura.b0 =0;

   }else if(erroTemperatura.b1 && mensagemExibida == 0) {
    mensagemErro("TEMP AMB MAX >");
    erroTemperatura.b1 =0;

   }else if(erroTemperatura.b2 && mensagemExibida == 0) {
    mensagemErro("TEMP AGUA MIN <");
    erroTemperatura.b2 =0;;

   }else if(erroTemperatura.b3 && mensagemExibida == 0) {
    mensagemErro("TEMP AGUA MAX >");
    erroTemperatura.b3 =0;
   }
   if(mensagemExibida == 0){
    atualizar = 1;
   }
}*/
void resetaMensagemErro()
{
  // LCD_Clear();
  // mensagemExibida = 0;
  // verificarErros();
}