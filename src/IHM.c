#include "IHM.h"
#include "LCD_I2C.h"
#include "global.h"
#include "interfaceMenu.h"
#include "interfaceSubMenu.h"
#include "interfaceSubMenuAlteracao.h"
//------------------------------// MENU //------------------------------------//
unsigned short int movimentarMenuPrincipal(unsigned short int posicao){
 unsigned short int quantidadeMenus = 5;
 
   if(posicao == 255){
     posicao = quantidadeMenus -1;
   }
   else if (posicao == quantidadeMenus){
     posicao = 0;
   }
   switch(posicao){
    case 0:
      menuCultivo_1();
      break;
    case 1:
      menuSensores_2();
      break;
    case 2:
      menuAtuadores_3();
      break;
    case 3 :
      menuPlanta_4();
      break;
    case 4 :
      menuRede_5();
      break;
   }
    return posicao;
 
}

unsigned short int movimentaSubMenu(unsigned short int posicaoSubMenu, unsigned short int posicaoMenu ){
 unsigned short int quantidadeSubMenu = 0;
 short int quantidadeSubMenus[5] ={1,5,2,2,4};
 
 quantidadeSubMenu = quantidadeSubMenus[posicaoMenu];
 if(posicaoSubMenu == 255){
  posicaoSubMenu = quantidadeSubMenu -1;
 }
 else if (posicaoSubMenu == quantidadeSubMenu){
 posicaoSubMenu = 0;
 }
 switch(posicaoMenu){
   case 0: //menu1 de cultivo e seus derivados
     switch(posicaoSubMenu){
      case 0:
        LCD_Clear();
        LCD_Out(1,1,"SUB MENU");
        LCD_Out(2,1,"11");
        break;
     }
   break;
   
   case 1: //menu2 de sensores e seus derivados
     switch(posicaoSubMenu){
      case 0:
        menuSensoresTempAmb_0();
        break;
      case 1:
        menuSensoresUmidade_1();
        break;
      case 2:
        menuSensoresTempAgua_2();
        break;
      case 3:
        menuSensoresPH_3();
        break;
      case 4:
        menuSensoresLuminosidade_4();
        break;
     }
   break;
 }
  return posicaoSubMenu;
}
unsigned short int movimentaSubmenuAlteracoes(unsigned short int posicaoSubMenuAlteracao, unsigned short int posicaoMenu,unsigned short int posicaoSubMenu,unsigned short int digito){
   unsigned short int quantidadeSubMenusAlteracao = 3;
   if(posicaoSubMenuAlteracao == 255){
    posicaoSubMenu = quantidadeSubMenusAlteracao -1;
   }
   else if (posicaoSubMenuAlteracao == quantidadeSubMenusAlteracao){
   posicaoSubMenuAlteracao = 0;
   }
   switch(posicaoMenu){
     case 0:
     case 1:
       switch(posicaoSubMenu){
        case 0:
             if(posicaoSubMenuAlteracao == 0){
              alteraValorSubMenuTemperaturaAmb(digito);
              LCD_Clear();
              LCD_Out(2,1,"23");
             }
             break;
        case 1:
          LCD_Clear();
          LCD_Out(1,1,"SUB MENU");
          LCD_Out(2,1,"22");
          break;
        case 2:
          LCD_Clear();
          LCD_Out(1,1,"SUB MENU");
          LCD_Out(2,1,"23");
          break;
       }
     break;
   }
    return posicaoSubMenuAlteracao;
}
int alteraPosicao(unsigned short int posicao, unsigned short int acao) {
  if(acao.b0 != 0){
   posicao = posicao + 1;
  } else if (acao.b1 != 0){
   posicao = posicao - 1 ;
  }
  
  return posicao;
}
void movimentaMenu(char tecla){
  unsigned short int acoesMenu;
  
  static unsigned short int menuSelecionado;
  static unsigned short int posicaoMenuPrincipal;
  static unsigned short int posicaoSubMenu;
  static unsigned short int posicaoSubMenuAlteracoes;
  unsigned short int digito = 10;
  acoesMenu = 0;
  digito = 10;
  switch (tecla){
   case '<':
        avancarMenu = 1;
        break;
   case '>':
       voltarMenu = 1;
       break;
   case '+':
       entrarMenu = 1;
       break;
   case '-':
       sairMenu = 1;
       break;
   default:
       if((tecla - '0')> 0 && (tecla - '0') < 10 ){
        digito = tecla - '0';
       }
       break;
  }

    if (sairMenu){
     if(subMenuAlteracoes != 0){
      subMenuAlteracoes = 0;
      resetarAcoesSubMenuAlteracao();
    }
     else if (subMenu != 0){
      subMenuAlteracoes = 0;
      subMenu = 0;
      resetarAcoesSubMenuAlteracao();
     }
    }
    
    if (entrarMenu){
      if (subMenu != 0){
        subMenuAlteracoes = 1;
        subMenu = 1;
      }
      else{
        subMenu  = 1;
      }
    }

  if(subMenu == 0 && subMenuAlteracoes == 0 ){
  //movimentar menu principal
    posicaoMenuPrincipal = alteraPosicao(posicaoMenuPrincipal, acoesMenu);
    posicaoMenuPrincipal = movimentarMenuPrincipal(posicaoMenuPrincipal);
  }
  else if (subMenu != 0 && subMenuAlteracoes == 0){
  //movimenta submenu
    posicaoSubMenu = alteraPosicao(posicaoSubMenu, acoesMenu);
    posicaoSubMenu = movimentaSubMenu(posicaoSubMenu,posicaoMenuPrincipal);
  }
  else if(subMenu != 0 && subMenuAlteracoes != 0){
  //movimenta submenualtera��o
    posicaoSubMenuAlteracoes = alteraPosicao(posicaoSubMenuAlteracoes, acoesMenu);
    posicaoSubMenuAlteracoes = movimentaSubmenuAlteracoes(posicaoSubMenuAlteracoes,posicaoMenuPrincipal,posicaoSubMenu,digito);
  }
}



