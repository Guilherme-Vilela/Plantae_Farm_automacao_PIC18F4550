//DECLARAÇÃO DE VARIAVEIS
#define MOTOR_2 RC1_bit
#define MOTOR_2_TRIS TRISC1_bit
#define MOTOR_1 RC2_bit
#define MOTOR_1_TRIS TRISC2_bit


void aceleraPWM1(short valor);
void aceleraPWM2(short valor);
void desaceleraPWM1(short valor);
void desaceleraPWM2(short valor);
void desligarPWM1();
void desligarPWM2();
void iniciarPWM();
void iniciarPWM2();
void setPWM1();