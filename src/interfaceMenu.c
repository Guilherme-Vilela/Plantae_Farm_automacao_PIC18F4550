#include "interfaceMenu.h"
#include "LCD_I2C.h"
#include "plantas.h"
#include "global.h"
void menuCultivo_0(){
  LCD_Clear();
    LCD_Out(1, 1, "CULTIVO: ");
    LCD_Out(2, 1, "MODO: ");
    if(modoFuncionamento){
    LCD_Out(2, 7, "AUTOMATICO");
    }else{
    LCD_Out(2, 7, "MANUAL");
    }

}
void menuSensores_1()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DOS");
 Lcd_Out(2, 1, "SENSORES");
}
void menuAtuadores_2()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DOS");
 Lcd_Out(2, 1, "ATUADORES");
}
void menuPlanta_3()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DAS");
 Lcd_Out(2, 1, "PLANTAS");
}
void menuRede_4()
{
 LCD_Clear();
 Lcd_Out(1, 1, "INFORMACOES DA");
 Lcd_Out(2, 1, "CONEXAO COM REDE");
}