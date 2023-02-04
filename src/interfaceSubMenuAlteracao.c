#include "interfaceSubMenuAlteracao.h"
#include "LCD_I2C.h"
#include "global.h"
#include "conversao.h"
static unsigned short int acoesConversao = 0;
static unsigned short int centena = 0, dezena = 0, unidade = 0;
void alteraVariavel(unsigned short int *valorMin, unsigned short int *valorMax, unsigned short int valorRecebido)
{
  char convercao[3];
  char novoValor[2];

  valorRecebido = 0;

  if (movimento1Display == 0) // verifica se o display ja foi posicionado
  {
    LCD_Set_Cursor(2, 5);
    LCD_CMD(LCD_UNDERLINE_ON);
    LCD_CMD(LCD_BLINK_CURSOR_ON);
    movimento1Display = 1;
  }
  else if (valorMinComplete == 0) // verifica se ja recebeu o novo valor minimo
  {
    if (valorRecebido < 10)
    {
      if (dezena == 0)
      {
        intToChar(valorRecebido, &convercao);
        Lcd_Chr(2, 5, convercao[2]);
        dezena = valorRecebido;
      }
      else if (unidade == 0)
      {
        if (valorRecebido != temperatura % 10)
        {
          intToChar(valorRecebido, &convercao);
          Lcd_Chr(2, 6, convercao[2]);
        }
        unidade = valorRecebido;
        *valorMin = (dezena * 10) + unidade;
        valorMinComplete = 1;
        LCD_Set_Cursor(2, 12);
        LCD_CMD(LCD_UNDERLINE_ON);
        LCD_CMD(LCD_BLINK_CURSOR_ON);
        movimento2Display = 1;
      }
    }
  }
  else if (valorMinComplete && movimento2Display)
  {
    if (valorRecebido < 10)
    {
      if (dezena == 0)
      {
        // valorRecebido = validaDigito(*valorMax / 10, &botaoPressionadoSubMenu);
        if (valorRecebido != temperatura / 10)
        {
          intToChar(valorRecebido, &convercao);
          Lcd_Chr(2, 13, convercao[2]);
          dezena = valorRecebido;
        }
      }
      else if (unidade == 0)
      {
        if (valorRecebido != temperatura % 10)
        {
          intToChar(valorRecebido, &convercao);
          Lcd_Chr(2, 15, convercao[2]);
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
void alteraValorSubMenuTemperaturaAmb(unsigned short int digitoPressionado)
{
  alteraVariavel(&temperaturaMAX, &temperaturaMIN, digitoPressionado);
}
void resetarAcoesSubMenuAlteracao()
{
  acoesConversao = 0;
  centena = 0;
  dezena = 0;
  unidade = 0;
  LCD_NoCursor();
}
void alterarPotenciaMotor(unsigned short int digito, unsigned short int *dutyCicle)
{
  int potenciaEmPorcentagem;
  char potencia[3];
  potenciaEmPorcentagem = *dutyCicle*100/255;
  intToChar(potenciaEmPorcentagem, &potencia);

  if (acoesConversao == 0 && digito <= 1 )
  {
    centena = digito;
    acoesConversao = 1;
  }
  else if (acoesConversao == 1 && digito < 10)
  {
    dezena = digito;
    acoesConversao = 2;
  }
  else if (acoesConversao == 2 && digito < 10)
  {
    unidade = digito;
    acoesConversao = 3;
  }
  else if (acoesConversao == 3 && digito == 65)
  {
  if(centena == 1){
  *dutyCicle =255;
  }
  else{
  *dutyCicle= (int)((dezena *10)+unidade)*255/100 ;
  }
  resetarAcoesSubMenuAlteracao();
  atualizaMenu=1;
  }
  LCD_Cursor();
  LCD_Out(1, 1, "Motor em: ");
  LCD_Chr(1, 12, potencia[0]);
  LCD_Chr(1, 13, potencia[1]);
  LCD_Chr(1, 14, potencia[2]);
  LCD_Chr(1, 15, '%');
  LCD_Out(2, 1, "% desejada: ");
  LCD_Chr(2, 12, centena + 48);
  LCD_Chr(2, 13, dezena + 48);
  LCD_Chr(2, 14, unidade + 48);
  LCD_Chr(2, 15, '%');
  switch (acoesConversao)
  {
  case 0:
    LCD_Set_Cursor(2, 12);
    break;
  case 1:
    LCD_Set_Cursor(2, 13);
    break;
  case 2:
    LCD_Set_Cursor(2, 14);
    break;
  case 3:
    LCD_Chr(2, 16, 'A');
    LCD_Set_Cursor(2, 16);
    break;
  }
}