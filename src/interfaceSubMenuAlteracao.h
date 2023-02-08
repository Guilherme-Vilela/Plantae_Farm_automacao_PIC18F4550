
#define subMenuTemperaturaAmb 0
#define subMenuUmidade 1
#define subMenuTemperaturaAgua 2
#define subMenuPH 3
#define subMenuLuminosidade 4

void resetarAcoesSubMenuAlteracao();
void alteraValorMaxMinSubMenuSensores(unsigned short int digitoPressionado, unsigned short int posicaoSubmenu);
void alterarPotenciaMotor(unsigned short int digito, unsigned short int *dutyCicle);

