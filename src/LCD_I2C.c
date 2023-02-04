#include "global.h"
#include "LCD_I2C.h"

void LCD_Init()
{
  LCD_WRITE(0x00);
  delay_ms(30);
  LCD_CMD(0x03);
  delay_ms(5);
  LCD_CMD(0x03);
  delay_ms(5);
  LCD_CMD(0x03);
  delay_ms(5);
  LCD_CMD(LCD_RETURN_HOME);
  delay_ms(5);
  LCD_CMD(0x20 | (LCD_TYPE << 2));
  delay_ms(50);
  LCD_CMD(LCD_TURN_ON);
  delay_ms(50);
  LCD_CMD(LCD_CLEAR);
  delay_ms(50);
  LCD_CMD(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
  delay_ms(50);
}

void LCD_WRITE(unsigned char Data)
{
  I2C1_Start();                             //Inicia I2C
  I2C1_Wr(LCD_ADDRESS);                            //Envia o byte por I2C (endere�o do dispositivo + Write)
  I2C1_Wr(Data);
  I2C1_Stop();
  delay_ms(3);
}

void LCD_WRITE_4Bit(unsigned char Nibble, unsigned char RS)
{

  Nibble |= RS;
  LCD_WRITE(Nibble | 0x04);
  LCD_WRITE(Nibble & 0xFB);
  delay_us(50);
  
}

void LCD_CMD(unsigned char CMD)
{
  unsigned char RS;
  RS =0 ;
  LCD_WRITE_4Bit(CMD & 0xF0, RS);
  LCD_WRITE_4Bit((CMD << 4) & 0xF0, RS);
  delay_us(50);
}

void LCD_Set_Cursor(unsigned char ROW, unsigned char COL)
{
  switch(ROW)
  {
    case 2:
      LCD_CMD(0xC0 + COL-1);
      break;
    case 3:
      LCD_CMD(0x94 + COL-1);
      break;
    case 4:
      LCD_CMD(0xD4 + COL-1);
      break;
    // Case 1
    default:
      LCD_CMD(0x80 + COL-1);
  }
}

void LCD_WRITE_Char(char Data)
{
  unsigned char RS;
  RS = 1;  // Data Register Select
  LCD_WRITE_4Bit(Data & 0xF0,RS);
  LCD_WRITE_4Bit((Data << 4) & 0xF0,RS);
}

void LCD_Chr(unsigned char row, unsigned char col, char Data){
    LCD_Set_Cursor(row,col);
    delay_us(50);
    LCD_WRITE_Char(Data);
}


void LCD_Out(unsigned char row, unsigned char col, char* Str)
{
  unsigned short int i;
    LCD_Set_Cursor(row,col);
    delay_us(50);
    for(i = 0; Str[i]!='\0'; i++){
      LCD_WRITE_Char(Str[i]);
    }
}

void LCD_Cursor() {
 LCD_CMD(LCD_UNDERLINE_ON);
 LCD_CMD(LCD_BLINK_CURSOR_ON);
}
void LCD_NoCursor() {
 LCD_CMD(LCD_CURSOR_OFF);

}
void LCD_Clear()
{
  LCD_CMD(0x01);
  delay_us(40);
}