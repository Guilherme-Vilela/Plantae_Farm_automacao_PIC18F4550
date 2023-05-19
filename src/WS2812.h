#define LED_PIN  RD3_bit
#define LED_PIN_DIR TRISD3_bit
//bliblioteca para funcionamento dos leds
void enviarBit1();
void enviarBit0();
void vermelho();
void azul();
void preto();
void ligar_led(unsigned short int quantidade);
void desliga_led(unsigned short int quantidade);