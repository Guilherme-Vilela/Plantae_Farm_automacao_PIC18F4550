// Variaveis principais
unsigned short int luminosidade;
unsigned short int luminosidadeMAX = 70;
unsigned short int luminosidadeMIN = 30;

float temperaturaAgua;
unsigned short int temperaturaAguaMAX = 26;
unsigned short int temperaturaAguaMIN = 22;

unsigned short int temperatura = 0;
unsigned short int temperaturaMAX = 26;
unsigned short int temperaturaMIN = 22;

unsigned short int umidade =0;
unsigned short int umidadeMAX = 21;
unsigned short int umidadeMIN = 21;

unsigned short int nivelAgua = 0;
unsigned short int nivelAguaMAX = 0;
unsigned short int nivelAguaMIN = 0;

unsigned short int ph = 0;
unsigned short int phMAX = 10;
unsigned short int phMIN = 0;

unsigned short int tensaoBateria = 0;
unsigned short int tensaoBateriaMin = 0;

unsigned short int correnteLeds =0;
unsigned short int correnteLedsMAX =0;

unsigned short int vazaoAgua =0;

unsigned short int correnteMotorAuxiliar =0;
unsigned short int correnteMotorAuxiliarMAX =0;

unsigned short int correnteMotorPrincipal=0;
unsigned short int correnteMotorPrincipalMAX=0;

unsigned short int correnteCooler =0;
unsigned short int correnteCoolerMAX =0;

unsigned short int correnteCoolerAgua =0;
unsigned short int correnteCoolerAguaMAX =0;


char teclaPressionada = 0;
unsigned short int erroMotor;
unsigned short int erroSensorCano;
unsigned short int SemAguaCano;
unsigned short int erroTemperatura;
unsigned short int interrupcaoTeclado;
unsigned short int erroSensor;

bit erroTempAgua;
bit erroIluminacao;
bit erroComunicaoesp;
bit mensagemExibidaa;
bit atualizaMenu;
 
unsigned short int interrupcaoKBI;

unsigned short dutyCicle1, dutyCicle2;
char status_atuadores;