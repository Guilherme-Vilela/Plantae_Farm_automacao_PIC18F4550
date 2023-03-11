
#define SUBMENU_TEMPERATURA_AMBIENTE 0
#define SUBMENU_UMIDADE 1
#define SUBMENU_TEMPERATURA_AGUA 2
#define SUBMENU_PH 3
#define SUBMENU_LUMINOSIDADE 4
#define ATUADOR_LED 0
#define ATUADOR_COOLER_AMBIENTE 1
#define ATUADOR_COOLER_AGUA 2
#define ATUADOR_RESISTENCIA 3

void resetarAcoesSubMenuAlteracao();
void alteraValorMaxMinSubMenuSensores(unsigned short int digitoPressionado, unsigned short int posicaoSubmenu);
void alterarPotenciaMotor(unsigned short int digito, unsigned short int *dutyCicle);
void alternarEstadoAtuadores(unsigned short int digitoPressionado, unsigned short int atuador, char atuadorNome[10]);
void selecaoPlanta(unsigned short int digitoPressionado);