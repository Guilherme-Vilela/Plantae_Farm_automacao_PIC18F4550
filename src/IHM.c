#include "IHM.h"
#include "LCD_I2C.h"
#include "global.h"
#include "interfaceMenu.h"
#include "interfaceSubMenu.h"
#include "interfaceSubMenuAlteracao.h"
#include "conversao.h"
//------------------------------// MENU //------------------------------------//
unsigned short int movimentarMenuPrincipal(unsigned short int posicao)
{
  unsigned short int quantidadeMenus = 5;

  if (posicao == 255)
  {
    posicao = quantidadeMenus - 1;
  }
  else if (posicao == quantidadeMenus)
  {
    posicao = 0;
  }
  switch (posicao)
  {
  case 0:
    menuCultivo_1();
    break;
  case 1:
    menuSensores_2();
    break;
  case 2:
    menuAtuadores_3();
    break;
  case 3:
    menuPlanta_4();
    break;
  case 4:
    menuRede_5();
    break;
  }
  return posicao;
}

unsigned short int movimentaSubMenu(unsigned short int posicaoSubMenu, unsigned short int posicaoMenu)
{
  unsigned short int quantidadeSubMenu = 0;
  short int quantidadeSubMenus[5] = {1, 5, 5, 2, 4};

  quantidadeSubMenu = quantidadeSubMenus[posicaoMenu]; // pega a quantidade de submenus do Menu principal

  if (posicaoSubMenu == 255)
  {
    posicaoSubMenu = quantidadeSubMenu - 1;
  }
  else if (posicaoSubMenu == quantidadeSubMenu)
  {
    posicaoSubMenu = 0;
  }
  switch (posicaoMenu)
  {
  case 0: // menu1 de cultivo e seus derivados
    switch (posicaoSubMenu)
    {
    case 0:
      LCD_Clear();
      LCD_Out(1, 1, "SUB MENU");
      LCD_Out(2, 1, "11");
      break;
    }
    break;

  case 1: // menu2 de sensores e seus derivados
    switch (posicaoSubMenu)
    {
    case 0:
      menuSensoresTempAgua_2();
      break;
    case 1:
      menuSensoresUmidade_1();
      break;
    case 2:
      menuSensoresTempAmb_0();
      break;
    case 3:
      menuSensoresPH_3();
      break;
    case 4:
      menuSensoresLuminosidade_4();
      break;
    }
    break;
  case 2: // menu2 de Atuadores_3
    switch (posicaoSubMenu)
    {
    case 0:
      menuAtuadoresMotorPrincipal_0();
      break;
    case 1:
      menuAtuadoresMotorAuxiliar_1();
      break;
    case 2:
      menuAtuadoresLeds_2();
      break;
    case 3:
      menuAtuadoresCoolerAmbiente_3();
      break;
    case 4:
      menuAtuadoresCoolerAgua_4();
      break;
    }
    break;
  }
  return posicaoSubMenu;
}
unsigned short int movimentaSubmenuAlteracoes(unsigned short int posicaoSubMenuAlteracao, unsigned short int posicaoMenu, unsigned short int posicaoSubMenu, unsigned short int digito)
{
  unsigned short int quantidadeSubMenusAlteracao = 3;
  if (posicaoSubMenuAlteracao == 255)
  {
    posicaoSubMenu = quantidadeSubMenusAlteracao - 1;
  }
  else if (posicaoSubMenuAlteracao == quantidadeSubMenusAlteracao)
  {
    posicaoSubMenuAlteracao = 0;
  }
  switch (posicaoMenu)
  {
  case 0: //menu de cultivo
  case 1: // menu SENSORES
    switch (posicaoSubMenu)
    {
    case 0: // SUB MENU TEMPERATURA AMB
      if (posicaoSubMenuAlteracao == 0)
      {
        alteraValorSubMenuTemperaturaAmb(digito);
        LCD_Clear();
        LCD_Out(2, 1, "23");
      }
      break;
    case 1: // SUB MENU TEMPERATURA AMB
      LCD_Clear();
      LCD_Out(1, 1, "SUB MENU");
      LCD_Out(2, 1, "22");
      break;
    case 2:
      LCD_Clear();
      LCD_Out(1, 1, "SUB MENU");
      LCD_Out(2, 1, "23");
      break;
    }
    break;
   case 2: //menu de atuaodres
   switch (posicaoSubMenu){
    case 0: // SUB MENU TEMPERATURA AMB

        alterarPotenciaMotor(digito,&dutyCicle1);
   }
   break;
  }
  return posicaoSubMenuAlteracao;
}
int alteraPosicao(unsigned short int posicao, unsigned short int acao)
{
  if (acao.b0 != 0)
  {
    posicao = posicao + 1;
  }
  else if (acao.b1 != 0)
  {
    posicao = posicao - 1;
  }

  return posicao;
}
void movimentaMenu(char tecla)
{
  static unsigned short int menuSelecionado = 0;
  static unsigned short int posicaoMenuPrincipal = 0;
  static unsigned short int posicaoSubMenu = 0;
  static unsigned short int posicaoSubMenuAlteracoes = 0;
  unsigned short int digito = 10;
  unsigned short int acoesMenu = 0;
        
  switch (tecla)
  {
  case botaoVoltar:
    avancarMenu = 1;
    break;
  case botaoAvancar:
    voltarMenu = 1;
    break;
  case botaoEntrar:
    entrarMenu = 1;
    break;
  case botaoSair:
    sairMenu = 1;
    break;
  case botaoAtualizar:
    // atualiza informa��es da tela
    break;
  default:
    if ((tecla - '0') >= 0 && (tecla - '0') < 10)
    {
      digito = tecla - '0';
    }
    break;
  }

  if (sairMenu)
  {
    if (subMenuAlteracoes != 0)
    {
      subMenuAlteracoes = 0;
      resetarAcoesSubMenuAlteracao();
    }
    else if (subMenu != 0)
    {
      subMenuAlteracoes = 0;
      subMenu = 0;
      resetarAcoesSubMenuAlteracao();
    }
  }

  if (entrarMenu)
  {
   if(subMenu == 1 && subMenuAlteracoes == 1){
     digito = 65;
   }
    else if (subMenu != 0)
    {
      subMenuAlteracoes = 1;
      subMenu = 1;
    }
    else
    {
      subMenu = 1;
    }
  }

  if (subMenu == 0 && subMenuAlteracoes == 0)
  {
    // movimentar menu principal
    posicaoMenuPrincipal = alteraPosicao(posicaoMenuPrincipal, acoesMenu);
    posicaoMenuPrincipal = movimentarMenuPrincipal(posicaoMenuPrincipal);
  }
  else if (subMenu != 0 && subMenuAlteracoes == 0)
  {
    // movimenta submenu
    posicaoSubMenu = alteraPosicao(posicaoSubMenu, acoesMenu);
    posicaoSubMenu = movimentaSubMenu(posicaoSubMenu, posicaoMenuPrincipal);
  }
  else if (subMenu != 0 && subMenuAlteracoes != 0)
  {
    // movimenta submenualtera��o
    posicaoSubMenuAlteracoes = alteraPosicao(posicaoSubMenuAlteracoes, acoesMenu);
    posicaoSubMenuAlteracoes = movimentaSubmenuAlteracoes(posicaoSubMenuAlteracoes, posicaoMenuPrincipal, posicaoSubMenu, digito);
  }
}

