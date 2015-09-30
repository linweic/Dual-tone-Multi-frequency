#include <hidef.h>
#include <mc9s12c128.h>
#include "stdio.h"
#include "termio.h"
//#include "terminal.h"
//#include "math.h"

unsigned int  ticks = 2272;
unsigned int ticks2, ticks3;
//unsigned long frequency, duration;
unsigned int count;
//char str[20];
//unsigned overflow;

void interrupt 10 OC2ISR(){
  printf("enter output compare inter 10\n");
  /*note: don't put printf in interrupt function!!!*/
  TC2 += ticks2;
  //TC3 += ticks3;
  TFLG1 = 0x04;    //clear OC2 flag
}

void interrupt 11 OC3ISR(){
  printf("enter output compare inter 11 \n");
  TC3 += ticks3;
  TFLG1 = 0x08;   //clear 0C3 flag
}
void interrupt 7 RealTimeInterrupt(){
  printf("enter\n");
  count++;
  if(count == 1) {
    PORTB = 0xFE; //make PB0 as low
    if(PORTB_BIT4 == 0){
      //putchar('A');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/697;
      ticks3 = 1000000/1633;
      TC2 += ticks2;
      TC3 += ticks3;
      //printf("ticks2: %d\n",ticks2);
      //printf("ticks3: %d\n",ticks3);
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT5 == 0){
      //putchar('3');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/697;
      ticks3 = 1000000/1477;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT6 == 0){
      //putchar('2');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/697;
      ticks3 = 1000000/1336;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT7 == 0){
      //putchar('1');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/697;
      ticks3 = 1000000/1209;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else{
      //TIE = 0x00; //disable timer interrupt
      TCTL2 = 0xA0;
    }
  }
  if(count == 2) {
    PORTB = 0xFD;  //make PB1 as low
    if(PORTB_BIT4 == 0){
      //putchar('B');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/770;
      ticks3 = 1000000/1633;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT5 == 0){
      //putchar('6');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/770;
      ticks3 = 1000000/1477;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT6 == 0){
      //putchar('5');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/770;
      ticks3 = 1000000/1336;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT7 == 0){
      //putchar('4');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/770;
      ticks3 = 1000000/1209;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else{
      //TIE = 0x00;
      TCTL2 = 0x00;
    }
  }
  if(count == 3) {
    PORTB = 0xFB;   //make PB2 as low
    //printf("PB2:%d\n", PORTB_BIT2);
    if(PORTB_BIT4 == 0){
      //putchar('C');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/852;
      ticks3 = 1000000/1633;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT5 == 0){
      //putchar('9');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/852;
      ticks3 = 1000000/1477;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT6 == 0){
      //putchar('8');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/852;
      ticks3 = 1000000/1336;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT7 == 0){
      //putchar('7');
      TCTL2 = 0x50; //toggle OC2, OC3
      ticks2 = 1000000/852;
      ticks3 = 1000000/1209;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else{
      //TIE = 0x00;
      TCTL2 = 0x00;
    }
  } 
  if(count == 4) {
    PORTB = 0xF7 ;  //make PB3 as low
    //printf("PB3:%d\n", PORTB_BIT3);
    if(PORTB_BIT4 == 0){
      TCTL2 = 0x50; //toggle OC2, OC3
      //putchar('D');
      ticks2 = 1000000/941;
      ticks3 = 1000000/1633;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT5 == 0){
      TCTL2 = 0x50; //toggle OC2, OC3
      //putchar('#');
      ticks2 = 1000000/941;
      ticks3 = 1000000/1477;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT6 == 0){
      TCTL2 = 0x50; //toggle OC2, OC3
      //putchar('0');
      ticks2 = 1000000/941;
      ticks3 = 1000000/1336;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else if(PORTB_BIT7 == 0){
      TCTL2 = 0x50; //toggle OC2, OC3
      //putchar('*');
      ticks2 = 1000000/941;
      ticks3 = 1000000/1209;
      TC2 += ticks2;
      TC3 += ticks3;
      //TIE = 0x0C; //enable timer interrupt for channel 2,3
    } else{
      //TIE = 0x00;
      TCTL2 = 0x00;
    }
  count = 0;
  }
  TFLG1 = 0xFF; //clear output compare and input capture
}

void main(void) {
  /* put your own code here */
  TERMIO_Init(); //Initialize the Serial Port	
  TIOS = 0x0C;//set PT2 and PT3 to output compare
  TSCR1 |= 0x80; //enable the free running counter
  ticks2 = 1000;
  ticks3 = 1000;
  TC2 += ticks2;
  TC3 += ticks3;
  PTT = 0x00; //set PORTT as low
  TCTL2 = 0x00; //toggle OC2, OC3
  DDRB = 0x0F; //set PB0-PB3 as output and PB4-PB7 as input
  PORTB |= 0xFF; //initialize PB0-PB7 to high
  TSCR2 = 0x80; //enable local interrupt
  TFLG1 = 0x0C; //clear output compare and input capture 
  count = 0; 
  RTICTL = 0x64; //set RTI counter
  CRGINT |= 0x80; // enable RTI interrupt  
  TIE = 0x0C; //enable timer interrupt for channel 2,3
  EnableInterrupts;
  
  while(1);
}
