#include "interfaceSubMenuAlteracao.h"
#include "LCD_I2C.h"
#include "global.h"
static unsigned short int acoesConversao = 0;
static unsigned short int dezena =0 , unidade = 0;
void alteraVariavel(int *valorMin, int *valorMax, unsigned short int valorRecebido){
  char convercao[15];
  char novoValor[2];
  short int i;
  
  valorRecebido =0;
  
  if (movimento1Display == 0) //verifica se o display ja foi posicionado
  {
    LCD_Set_Cursor(2,5);
    LCD_CMD(LCD_UNDERLINE_ON);
    LCD_CMD(LCD_BLINK_CURSOR_ON);
    movimento1Display = 1;
  }
  else if (valorMinComplete == 0)  //verifica se ja recebeu o novo valor minimo
  {
    if(valorRecebido < 10){
      if (dezena == 0)
      {
        ShortToStr(valorRecebido, convercao);
        Lcd_Chr(2, 5,convercao[3]);
        dezena = valorRecebido;
      }
      else if (unidade == 0)
      {
        if (valorRecebido != temperatura % 10)
        {
          ShortToStr(valorRecebido, convercao);
          Lcd_Chr(2, 6,convercao[3]);
        }
        unidade = valorRecebido;
        *valorMin = (dezena * 10) + unidade;
        valorMinComplete = 1;
        LCD_Set_Cursor(2,12);
        LCD_CMD(LCD_UNDERLINE_ON);
        LCD_CMD(LCD_BLINK_CURSOR_ON);
        movimento2Display = 1;
      }
    }
  }
  else if (valorMinComplete && movimento2Display)
  {
     if(valorRecebido < 10){
        if (dezena == 0){
          //valorRecebido = validaDigito(*valorMax / 10, &botaoPressionadoSubMenu);
          if (valorRecebido != temperatura / 10)
          {
            ShortToStr(valorRecebido, convercao);
            Lcd_Chr(2, 13,convercao[3]);
            dezena = valorRecebido;
          }
        }
        else if (unidade == 0)
        {
          if (valorRecebido != temperatura % 10)
          {
            ShortToStr(valorRecebido, convercao);
            Lcd_Chr(2, 15,convercao[3]);
          }
          unidade = valorRecebido;
          *valorMax = (dezena * 10) + unidade;
          resetarAcoesSubMenuAlteracao();
          LCD_CMD(LCD_CURSOR_OFF);
          LCD_CMD(LCD_TURN_OFF);
        }
     }
  }
}
void alteraValorSubMenuTemperaturaAmb(unsigned short int digitoPressionado){
    alteraVariavel(&temperaturaMAX, &temperaturaMIN,digitoPressionado);
}
void resetarAcoesSubMenuAlteracao(){
 acoesConversao = 0;
 dezena = 0;
 unidade = 0;
}