//----------------------------------------------------------------------------//
void leituraTeclado()
{
  unsigned short coluna = 0;
  unsigned short linha = 0x00;
  unsigned short i = 0;
  char teclapressionada;
  //  char posicaoColunas[4] = {0xf0, 0x20, 0x40, 0x80};
  char teclas[4][4] = {{'*', '7', '4', '1'},
                       {'0', '8', '5', '2'},
                       {'#', '9', '6', '3'},
                       {'D', 'C', 'B', 'A'}};
  flagLeituraTecladoEmAndamento = 1; // set flag de processamento travando interrup��o
  I2C1_Start();                      // inicia comunicao I2C
  I2C1_Wr(enderecoTecladoLeitura);   // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  linha = I2C1_Rd(0);                // ARMAZENA DADOS DE LEITURA EM LINHA
  I2C1_Stop();

  switch (linha)
  { // COMPARA INFORMA��ES
  case 14:
    linha = 1;
    break; // SET LINHA 1
  case 13:
    linha = 2;
    break; // SET LINHA 2
  case 11:
    linha = 3;
    break; // SET LINHA 3
  case 7:
    linha = 4;
    break; // SET LINHA 4
  default:
    linha = 0;
    break; // SET LINHA 1
  }

  I2C1_Start();                    // INICIA COMUNICAO I2C
  I2C1_Wr(enderecoTecladoEscrita); // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE ESCRITA
  I2C1_Wr(0xf0);                   // ENVIA COMANDOS DO ARRAY, MODIFICA ENTRADAS E SAIDAS DO ESCRAVO
  I2C1_Stop();

  I2C1_Start();                    // INICIA COMUNICAO I2C
  I2C1_Wr(enderecoTecladoLeitura); // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  coluna = I2C1_Rd(0);             // ARMAZENA DADOS DE LEITURA EM COLUNA
  I2C1_Stop();
  switch (coluna)
  { // COMPARA INFORMA��ES
  case 224:
    coluna = 1;
    break;
  case 208:
    coluna = 2;
    break;
  case 176:
    coluna = 3;
    break;
  case 112:
    coluna = 4;
    break;
  default:
    coluna = 0;
    break;
  }
  iniciaTeclado();
  linha--;
  coluna--;
  if (linha != 255 && coluna != 255)
  {
    teclaPressionada = teclas[linha][coluna];
    /*LCD_Clear();
      Lcd_Chr(2, 12, teclaPressionada);*/
  }
  LCD_Clear();
  if (teclaPressionada == 'O')
  {
    // resetaMensagemErro();
  }
  // else if(mensagemExibida == 0){
  else
  {
    movimentaMenu(teclaPressionada);
  }
  /*Lcd_Chr(2,1,teclaPressionada);*/
  flagLeituraTecladoEmAndamento = 0; // RESET BIT INDICANDO QUE A PROCESSO ACABOU
  flagStatusTeclado = 1;             //  TECLADO PRESSIONADO
}

