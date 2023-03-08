// Variaveis principais
extern unsigned short int luminosidade;
extern unsigned short int luminosidadeMAX;
extern unsigned short int luminosidadeMIN;

extern float temperaturaAgua;
extern unsigned short int temperaturaAguaMAX;
extern unsigned short int temperaturaAguaMIN;

extern unsigned short int temperatura;
extern unsigned short int temperaturaMAX;
extern unsigned short int temperaturaMIN;

extern unsigned short int umidade;
extern unsigned short int umidadeMAX;
extern unsigned short int umidadeMIN;

extern unsigned short int nivelAgua;
extern unsigned short int nivelAguaMAX;
extern unsigned short int nivelAguaMIN;

extern unsigned short int ph;
extern unsigned short int phMAX;
extern unsigned short int phMIN;

extern unsigned short int tensaoBateria;
extern unsigned short int tensaoBateriaMin;

extern unsigned short int vazaoAgua;

extern unsigned short int correnteLeds;
extern unsigned short int correnteLedsMAX;

extern unsigned short int correnteMotorAuxiliar;
extern unsigned short int correnteMotorAuxiliarMAX;

extern unsigned short int correnteMotorPrincipal;
extern unsigned short int correnteMotorPrincipalMAX;

extern unsigned short int correnteCooler;
extern unsigned short int correnteCoolerMAX;
extern unsigned short int correnteCoolerAgua;
extern unsigned short int correnteCoolerAguaMAX;

extern unsigned short int interrupcaoTeclado;

#define flagLeituraTeclado interrupcaoTeclado.b0
#define flagLeituraTecladoEmAndamento interrupcaoTeclado.b1
#define flagEstadoTeclado interrupcaoTeclado.b2

extern bit modoFuncionamento;
#define AUTOMATICO 1
#define MANUAL 0
#define LIGAR 1
#define DESLIGAR 0

extern unsigned short int interrupcaoKBI;
#define falhaRedeEnergia interrupcaoKBI.b0
#define leituraEspDisponivel interrupcaoKBI.b1

extern unsigned short int dutyCicle1, dutyCicle2;

extern char Estado_atuadores;

extern unsigned short int atualizar = 0;
#define atualizaMenuEntrar 65
#define atualizaMenuSair 66
#define atualizaMenuAvancar 67
#define atualizaMenuVoltar 68
#define atualizaLCD 1
#define atualizarPWM1 99
#define atualizarPWM2 100

// extern unsigned short int erro;
#define ERRO_MOTOR_PRINCIPAL 1
#define ERRO_MOTOR_AUXILIAR 2
#define ERRO_TEMPERATURA_AMBIENTE_MAX 3
#define ERRO_TEMPERATURA_AMBIENTE_MIN 4
#define ERRO_TEMPERATURA_AGUA_MAX 5
#define ERRO_TEMPERATURA_AGUA_MIN 6
#define ERRO_LUMINOSIDADE_MAX 7
#define ERRO_LUMINOSIDADE_MIN 8
#define ERRO_UMIDADE_MAX 9
#define ERRO_UMIDADE_MIN 10
#define ERRO_PH_MAX 11
#define ERRO_PH_MIN 12
#define ERRO_COOLER_AMBIENTE 13
#define ERRO_COOLER_AGUA 14
#define ERRO_RESISTENCIA 15
#define ERRO_LEDS 16
#define ERRO_COMUNICACAO_DHT11 17
#define ERRO_COMUNICACAO_DS18B20 18
#define ERRO_LDR 19

//---------TOPICOS DE ATUADORES, SOLICITADOS DO USUARIO (TOPICOS QUE LEMOS DO ESP) -------//

#define topicCoolerAguaUser     "COASR"
#define topicCoolerPlantaUser   "COPSR"
#define topicLedsUser           "LEDSR"
#define topicMotorAuxiliarUser  "MTASR"
#define topicMotorPrincipalUser "MTPSR"
#define topicResistenciaUser    "RESSR"

//---------TOPICOS DE CONFIGURACAO, SOLICITADOS DO USUARIO (TOPICOS QUE LEMOS DO ESP) -------//
#define topicUmidadeMaxUser "UMIHR"
#define topicUmidadeMinUser "UMILR"
#define topicTemperaturaAguaMaxUser "TPAHR"
#define topicTemperaturaAguaMinUser "TPALR"
#define topicTemperaturaMaxUser "TMPHR"
#define topicTemperaturaMiUsern "TMPLR"
#define topicLuminosidadeMaxUser "LUMHR"
#define topicLuminosidadeMinUser "LUMLR"
#define topicPhMaxUser "SPHHR"
#define topicPhMinUser "SPHLR"

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