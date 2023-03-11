#include "interfaceSubMenu.h"
#include "global.h"
#include "LCD_I2C.h"
#include "conversao.h"





void escritaSensores(int atual, int max, int min, int unidadeMedida)
{
  char variavelAtual[3];
  char variavelMaxima[3];
  char variavelMinima[3];
  // unidadeMedida = 1 = TEMPERATURA
  // unidadeMedida = 2 = UMIDADE
  intToChar( atual, &variavelAtual);

  Lcd_Chr(1, 12, variavelAtual[1]);
  Lcd_Chr(1, 13, variavelAtual[2]);
  if (unidadeMedida == 1)
  {
    Lcd_Chr(1, 14, 223);
    Lcd_Chr(1, 15, 'C');
  }
  else if (unidadeMedida == 2)
  {
    Lcd_Chr(1,14,'%');
  }
  intToChar( min, &variavelMinima);
  Lcd_Out(2,1,"MIN");
  Lcd_Chr(2, 5, variavelMinima[1]);
  Lcd_Chr(2, 6, variavelMinima[2]);
  
  intToChar( max, &variavelMaxima);
  Lcd_Out(2,11,"MAX");
  Lcd_Chr(2, 15, variavelMaxima[1]);
  Lcd_Chr(2, 16, variavelMaxima[2]);

}
//------------------------// SUBMENU CULTIVO // -----------------------------//
void menuSelecaoCultivo_0(){
  if(cultivoSelecionado !=0 ){
    LCD_Out(1, 1, "TROCA DO CULTIVO");
  }else{
  LCD_Out(1, 1, "ESCOLHA CULTIVO");
  }
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
  escritaSensores(temperatura, phMAX, phMIN, 0);
}
void menuSensoresLuminosidade_4(){
  LCD_Clear();
  Lcd_Out(1,2,"LUMENS:");
  escritaSensores(luminosidade, luminosidadeMAX, luminosidadeMIN, 0);
}
//------------------------// FIM SUBMENU SENSORES // -----------------------------//
void escritaAtuadores(int valor){
 char unidade;
 char decimal;
 leituraADFloat(valor,&unidade,&decimal);
 if(valor > 0 && (unidade > 48 || decimal > 48)){
 Lcd_Out(2,1,"Ligado:");
 
 }else{
 Lcd_Out(2,1,"Desligado:");
 }

 Lcd_Chr(2,11 ,' ');
 Lcd_Chr(2,12, unidade);
 Lcd_Chr(2,13, ',');
 Lcd_Chr(2,14, decimal) ;
 Lcd_Chr(2,15, 'A') ;

}

void menuAtuadoresMotorPrincipal_0(){
  LCD_Clear();
  Lcd_Out(1,1,"Motor Principal");
  escritaAtuadores(correnteMotorPrincipal);
}
void menuAtuadoresMotorAuxiliar_1(){
  LCD_Clear();
  Lcd_Out(1,1,"Motor Auxiliar");
  escritaAtuadores(correnteMotorAuxiliar);
}
void menuAtuadoresLeds_2(){
  LCD_Clear();
  Lcd_Out(1,1,"LEDs");
  escritaAtuadores(correnteLeds);
}
void menuAtuadoresCoolerAmbiente_3(){
  LCD_Clear();
  Lcd_Out(1,1,"Cooler Ambiente");
  escritaAtuadores(correnteCooler);
}
void menuAtuadoresCoolerAgua_4(){
  LCD_Clear();
  Lcd_Out(1,1,"Cooler Agua");
  escritaAtuadores(correnteCoolerAgua);
}

//------------------------// SUBMENU ATUADORES // -------------------------------//


//------------------------// SUBMENU ATUADORES // -------------------------------//