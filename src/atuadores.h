//DEFINEES ATUADORES
#define COOLER_AGUA  RD5_bit
#define COOLER_AGUA_TRIS TRISD5_bit

#define COOLER_AMBIENTE  RD6_bit
#define COOLER_AMBIENTE_TRIS TRISD6_bit

#define RESISTENCIA_AMBIENTE RD2_bit
#define RESISTENCIA_TRIS_AMBIENTE TRISD2_bit

//DEFINEES ATUADORES

void ligaCoolerAmbiente();
void desligaCoolerAmbiente();
void ligaResistenciaAmbiente();
void desligaResistenciaAmbiente();
void ligaCoolerAgua();
void desligaCoolerAgua();
void ligaResistenciaAgua();
void desligaResistenciaAgua();
void ligaLed();
void desligaLed();