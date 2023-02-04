

char intTeclado = 0;
//flagLeituraTeclado ACIONADO QUANDO RB4 MUDA DE STATUS  1= HOUVE INTERRUP��O   0= SEM INTERRUP��O
//flagLeituraTecladoEmAndamento ACIONADO QUANDO INCIA PROCESSO DE CAPUTA DE TECLA PRESSIONADA  1= EM PROCESSO   0= COMPLETO
//flagStatusTeclado UTILIZADO PARA SABER SE O BOT�OJA FOI SOLTO 1 = SOLTO 0 = PRESSIONADO

void leituraTeclado(){
 unsigned short coluna = 6;
 unsigned short linha = 0x00;
 unsigned short i = 0;
 char teclapressionada;
 char posicaoColunas [4] = { 0x1F,0x2F,0x4F,0x8F};
 
 char teclas[4][4] ={{'7', '4', '1', 'O'},
  {'8','5', '2', '0'},
  {'9', '6', '3', '='},
  {'<', 'C', '-', '+'}};
  
  flagLeituraTecladoEmAndamento = 1;     //set flag de processamento travando interrup��o
  I2C1_Start();          //inicia comunicao I2C
  while(I2C1_Is_Idle() == 0){};    //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Wr( 0x41 );                 //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  while(I2C1_Is_Idle() == 0){};     //VERIFICA SE BARRAMENTO FOI LIBERADO
  linha = I2C1_Rd(0);               //ARMAZENA DADOS DE LEITURA EM LINHA
  while(I2C1_Is_Idle() == 0){};     //VERIFICA SE BARRAMENTO FOI LIBERADO
  switch(linha){                     //COMPARA INFORMA��ES
   case 14: linha = 1; break;        //SET LINHA 1
   case 13: linha = 2;break;         //SET LINHA 2
   case 11: linha = 3;break;         //SET LINHA 3
   case  7: linha = 4; break;        //SET LINHA 4
   default : linha = 0; break;       //SET LINHA 1
  }
  while(i < 4 && coluna > 5){        //FOR PARA DESCOBRIR QUAL A COLUNA SELECIONADA
    I2C1_Repeated_Start();           //INICIA COMUNICAO I2C
    while(I2C1_Is_Idle() == 0){};    //VERIFICA SE BARRAMENTO FOI LIBERADO
    I2C1_Wr( 0x40 );                 //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE ESCRITA
    while(I2C1_Is_Idle() == 0){};   //VERIFICA SE BARRAMENTO FOI LIBERADO
    I2C1_Wr(posicaoColunas[i]);      //ENVIA COMANDOS DO ARRAY, MODIFICA ENTRADAS E SAIDAS DO ESCRAVO
    while(I2C1_Is_Idle() == 0){};   //VERIFICA SE BARRAMENTO FOI LIBERADO

    I2C1_Repeated_Start();           //INICIA COMUNICAO I2C
    while(I2C_Is_Idle() == 0){};    //VERIFICA SE BARRAMENTO FOI LIBERADO
    I2C1_Wr( 0x41 );                  //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
    while(I2C_Is_Idle() == 0){};    //VERIFICA SE BARRAMENTO FOI LIBERADO
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
  while(I2C_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Wr( 0x40 ); //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE ESCRITA
  while(I2C_Is_Idle() == 0){}; //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Wr(0x0F);                //RESETA AS ENTRADAS DO ESCVRAVO PARA O PADRAO
  while(I2C_Is_Idle() == 0){}; //VERIFICA SE BARRAMENTO FOI LIBERADO

  I2C1_Repeated_Start();  //INICIA COMUNICAO I2C
  while(I2C_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Wr( 0x41 );        //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  while(I2C_Is_Idle() == 0){}; //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Rd(0);                 //BUSCA INFORMA��ES E N�O ARAMAZENA
  while(I2C_Is_Idle() == 0){}; //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Stop();                // FINALIZA COMUNICA��O I2C
  linha--;
  teclaPressionada = teclas[linha][coluna];
     //LCD_Clear();
   //Lcd_Out(1,1,"voce apertou");
   //Lcd_Chr(2,1,*tecla);
  if(teclaPressionada == 'O'){
    //resetaMensagemErro();
   }
   //else if(mensagemExibida == 0){
   else{
     movimentaMenu(&teclaPressionada);
   }
    /*Lcd_Chr(2,1,teclaPressionada);*/
  flagLeituraTecladoEmAndamento = 0;           // RESET BIT INDICANDO QUE A PROCESSO ACABOU
  flagStatusTeclado = 0;            //  INICIA BIT DE ESPERAR O USUARIO SOLTAR O BOT�O

}
void verificaTecladoSolto(){
 unsigned short valorRecebido = 0;
  I2C1_Start();                //I       INICIA COMUNICA��O I2C
  while(I2C1_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Wr( 0x41 );        //ENVIA ENDERE�O DO DISPOSITVO ESCRAVO E COMANDO DE LEITURA
  while(I2C1_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  valorRecebido = I2C1_Rd(0); //ARMAZENA DADOS DE LEITURA EM COLUNA
  while(I2C1_Is_Idle() == 0){};  //VERIFICA SE BARRAMENTO FOI LIBERADO
  I2C1_Stop();                   //FINALIZA COMUNICA��O I2C
  if(valorRecebido == 15){        //VERIFICA SE O TECLADO FOI SOLTO
    flagStatusTeclado = 1;            //LIBERA BIT PARA PODER INCIAR UMA NOVA LEITURA DE TECLADO
  }

}
void verificaPressionamentoTeclado(){   //FUN��O PADR�O
 if(flagLeituraTeclado ){               //VERIFICA SE HOUVE ALGUM CLICK
  flagLeituraTeclado = 0;               //reseta flag da interrup��o
  if(flagStatusTeclado){              //verifica se o teclado estava solto
  leituraTeclado();
             //faz leitura da tecla processada
  }else{
    verificaTecladoSolto();         //verifica se a tecla foi solta
  }
 }
}