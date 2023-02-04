
//biblioteca para DHT11
//DHT11
#define DHT11_PIN  RD1_bit
#define DHT11_PIN_DIR TRISD1_bit
//DECLARAÇÃO DE VARIAVEIS

unsigned short int leituraByteDht11();
void leituraDht11(unsigned short int *dht11_humi, unsigned short int *dht11_temp);