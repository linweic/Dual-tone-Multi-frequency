#include <hidef.h>
#include <mc9s12c128.h>
#include "stdio.h"
#include "termio.h"
#include "terminal.h"

unsigned int ticks = 2272;
unsigned long ticks_p2;
unsigned long frequency, duration;
char str[20];
unsigned overflow;

void interrupt 9 OC1ISR(){
  //printf("enter output compare inter\n");
  /*note: don't put printf in interrupt function!!!*/
  TC1 += ticks_p2;
  TFLG1 = 0x02;    //clear OC1 flag
}

void interrupt 16 TOFISR() {
  TFLG2 = 0x80; //clear TOF flag
  overflow ++;
}

int validate(unsigned long f){
  /*return 1 if input is valid, return 0 if input is invalid*/
  if(f>1000000) return 0;
  return 1;  
}
void main(void) {
  /* put your own code here */
  TERMIO_Init(); //Initialize the Serial Port	
  TIOS = 0x02;//set PT1 to output compare
  TSCR1 |= 0x80; //enable the free running counter
  //TC2 += ticks;
  PTT = 0x00; //set PORTT as low
  TCTL2 = 0x04; //toggle OC1 pin50
  TSCR2 = 0x80; //enable local interrupt
  TFLG1 = 0x02;    
  EnableInterrupts;
  while(1){
    
    /*read frequency and duration from input*/
    /*determine how many ticks for each toggle*/
    printf("please enter frequency and duration in millisecond:\n");
    TERM_ReadString(str, 20);
    printf("\ninput string:%s \n",str);
    sscanf(str, "%lu %lu", &frequency, &duration);
    ticks_p2 = 1000000/frequency;
    printf("frequency: %lu, duration: %lu, ticks_p2: %lu\n",frequency,duration, ticks_p2 );
    
    TIE = 0x02; //enable timer interrupt for channel 1
    TC1 += ticks_p2;
    overflow = 0;
    printf("%d", validate(frequency));
    if(validate(frequency)){
    /* an overflow period is roughly 32ms */
      if(duration<32){
        while(TCNT< (2*duration*1000000));
      }
      else{
        while((32*overflow+TCNT/2000) < duration);
      }
      TIE =0x00;//disable timer interrupt
      printf("time is up\n");
    } 
    else{
       printf("input frequency is invalid, please re-enter.\n");
    }
  }

}
