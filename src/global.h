// Variaveis principais
extern unsigned short int luminosidade;
extern unsigned short int luminosidadeMAX = 70;
extern unsigned short int luminosidadeMIN = 30;

extern float temperaturaAgua;
extern unsigned short int temperaturaAguaMAX = 26;
extern unsigned short int temperaturaAguaMIN = 22;

extern unsigned short int temperatura = 0;
extern unsigned short int temperaturaMAX = 26;
extern unsigned short int temperaturaMIN = 22;

extern unsigned short int umidade = 0;
extern unsigned short int umidadeMAX = 21;
extern unsigned short int umidadeMIN = 21;

extern unsigned short int nivelAgua = 0;
extern unsigned short int nivelAguaMAX = 0;
extern unsigned short int nivelAguaMIN = 0;

extern unsigned short int ph = 0;
extern unsigned short int phMAX = 10;
extern unsigned short int phMIN = 0;

extern unsigned short int tensaoBateria = 0;
extern unsigned short int tensaoBateriaMin = 0;

extern unsigned short int correnteLeds = 0;
extern unsigned short int correnteLedsMAX = 0;

extern unsigned short int vazaoAgua = 0;

extern unsigned short int correnteMotorAuxiliar = 0;
extern unsigned short int correnteMotorAuxiliarMAX = 0;

extern unsigned short int correnteMotorPrincipal = 0;
extern unsigned short int correnteMotorPrincipalMAX = 0;

extern unsigned short int correnteCooler = 0;
extern unsigned short int correnteCoolerMAX = 0;

extern unsigned short int correnteCoolerAgua = 0;
extern unsigned short int correnteCoolerAguaMAX = 0;
extern char teclaPressionada = 0;
extern unsigned short int erroMotor;
extern unsigned short int erroSensorCano;
extern unsigned short int SemAguaCano;
extern unsigned short int erroTemperatura;
extern unsigned short int interrupcaoTeclado;

#define flagLeituraTeclado interrupcaoTeclado.b0;
#define flagLeituraTecladoEmAndamento interrupcaoTeclado.b1;
#define flagTecladoPressionado interrupcaoTeclado.b2;

extern unsigned short int erroSensor;

extern bit erroTempAgua;
extern bit erroIluminacao;
extern bit erroComunicaoesp;
extern bit mensagemExibidaa;
extern bit atualizaMenu;

extern unsigned short int interrupcaoKBI;

extern unsigned short dutyCicle1, dutyCicle2;
extern char status_atuadores;

#define statusLeds 'LEDSW'
#define leds 'LEDAW'
#define correnteLeds 'LEDCW'
#define statusCoolerPlanta 'COPSW'
#define coolerPlanta 'COPAW'
#define correnteCoolerPlanta 'COPCW'
#define statusCoolerAgua 'COASW'
#define coolerAgua 'COAAW'
#define correnteCoollerAgua 'COACW'
#define statusResistencia 'RESSW'
#define resistencia 'RESAW'
#define correnteResistencia 'RESCW'
#define StatusMotor 'MTPSW'
#define MotorPrincipal 'MTPAW'
#define CorrenteMotor 'MTPCW'
#define StatusMotorAuxiliar 'MTASW'
#define MotorAuxiliar 'MTAAW'
#define CorrenteMotorAuxiliar 'MTACW'
#define luminosidadeMax 'LUMHW'
#define luminosidadeMin 'LUMLW'
#define luminosidade 'LUMRW'
#define temperaturaMax 'TMPHW'
#define temperaturaMin 'TMPLW'
#define temperaturaAmbiente 'TMPRW'
#define temperaturaAguaMax 'TPAHW'
#define temperaturaAguaMin 'TPALW'
#define temperaturaAgua 'TPARW'
#define umidadeMax 'UMIHW'
#define umidadeMin 'UMILW'
#define umidade 'UMIRW'
#define phMax 'SPHHW'
#define phMin 'SPHLW'
#define ph 'SPHRW'