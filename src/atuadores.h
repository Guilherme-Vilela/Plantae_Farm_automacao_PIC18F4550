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

void ligaCoolerAmbiente(unsigned short int solicitante);
void desligaCoolerAmbiente(unsigned short int solicitante);
void ligaResistenciaAmbiente(unsigned short int solicitante);
void desligaResistenciaAmbiente(unsigned short int solicitante);
void ligaCoolerAgua(unsigned short int solicitante);
void desligaCoolerAgua(unsigned short int solicitante);
void ligaResistenciaAgua(unsigned short int solicitante);
void desligaResistenciaAgua(unsigned short int solicitante);
void ligaLed();
void desligaLed();
