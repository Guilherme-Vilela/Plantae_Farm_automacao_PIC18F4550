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

extern unsigned short int erroMotor;

extern unsigned short int SemAguaCano;
extern unsigned short int erroTemperatura;
extern unsigned short int interrupcaoTeclado;

#define flagLeituraTeclado interrupcaoTeclado.b0
#define flagLeituraTecladoEmAndamento interrupcaoTeclado.b1
#define flagStatusTeclado interrupcaoTeclado.b2

extern unsigned short int erroSensor;

extern bit erroTempAgua;
extern bit erroIluminacao;
extern bit erroComunicaoesp;
extern bit mensagemExibidaa;

extern bit erroI2C;
extern bit modoFuncionamento; 
#define AUTOMATICO 1
#define MANUAL 0
extern unsigned short int interrupcaoKBI;
#define falhaRedeEnergia interrupcaoKBI.b0
#define leituraEspDisponivel interrupcaoKBI.b1

extern unsigned short int dutyCicle1, dutyCicle2;

extern char status_atuadores;

#define topicCoolerAgua         \
    {                           \
        'C', 'O', 'A', 'A', 'W' \
    }
#define topicCorrenteCoolerAgua \
    {                           \
        'C', 'O', 'A', 'C', 'W' \
    }
#define topicStatusCoolerAgua   \
    {                           \
        'C', 'O', 'A', 'S', 'W' \
    }
#define topicCoolerPlanta       \
    {                           \
        'C', 'O', 'P', 'A', 'W' \
    }
#define topicCorrenteCoolerPlanta \
    {                             \
        'C', 'O', 'P', 'C', 'W'   \
    }
#define topicStatusCoolerPlanta \
    {                           \
        'C', 'O', 'P', 'S', 'W' \
    }
#define topicLeds               \
    {                           \
        'L', 'E', 'D', 'A', 'W' \
    }
#define topicCorrenteLeds       \
    {                           \
        'L', 'E', 'D', 'C', 'W' \
    }
#define topicStatusLeds         \
    {                           \
        'L', 'E', 'D', 'S', 'W' \
    }
#define topicLuminosidadeMax    \
    {                           \
        'L', 'U', 'M', 'H', 'W' \
    }
#define topicLuminosidadeMin    \
    {                           \
        'L', 'U', 'M', 'L', 'W' \
    }
#define topicLuminosidade       \
    {                           \
        'L', 'U', 'M', 'R', 'W' \
    }
#define topicMotorAuxiliar      \
    {                           \
        'M', 'T', 'A', 'A', 'W' \
    }
#define topicNivelAgua          \
    {                           \
        'N', 'I', 'V', 'E', 'W' \
    }
#define topicCorrenteMotorAuxiliar \
    {                              \
        'M', 'T', 'A', 'C', 'W'    \
    }
#define topicStatusMotorAuxiliar \
    {                            \
        'M', 'T', 'A', 'S', 'W'  \
    }
#define topicMotorPrincipal     \
    {                           \
        'M', 'T', 'P', 'A', 'W' \
    }
#define topicCorrenteMotor      \
    {                           \
        'M', 'T', 'P', 'C', 'W' \
    }
#define topicStatusMotor        \
    {                           \
        'M', 'T', 'P', 'S', 'W' \
    }
#define topicResistencia        \
    {                           \
        'R', 'E', 'S', 'A', 'W' \
    }
#define topicCorrenteResistencia \
    {                            \
        'R', 'E', 'S', 'C', 'W'  \
    }
#define topicStatusResistencia  \
    {                           \
        'R', 'E', 'S', 'S', 'W' \
    }
#define topicPhMax              \
    {                           \
        'S', 'P', 'H', 'H', 'W' \
    }
#define topicPhMin              \
    {                           \
        'S', 'P', 'H', 'L', 'W' \
    }
#define topicPh                 \
    {                           \
        'S', 'P', 'H', 'R', 'W' \
    }
#define topicTemperaturaMax     \
    {                           \
        'T', 'M', 'P', 'H', 'W' \
    }
#define topicTemperaturaMin     \
    {                           \
        'T', 'M', 'P', 'L', 'W' \
    }
#define topicTemperatura        \
    {                           \
        'T', 'M', 'P', 'R', 'W' \
    }
#define topicTemperaturaAguaMax \
    {                           \
        'T', 'P', 'A', 'H', 'W' \
    }
#define topicTemperaturaAguaMin \
    {                           \
        'T', 'P', 'A', 'L', 'W' \
    }
#define topicTemperaturaAgua    \
    {                           \
        'T', 'P', 'A', 'R', 'W' \
    }
#define topicTensaoBateria      \
    {                           \
        'V', 'B', 'A', 'T', 'W' \
    }
#define topicUmidadeMax         \
    {                           \
        'U', 'M', 'I', 'H', 'W' \
    }
#define topicUmidadeMin         \
    {                           \
        'U', 'M', 'I', 'L', 'W' \
    }
#define topicUmidade            \
    {                           \
        'U', 'M', 'I', 'R', 'W' \
    }
extern unsigned short int atualizar = 0;
#define atualizaMenuEntrar 65
#define atualizaMenuSair 66
#define atualizaMenuAvancar 67
#define atualizaMenuVoltar 68
#define atualizaLCD 1
#define atualizarPWM1 99
#define atualizarPWM2 100
