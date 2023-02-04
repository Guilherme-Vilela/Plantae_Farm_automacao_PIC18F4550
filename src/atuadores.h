//DEFINEES ATUADORES
#define COOLER_AGUA  RB3_bit
#define COOLER_AGUA_TRIS TRISB3_bit
#define COOLER_AMBIENTE  RB2_bit
#define COOLER_AMBIENTE_TRIS TRISB2_bit
#define LED  RE1_bit
#define LED_TRIS  TRISE1_bit
#define RESISTENCIA_AMBIENTE RA4_bit
#define RESISTENCIA_TRIS_AMBIENTE TRISA4_bit
#define RESISTENCIA_AGUA RA5_bit
#define RESISTENCIA_TRIS_AGUA TRISA5_bit
//DEFINEES ATUADORES

void ligaCoolerAmbiente();
void desligaCoolerAmbiente();
void ligaResistenciaAmbiente();
void desligaResistenciaAmbiente();
void ligaCoolerAgua();
void desligaCoolerAgua();
void ligaResistenciaAgua();
void desligaResistenciaAgua();
void verificaAtuadores();
void ligaLed();
void desligaLed();