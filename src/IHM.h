//defines para saber o movimento do menu
#define  avancarMenu            1
#define  voltarMenu             2
#define  entrarMenu             3
#define  sairMenu               4
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


#define SUBMENU_TEMPERATURA_AMBIENTE 0
#define SUBMENU_UMIDADE 1
#define SUBMENU_TEMPERATURA_AGUA 2
#define SUBMENU_PH 3
#define SUBMENU_LUMINOSIDADE 4

#define SUBMENU_MOTOR_PRINCIPAL 0
#define SUBMENU_MOTOR_AUXILIAR 1
#define SUBMENU_LEDS 2
#define SUBMENU_COOLER_AMBIENTE 3
#define SUBMENU_COOLER_AGUA 4
#define SUBMENU_RESISTENCIA 5
void movimentaMenu(char tecla);
void verificaPressionamentoTeclado();
void iniciaTeclado();