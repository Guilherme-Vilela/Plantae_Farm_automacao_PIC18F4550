#include "interfaceMenu.h"
#include "LCD_I2C.h"
#include "plantas.h"
void menuCultivo_1(){
  LCD_Clear();
//  if (planta_cultivada != 255)
//  {
    LCD_Out(1, 1, " CULTIVO: ");
//    LCD_Out(2, 1, plantas[planta_cultivada]);
    //diasRestantes = duracaoCultivo[planta_cultivada];
  //}
  //else if (planta_cultivada == 255)
 // {
    //Lcd_Out(1, 3, "CULTIVO NAO ");
    //Lcd_Out(2, 3, "SELECIONADO");
  //}
}
void menuSensores_2()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DOS");
 Lcd_Out(2, 1, "SENSORES");
}
void menuAtuadores_3()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DOS");
 Lcd_Out(2, 1, "ATUADORES");
}
void menuPlanta_4()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DAS");
 Lcd_Out(2, 1, "PLANTAS");
}
void menuRede_5()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DA");
 Lcd_Out(2, 1, "CONEXAO COM REDE");
}