#define ADDRESS_ESP_W 0x10
#define ADDRESS_ESP_R 0X11

void readTopic(char *topicRecebido, char *valorRecebido);
void sendTopic(char topic[5], int value);
void verificarEspNotificacoes();
void enviarParametros();


//---------TOPICOS DE cultivo,  -------//
#define topicCultivo "PLATW"
#define topicCultivoUser "PLATR"

//---------TOPICOS DE ATUADORES, SOLICITADOS DO USUARIO (TOPICOS QUE LEMOS DO ESP) -------//

#define topicCoolerAguaUser "COASR"
#define topicCoolerPlantaUser "COPSR"
#define topicLedsUser "LEDSR"
#define topicMotorAuxiliarUser "MTASR"
#define topicMotorPrincipalUser "MTPSR"
#define topicResistenciaUser "RESSR"

//---------TOPICOS DE CONFIGURACAO, SOLICITADOS DO USUARIO (TOPICOS QUE LEMOS DO ESP) -------//
#define topicUmidadeMaxUser "UMIHR"
#define topicUmidadeMinUser "UMILR"
#define topicTemperaturaAguaMaxUser "TPAHR"
#define topicTemperaturaAguaMinUser "TPALR"
#define topicTemperaturaMaxUser "TMPHR"
#define topicTemperaturaMinUser "TMPLR"
#define topicLuminosidadeMaxUser "LUMHR"
#define topicLuminosidadeMinUser "LUMLR"
#define topicPhMaxUser "SPHHR"
#define topicPhMinUser "SPHLR"
#define topicNivelMax "NVLHR"
#define topicNivelMin "NVLLR"

//---------TOPICOS DE CONFIGURACAO DOS SENSORES -------//

#define topicUmidadeMax "UMIHW"
#define topicUmidadeMin "UMILW"

#define topicTemperaturaAguaMax "TPAHW"
#define topicTemperaturaAguaMin "TPALW"

#define topicTemperaturaMax "TMPHW"
#define topicTemperaturaMin "TMPLW"

#define topicLuminosidadeMax "LUMHW"
#define topicLuminosidadeMin "LUMLW"

#define topicPhMax "SPHHW"
#define topicPhMin "SPHLW"

//---------TOPICOS DE ESTADO DOS SENSORES -------//
#define topicPh "SPHRW"
#define topicTemperatura "TMPRW"
#define topicUmidade "UMIRW"
#define topicTensaoBateria "VBATW"
#define topicNivelAgua "NIVEW"
#define topicTemperaturaAgua "TPARW"
#define topicLuminosidade "LUMRW"

//---------TOPICOS DE ESTADO DOS ATUADORES -------//
#define topicEstadoCoolerAgua "COASW"
#define topicEstadoCoolerPlanta "COPSW"
#define topicEstadoLeds "LEDSW"
#define topicEstadoMotorAuxiliar "MTASW"
#define topicEstadoMotorPrincipal "MTPSW"
#define topicEstadoResistencia "RESSW"

//---------TOPICOS DE CORRENTE DOS ATUADORES -------//
#define topicCorrenteCoolerAgua "COACW"
#define topicCorrenteCoolerPlanta "COPCW"
#define topicCorrenteLeds "LEDCW"
#define topicCorrenteMotor "MTPCW"
#define topicCorrenteMotorAuxiliar "MTACW"
#define topicCorrenteResistencia "RESCW"