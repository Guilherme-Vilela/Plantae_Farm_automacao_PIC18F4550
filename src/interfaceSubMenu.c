#include "interfaceSubMenu.h"
#include "global.h"
#include "LCD_I2C.h"
void escritaSensores(int atual, int max, int min, int unidadeMedida)
{
  char convercao[15];
  // unidadeMedida = 1 = TEMPERATURA
  // unidadeMedida = 2 = UMIDADE

  ShortToStr(atual, convercao);
  Lcd_Chr(1, 12, convercao[2]);
  Lcd_Chr(1, 13, convercao[3]);
  if (unidadeMedida == 1)
  {
    Lcd_Chr(1, 14, 223);
    Lcd_Chr(1, 15, 'C');
  }
  else if (unidadeMedida == 2)
  {
    Lcd_Chr(1,14,'%');
  }
  Lcd_Out(2,1,"MIN");
  ShortToStr(min, convercao);
  Lcd_Chr(2, 5, convercao[2]);
  Lcd_Chr(2, 6, convercao[3]);
  
  Lcd_Out(2,11,"MAX");
  ShortToStr(max, convercao);
  Lcd_Chr(2, 15, convercao[2]);
  Lcd_Chr(2, 16, convercao[3]);

}
//------------------------// SUBMENU SENSORES // -----------------------------//
void menuSensoresTempAmb_0(){
  LCD_Clear();
  Lcd_Out(1,2,"TEMP AMB:");
  escritaSensores(temperatura, temperaturaMAX, temperaturaMIN, 1);
}
void menuSensoresUmidade_1(){
  LCD_Clear();
  Lcd_Out(1,2,"UMIDADE:");
  escritaSensores(umidade, umidadeMAX, umidadeMIN, 2);
}
void menuSensoresTempAgua_2(){
  LCD_Clear();
  Lcd_Out(1,2,"TEMP AGUA:");
  escritaSensores(temperaturaAgua, temperaturaAguaMAX, temperaturaAguaMIN, 1);
}
void menuSensoresPH_3(){
  LCD_Clear();
  Lcd_Out(1,2,"PH:");
  escritaSensores(temperatura, temperaturaMAX, temperaturaMIN, 0);
}
void menuSensoresLuminosidade_4(){
  LCD_Clear();
  Lcd_Out(1,2,"LUMENS:");
  escritaSensores(luminosidade, luminosidadeMAX, luminosidadeMIN, 0);
}
//------------------------// FIM SUBMENU SENSORES // -----------------------------//

