#include<avr/io.h>
//#include<uart.h>
#include <util/delay.h>
#include<stdbool.h> 


int main(void){
//UART_Init(9600);
// DDRB   |= 0x4F;
  

bool X,Y,Z,A,B,C;
 DDRB  = 0b11111000; //8,9,10 as input
 DDRD  = 0b00011100; //2&3&4 as output
 PORTB = 0b00000111; //pulling up the inputs 
 
 while(1)
   {
 
 
 PORTB  =  (1 <<PB5); 
  _delay_ms (500L);
  
 
  A = (PINB & (1 << PINB0)) == (1 << PINB0);
  B = (PINB & (1 << PINB1)) == (1 << PINB1);
  C = (PINB & (1 << PINB2)) == (1 << PINB2);
  
     
 //A = 0b0;
  //B= 0b0;
  //C= 0b1;
  
  
//  d= (PINB & (1<<PINB5)) == (0<<PINB5);
 
   //X=(A&&C)||(B&&(!C));
   //Y=((!A)&&C)||(B&&(!C));
   //Z=((!A)&&(!B))||(A&&B);
   
   X= ((A&&C) || (B&&!C));
   Y= ((!A&&C)||(B&&!C));
   Z = ((!A&&!B) || (A&&B));
   
  // PORTB |= (0 << 5); 
  // _delay_ms (1000);
   
   PORTB  =  (0 <<PB5);
  _delay_ms (500L);
  
   PORTD = (X<<2);
   PORTD |= (Y<<3);
   PORTD |= (Z<<4);   
 
  
     
}
  
 return 0;
  
 }
