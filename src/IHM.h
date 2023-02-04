//defines para saber o movimento do menu
#define  avancarMenu            acoesMenu.b0
#define  voltarMenu             acoesMenu.b1
#define  entrarMenu             acoesMenu.b2
#define  sairMenu               acoesMenu.b3
#define  enderecoTecladoEscrita        0x42
#define  enderecoTecladoLeitura        0x43
#define  configuracaoPortsIO      0x0f
//defines para saber a posi��o do menu
#define  menuPrincipal          menuSelecionado.b0
#define  subMenu                menuSelecionado.b1
#define  subMenuAlteracoes      menuSelecionado.b2


#define botaoAvancar   'C'
#define botaoVoltar   'D'
#define botaoEntrar   'A'
#define botaoSair   'B'
#define botaoAtualizar  'X'

#define menuCultivo 0
#define menuSensores 1
#define menuAtuadores 2
#define menuPlanta 3
#define menuRede 4


#define subMenuTemperaturaAmb 0
#define subMenuUmidade 1
#define subMenuTemperaturaAgua 2
#define subMenuPH 3
#define subMenuLuminosidade 4

#define subMenuMotorPrincipal 0
#define subMenuMotorAuxiliar 1
#define subMenuLeds 2
#define subMenuCoolerAmbiente 3
#define subMenuCoolerAgua 4

void movimentaMenu(char tecla);
void verificaPressionamentoTeclado();
void iniciaTeclado();