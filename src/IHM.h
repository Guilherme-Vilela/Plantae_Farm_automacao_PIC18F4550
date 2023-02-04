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


void movimentaMenu(char tecla);
void verificaPressionamentoTeclado();
void iniciaTeclado();