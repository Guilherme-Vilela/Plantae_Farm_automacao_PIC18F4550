#include "convertionChar.h"
void intToChar(int value, char *address){
    char *unidade = address+2;
    char *dezena = address+1;
    char *centena = address;
//    char *milhar = address+3;
//    *milhar = (value/1000)+48;
    *centena = ((value%1000)/100)+48;
    *dezena = (((value%1000)%100)/10)+48;
    *unidade = (((value%1000)%100)%10)+48;

//    if(milhar != 48 ){
      /*&address+3 = milhar;
      &address+2 = centena;
      &address+1 = dezena;
      address  = unidade;
    }else if(centena != 48){
      result[2] = centena;
      result[1]= dezena;
      result[0]= unidade;
    }
    else if(dezena != 48){
      result[1]= dezena;
      result[0]= unidade;
    }else{
      result[0]= unidade;
    }*/
}