////////////////////////////////////////////////////////////////////////////////////
void verificaTecladoSolto()
{
  unsigned short valorRecebido = 0;

  while (I2C1_Is_Idle() == 0)
  {
  }; // VERIFICA SE BARRAMENTO FOI LIBERADO

  I2C1_Start();                    // I       INICIA COMUNICA��O I2C
  I2C1_Wr(enderecoTecladoLeitura); // ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  valorRecebido = I2C1_Rd(0);      // ARMAZENA DADOS DE LEITURA EM COLUNA
  I2C1_Stop();                     // FINALIZA COMUNICA��O I2C
  if (valorRecebido == 15)
  {                        // VERIFICA SE O TECLADO FOI SOLTO
    flagStatusTeclado = 0; // LIBERA BIT PARA PODER INCIAR UMA NOVA LEITURA DE TECLADO
  }
}

////////////////////////////////////////////////////////////////////////////////////
void verificaPressionamentoTeclado()
{                         // FUN��O PADR�O
  if (flagLeituraTeclado) // VERIFICA SE HOUVE ALGUM CLICK  1= SIM 0 =NAO
  {
    if (flagStatusTeclado == 0) // 1= PRESSIONADO 0= SOLTO
    {
      leituraTeclado();
    }
    else
    {
      verificaTecladoSolto(); // verifica se a tecla foi solta
    }
    flagLeituraTeclado = 0; // reseta flag da interrup��o
  }
  iniciaTeclado();
}

void iniciaTeclado()
{
  I2C1_Start();                    // Inicia I2C
  I2C1_Wr(enderecoTecladoEscrita); // Envia o byte por I2C (endere�o do dispositivo + Write)
  I2C1_Wr(configuracaoPortsIO);    // comando de configura��o das portas do CI
  I2C1_Stop();
}