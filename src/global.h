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

extern unsigned short int cultivoSelecionado;

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

#define E2PROM_ADDRESS_MODO_OPERACAO 0
#define E2PROM_ADDRESS_TEMPERATURA_MAX 1
#define E2PROM_ADDRESS_TEMPERATURA_MIN 2
#define E2PROM_ADDRESS_LUMINOSIDADE_MAX 3
#define E2PROM_ADDRESS_LUMINOSIDADE_MIN 4
#define E2PROM_ADDRESS_TEMPERATURA_AGUA_MAX 5
#define E2PROM_ADDRESS_TEMPERATUR_AAGUA_MIN 6
#define E2PROM_ADDRESS_UMIDADE_MAX 7  
#define E2PROM_ADDRESS_UMIDADE_MIN 8
#define E2PROM_ADDRESS_NIVEL_AGUA_MAX 9
#define E2PROM_ADDRESS_NIVEL_AGUA_MIN 10
#define E2PROM_ADDRESS_PH_MAX 11
#define E2PROM_ADDRESS_PH_MIN 12
#define E2PROM_ADDRESS_CULTIVO 13