//---------------[TECLADO MATRIZ ]-------------------
//---------------------------------------------------
void leituraTeclado(){
 unsigned short coluna = 6;
 unsigned short linha = 0x00;
 unsigned short i = 0;
 char teclapressionada;
 char posicaoColunas [4] = { 0x1F,0x2F,0x4F,0x8F};
 char teclas[4][4] ={{'7', '4', '1', 'O'},
  {'8','5', '2', '0'},
  {'9', '6', '3', '='},
  {'<', '>', '-', '+'}};

  flagLeituraTecladoEmAndamento = 1;     //set flag de processamento travando interrup��o
  while(I2C1_Is_Idle() == 0){};    //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Start();          //inicia comunicao I2C
  I2C1_Wr( 0x41 );                 //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  linha = I2C1_Rd(0);               //ARMAZENA DADOS DE LEITURA EM LINHA
  switch(linha){                     //COMPARA INFORMA��ES
   case 14: linha = 1; break;        //SET LINHA 1
   case 13: linha = 2; break;         //SET LINHA 2
   case 11: linha = 3; break;         //SET LINHA 3
   case  7: linha = 4; break;        //SET LINHA 4
   default : linha = 0; break;       //SET LINHA 1
  }
  while(i < 4 && coluna > 5){        //FOR PARA DESCOBRIR QUAL A COLUNA SELECIONADA
    I2C1_Repeated_Start();           //INICIA COMUNICAO I2C
    I2C1_Wr( TECLADO_ADDRESS_W );                 //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE ESCRITA
    I2C1_Wr(posicaoColunas[i]);      //ENVIA COMANDOS DO ARRAY, MODIFICA ENTRADAS E SAIDAS DO ESCRAVO

    I2C1_Repeated_Start();           //INICIA COMUNICAO I2C
    I2C1_Wr( TECLADO_ADDRESS_R );                  //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
    coluna = I2C1_Rd(0);             //ARMAZENA DADOS DE LEITURA EM COLUNA
    while(I2C_Is_Idle() == 0){};    //VERIFICA SE BARRAMENTO FOI LIBERADO

    switch(linha){                  //COMPARA��O PARA DESCOBRIR QUAL � A COLUNA
     case 0: coluna = 0;break;
     case 1: if(coluna.b0 == 1){ coluna = i;} break ;   //COMPARA SE HOUVE ALTERA��O NOS BITS
     case 2: if(coluna.b1 == 1){ coluna = i;} break;    //COMPARA SE HOUVE ALTERA��O NOS BITS
     case 3: if(coluna.b2 == 1){ coluna = i;} break;    //COMPARA SE HOUVE ALTERA��O NOS BITS
     case 4: if(coluna.b3 == 1){ coluna = i;} break;    //COMPARA SE HOUVE ALTERA��O NOS BITS
    }
    i++;
  }

  I2C1_Repeated_Start();  //INICIA COMUNICAO I2C
  I2C1_Wr( TECLADO_ADDRESS_W ); //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE ESCRITA
  I2C1_Wr(0x0F);   //RESETA AS ENTRADAS DO ESCVRAVO PARA O PADRAO

  I2C1_Repeated_Start();  //INICIA COMUNICAO I2C
  I2C1_Wr( TECLADO_ADDRESS_R );        //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  I2C1_Rd(0);                 //BUSCA INFORMA��ES E N�O ARAMAZENA
  I2C1_Stop();                // FINALIZA COMUNICA��O I2C
  linha--;
  teclaPressionada = teclas[linha][coluna];
  // LCD_Clear();
//   Lcd_Out(1,1,"voce apertou");
   //Lcd_Chr(2,1,teclaPressionada);
  if(teclaPressionada == 'O'){
    //resetaMensagemErro();
   }
   //else if(mensagemExibida == 0){
   else{
     movimentaMenu(teclaPressionada);
   }
    /*Lcd_Chr(2,1,teclaPressionada);*/
  flagLeituraTecladoEmAndamento = 0;           // RESET BIT INDICANDO QUE A PROCESSO ACABOU
  flagTecladoPressionado = 0;            //  INICIA BIT DE ESPERAR O USUARIO SOLTAR O BOT�O

}
void verificaTecladoSolto(){
 unsigned short valorRecebido = 0;
  I2C1_Start();                //I       INICIA COMUNICA��O I2C
  while(I2C1_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Wr( TECLADO_ADDRESS_R );        //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  while(I2C1_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  valorRecebido = I2C1_Rd(0); //ARMAZENA DADOS DE LEITURA EM COLUNA
  while(I2C1_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Stop();                   //FINALIZA COMUNICA��O I2C
  if(valorRecebido == 15){        //VERIFICA SE O TECLADO FOI SOLTO
    flagTecladoPressionado = 1;            //LIBERA BIT PARA PODER INCIAR UMA NOVA LEITURA DE TECLADO
  }
}
void verificaPressionamentoTeclado(){   //FUN��O PADR�O
 if(flagLeituraTeclado ){               //VERIFICA SE HOUVE ALGUM CLICK
  flagLeituraTeclado = 0;               //reseta flag da interrup��o
  if(flagTecladoPressionado){              //verifica se o teclado estava solto
  leituraTeclado();
             //faz leitura da tecla processada
  }else{
    verificaTecladoSolto();         //verifica se a tecla foi solta
  }
 }
}
//---------------[ FIM TECLADO MATRIZ ]-------------------
//---------------------------------------------------