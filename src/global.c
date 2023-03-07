// Variaveis principais
unsigned short int luminosidade;
unsigned short int luminosidadeMAX = 70;
unsigned short int luminosidadeMIN = 30;

float temperaturaAgua = 0;
unsigned short int temperaturaAguaMAX = 25;
unsigned short int temperaturaAguaMIN = 21;

unsigned short int temperatura = 0;
unsigned short int temperaturaMAX = 27;
unsigned short int temperaturaMIN = 22;

unsigned short int umidade =0;
unsigned short int umidadeMAX = 50;
unsigned short int umidadeMIN = 95;

unsigned short int nivelAgua = 0;
unsigned short int nivelAguaMIN = 30;

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


unsigned short int interrupcaoTeclado = 0;

bit modoFuncionamento; //1 = automatico //0 para manual
 
unsigned short int interrupcaoKBI;
char status_atuadores;

unsigned short int dutyCicle1,dutyCicle2;
unsigned short int atualizar;
// unsigned short int erro;

