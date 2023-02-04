//defines para saber o movimento do menu
#define  avancarMenu            acoesMenu.b0
#define  voltarMenu             acoesMenu.b1
#define  entrarMenu             acoesMenu.b2
#define  sairMenu               acoesMenu.b3
#define TECLADO_ADDRESS_W        0x40
#define TECLADO_ADDRESS_R        0x41
//defines para saber a posição do menu
#define  menuPrincipal          menuSelecionado.b0
#define  subMenu                menuSelecionado.b1
#define  subMenuAlteracoes      menuSelecionado.b2



void movimentaMenu(char tecla);
void verificaPressionamentoTeclado();