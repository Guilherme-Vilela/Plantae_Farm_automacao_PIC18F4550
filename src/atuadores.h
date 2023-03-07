// DEFINEES ATUADORES
#define COOLER_AGUA RD5_bit
#define COOLER_AGUA_TRIS TRISD5_bit

#define COOLER_AMBIENTE RD6_bit
#define COOLER_AMBIENTE_TRIS TRISD6_bit

#define RESISTENCIA_AMBIENTE RD2_bit
#define RESISTENCIA_TRIS_AMBIENTE TRISD2_bit

#define PIN_LED RD4_bit
#define MICROCONTROLADOR 0
#define USUARIO 1

// DEFINEES ATUADORES

void controleCoolerAmbiente(unsigned short int solicitante, unsigned short int acao);
void controleResistenciaAmbiente(unsigned short int solicitante, unsigned short int acao);
void controleCoolerAgua(unsigned short int solicitante, unsigned short int acao);
void controleResistenciaAgua(unsigned short int solicitante, unsigned short int acao);
void controleLed(unsigned short int solicitante, unsigned short int acao);
void controlePWM1(unsigned short int solicitante, unsigned short int acao);
void controlePWM2(unsigned short int solicitante, unsigned short int acao);
void aceleraPWM1(short valor);
void aceleraPWM2(short valor);
void desaceleraPWM1(short valor);
void desaceleraPWM2(short valor);
void setPWM1();