#include "interfaceSubMenuAlteracao.h"
#include "LCD_I2C.h"
#include "global.h"
#include "conversao.h"
static unsigned short int etapaConversao = 0;
static unsigned short int milhar = 0, centena = 0, dezena = 0, unidade = 0;
void alteraVariavel(unsigned short int *valorMin, unsigned short int *valorMax, unsigned short int digitoPressionado)
{
  char convercao[3];
  unsigned short int max, min, coluna;

  if (etapaConversao == 0 && digitoPressionado < 10) // verifica se ja recebeu o novo valor minimo
  {
    milhar = digitoPressionado * 10; // pega a dezena do valor minimo
    etapaConversao++;
  }
  else if (etapaConversao == 1 && digitoPressionado < 10)
  {
    centena = digitoPressionado; // pega a unidade  do valor minimo
    etapaConversao++;
  }
  else if (etapaConversao == 2 && digitoPressionado < 10)
  {
    dezena = digitoPressionado * 10; // pega a dezena do valor maximo
    etapaConversao++;
  }
  else if (etapaConversao == 3 && digitoPressionado < 10)
  {
    unidade = digitoPressionado; // pega a unidade do valor maximo
    etapaConversao++;
  }
  else if (etapaConversao == 4 && digitoPressionado == 65)
  {
    *valorMax = dezena + unidade;
    *valorMin = milhar + centena;
    resetarAcoesSubMenuAlteracao();
    atualizar = atualizaMenuSair;
  }
  LCD_Cursor();
  Lcd_Out(1, 1, "Alterar variaveis");

  switch (etapaConversao)
  {
  case 0:
    coluna = 5;
    max = *valorMax;
    min = *valorMin;
    break;
  case 1:
    coluna = 6;
    max = *valorMax;
    min = milhar + *valorMin % 10;
    break;
  case 2:
    coluna = 13;
    max = *valorMax;
    min = milhar + centena;
    break;
  case 3:
    coluna = 14;
    max = dezena + *valorMax % 10;
    min = milhar + centena;
    break;
  case 4:
    coluna = 16;
    max = dezena + unidade;
    min = milhar + centena;
    break;
  }

  Lcd_Out(2, 1, "MIN");
  intToChar(min, &convercao);
  Lcd_Chr(2, 5, convercao[1]);
  Lcd_Chr(2, 6, convercao[2]);

  Lcd_Out(2, 9, "MAX");
  intToChar(max, &convercao);
  Lcd_Chr(2, 13, convercao[1]);
  Lcd_Chr(2, 14, convercao[2]);
  if (etapaConversao == 4)
  {
    Lcd_Chr(2, 16, 'A');
  }
  LCD_Set_Cursor(2, coluna);
}
void alteraValorMaxMinSubMenuSensores(unsigned short int digitoPressionado, unsigned short int posicaoSubmenu)
{
  switch (posicaoSubmenu)
  {
  case subMenuTemperaturaAmb:
    alteraVariavel(&temperaturaMIN, &temperaturaMAX, digitoPressionado);
    break;
  case subMenuUmidade:
    alteraVariavel(&umidadeMIN, &umidadeMAX, digitoPressionado);
    break;
  case subMenuTemperaturaAgua:
    alteraVariavel(&temperaturaAguaMIN, &temperaturaAguaMAX, digitoPressionado);
    break;
  case subMenuPH:
    alteraVariavel(&phMIN, &phMAX, digitoPressionado);
    break;
  case subMenuLuminosidade:
    alteraVariavel(&luminosidadeMIN, &luminosidadeMAX, digitoPressionado);
    break;
  }
}
void resetarAcoesSubMenuAlteracao()
{
  etapaConversao = 0;
  centena = 0;
  dezena = 0;
  unidade = 0;
  LCD_NoCursor();
}
void alterarPotenciaMotor(unsigned short int digitoPressionado, unsigned short int *dutyCicle)
{
  int potenciaEmPorcentagem;
  char potencia[3];
  potenciaEmPorcentagem = *dutyCicle * 100 / 255;
  intToChar(potenciaEmPorcentagem, &potencia);

  if (etapaConversao == 0 && digitoPressionado <= 1)
  {
    centena = digitoPressionado;
    etapaConversao = 1;
  }
  else if (etapaConversao == 1 && digitoPressionado < 10)
  {
    dezena = digitoPressionado;
    etapaConversao = 2;
  }
  else if (etapaConversao == 2 && digitoPressionado < 10)
  {
    unidade = digitoPressionado;
    etapaConversao = 3;
  }
  else if (etapaConversao == 3 && digitoPressionado == 65)
  {
    if (centena == 1)
    {
      *dutyCicle = 255;
    }
    else
    {
      *dutyCicle = (int)((dezena * 10) + unidade) * 255 / 100;
    }
    resetarAcoesSubMenuAlteracao();
    atualizar = 1;
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
  switch (etapaConversao)
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