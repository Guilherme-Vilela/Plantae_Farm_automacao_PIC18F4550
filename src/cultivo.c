#include "cultivo.h"
#include "ESP_I2C.h"
#include "global.h"
#include "DHT11.h"
#include "DS18B20.h"
#include "atuadores.h"
#include "leituraAD.h"
void selecaoCultivo(){

controlePWM1(1, LIGAR);
}
void enviarParametrosESP(){

}

void verificarSensores()
{
  leituraDht11(&umidade, &temperatura); // leitura de valores DHT11
  leituraDs18b20(&temperaturaAgua);     // LEITURA TEMPERATURA DA �GUA
  leituraPortasAnalogicas();            // faz a leitura das 9 entradas analogicas
}