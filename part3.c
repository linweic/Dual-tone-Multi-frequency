#include <hidef.h>
#include <mc9s12c128.h>
#include "stdio.h"
#include "termio.h"
#include "terminal.h"
//#include "math.h"

unsigned int i=0, ticks = 2272;
unsigned long ticks_p2;
unsigned long frequency, duration;
unsigned int count;
char str[20];
unsigned overflow;

void interrupt 9 OC1ISR(){
  //printf("enter output compare inter\n");
  /*note: don't put printf in interrupt function!!!*/
  TC1 += ticks_p2;
  TFLG1 = 0x02;    //clear OC1 flag
}

void interrupt 7 RealTimeInterrupt(){
  //printf("enter\n");
  count++;
  if(count == 1) {
      PORTB = 0xFE; //make PB0 as low
      if(PORTB_BIT4 == 0){
        putchar('A');
      }
      if(PORTB_BIT5 == 0){
        putchar('3');
      }
      if(PORTB_BIT6 == 0){
        putchar('2');
      }
      if(PORTB_BIT7 == 0){
        putchar('1');
      }
  }
  if(count == 2) {
    PORTB = 0xFD;  //make PB1 as low
    if(PORTB_BIT4 == 0){
        putchar('B');
      }
    if(PORTB_BIT5 == 0){
        putchar('6');
      }
    if(PORTB_BIT6 == 0){
        putchar('5');
      }
    if(PORTB_BIT7 == 0){
        putchar('4');
      }
  }
  if(count == 3) {
    PORTB = 0xFB;   //make PB2 as low
    //printf("PB2:%d\n", PORTB_BIT2);
    if(PORTB_BIT4 == 0){
        putchar('C');
      }
    if(PORTB_BIT5 == 0){
        putchar('9');
      }
    if(PORTB_BIT6 == 0){
        putchar('8');
      }
    if(PORTB_BIT7 == 0){
        putchar('7');
      }
  } 
  if(count == 4) {
    PORTB = 0xF7 ;  //make PB3 as low
    //printf("PB3:%d\n", PORTB_BIT3);
    if(PORTB_BIT4 == 0){
        putchar('D');
      }
      if(PORTB_BIT5 == 0){
        putchar('#');
      }
      if(PORTB_BIT6 == 0){
        putchar('0');
      }
      if(PORTB_BIT7 == 0){
        putchar('*');
      }
    count = 0;
  }
  TFLG1 = 0xFF; //clear output compare and input capture
}

void main(void) {
  /* put your own code here */
  TERMIO_Init(); //Initialize the Serial Port	
  //TIOS = 0x02;//set PT1 to output compare
  TSCR1 |= 0x80; //enable the free running counter
  //TC2 += ticks;
  //PTT = 0x00; //set PORTT as low
  //TCTL2 = 0x04; //toggle OC1 pin50
  DDRB = 0x0F; //set PB0-PB3 as output and PB4-PB7 as input
  PORTB |= 0xFF; //initialize PB0-PB7 to high
  //TSCR2 = 0x80; //enable local interrupt
  TFLG1 = 0xFF; //clear output compare and input capture 
  count = 0; 
  RTICTL = 0x62; //set RTI counter
  CRGINT |= 0x80; // enable RTI interrupt  
  EnableInterrupts;
  //printf("start");
  while(1);
}
