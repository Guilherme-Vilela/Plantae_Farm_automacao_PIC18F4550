unsigned short int timer1;
unsigned short int timer0;
void startTimer1(){
  TMR1L = 0;
  TMR1H = 0;
  timer1 = 0;
  T1CON = 0xB1;
}
void stopTimer1(){
  T1CON = 0x30;
}

void startTimer0(){
TMR0L = 0;
TMR0H = 0;
T0CON = 0x87 ;
}
void stopTimer0(){
T0CON = 0x07 ;
}