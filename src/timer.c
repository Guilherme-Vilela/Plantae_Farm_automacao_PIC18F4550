unsigned short int timer1;
unsigned short int timer0;
void startTimer1(){
  TMR1L = 0;
  TMR1H = 0;
  timer1 = 0;
  T1CON = 0x31;
}
void stopTimer1(){
  T1CON = 0x30;
}