#include <hidef.h>
#include <mc9s12c128.h>
#include "stdio.h"
#include "termio.h"

unsigned int ticks = 2272;

void interrupt 9 OC1ISR(){
  //printf("jin\n");
  TFLG1 = 0x02;    //clear OC2 flag
  TC1 += ticks;
}

void main(void) {
  /* put your own code here */
  TERMIO_Init(); //Initialize the Serial Port
	EnableInterrupts;
  TIOS = 0x02;//set PT1 to output compare
  TSCR1 |= 0x80; //enable the free running counter
  TC1 += ticks;
  PTT |= 0x00; //set PORTT as low
  TCTL2 = 0x04; //toggle OC1 pin50
  TIE = 0x02; //enable timer interrupt for channel 1
  TFLG1 = 0x02;
  while(1);  

}

