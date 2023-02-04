#include "conversao.h"
void intToChar(int value, char *endereco){
    char *unidade = endereco+2;
    char *dezena = endereco+1;
    char *centena = endereco;
//    char *milhar = address+3;
//    *milhar = (value/1000)+48;
    *centena = ((value%1000)/100)+48;
    *dezena = (((value%1000)%100)/10)+48;
    *unidade = (((value%1000)%100)%10)+48;
}
void leituraADFloat(int valor_lido, char *enderecoUnidade , char *enderecoDecimal){
      unsigned short int unidade;
      unsigned short int decimal;
      float tensao;

      if (valor_lido > 0 ){
        tensao = (valor_lido*0.0049)/0.185;
        unidade =(int)tensao;
        decimal = (int)((tensao*10)-(unidade*10));
        *enderecoUnidade = unidade+48;
        *enderecoDecimal = decimal+48;
      }else{
        *enderecoUnidade =48;
        *enderecoDecimal = 48;
        enderecoDecimal++;
        *enderecoDecimal = 48;
      }
//float result = valor_lido*1;
}