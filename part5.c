#include <hidef.h>
#include <mc9s12c128.h>
#include "stdio.h"
#include "termio.h"
//#include "terminal.h"
//#include "math.h"

unsigned int count;
int ismiss1 = 0, ismiss2 = 0, ismiss3 = 0, ismiss4 = 0;

void interrupt 7 RealTimeInterrupt(){
  //printf("enter\n");
  TFLG1 = 0xFF; //clear output compare and input capture
  count++;
  if(count == 1) {
    ismiss1 = 0;
    PORTB = 0xFE; //make PB0 as low
    if(PORTB_BIT4 == 0){
      PWMPER23 = 2000000/697; 
      PWMPER45 = 2000000/1633;
      PWMDTY23 = 1000000/697;
      PWMDTY45 = 1000000/1633;
    } else if(PORTB_BIT5 == 0){      
      PWMPER23 = 2000000/697;
      PWMPER45 = 2000000/1477;
      PWMDTY23 = 1000000/697;
      PWMDTY45 = 1000000/1477;
    } else if(PORTB_BIT6 == 0){
      PWMPER23 = 2000000/697;
      PWMPER45 = 2000000/1336;
      PWMDTY23 = 1000000/697;
      PWMDTY45 = 1000000/1336;
    } else if(PORTB_BIT7 == 0){
      PWMPER23 = 2000000/697;
      PWMPER45 = 2000000/1209;
      PWMDTY23 = 1000000/697;
      PWMDTY45 = 1000000/1209;
    } else{
      ismiss1 = 1;
    }
  }
  if(count == 2) {
    ismiss2 = 0;
    PORTB = 0xFD;  //make PB1 as low
    if(PORTB_BIT4 == 0){
      PWMPER23 = 2000000/770;
      PWMPER45 = 2000000/1633;
      PWMDTY23 = 1000000/770;
      PWMDTY45 = 1000000/1633;
    } else if(PORTB_BIT5 == 0){
      PWMPER23 = 2000000/770;
      PWMPER45 = 2000000/1477;
      PWMDTY23 = 1000000/770;
      PWMDTY45 = 1000000/1477;
    } else if(PORTB_BIT6 == 0){
      PWMPER23 = 2000000/770;  //
      PWMPER45 = 2000000/1336;
      PWMDTY23 = 1000000/770;
      PWMDTY45 = 1000000/1336;
    } else if(PORTB_BIT7 == 0){
      PWMPER23 = 2000000/770; 
      PWMPER45 = 2000000/1209;
      PWMDTY23 = 1000000/770;
      PWMDTY45 = 1000000/1209;
    } else{
      ismiss2 = 1;
    }
  }
  if(count == 3) {
    ismiss3 = 0;
    PORTB = 0xFB;   //make PB2 as low
    //printf("PB2:%d\n", PORTB_BIT2);
    if(PORTB_BIT4 == 0){
      PWMPER23 = 2000000/852; 
      PWMPER45 = 2000000/1633;
      PWMDTY23 = 1000000/852;
      PWMDTY45 = 1000000/1633;
    } else if(PORTB_BIT5 == 0){
      PWMPER23 = 2000000/852; 
      PWMPER45 = 2000000/1477;
      PWMDTY23 = 1000000/852;
      PWMDTY45 = 1000000/1477;
    } else if(PORTB_BIT6 == 0){
      PWMPER23 = 2000000/852;
      PWMPER45 = 2000000/1336;
      PWMDTY23 = 1000000/852;
      PWMDTY45 = 1000000/1336;
    } else if(PORTB_BIT7 == 0){
      PWMPER23 = 2000000/852; 
      PWMPER45 = 2000000/1209;
      PWMDTY23 = 1000000/852;
      PWMDTY45 = 1000000/1209;
    } else{
      ismiss3 = 1;
    }
  } 
  if(count == 4) {
    ismiss4 = 0;
    PORTB = 0xF7 ;  //make PB3 as low
    if(PORTB_BIT4 == 0){
      PWMPER23 = 2000000/941; 
      PWMPER45 = 2000000/1633;
      PWMDTY23 = 1000000/941;
      PWMDTY45 = 1000000/1633;
    } else if(PORTB_BIT5 == 0){
      PWMPER23 = 2000000/941; 
      PWMPER45 = 2000000/1477;
      PWMDTY23 = 1000000/941;
      PWMDTY45 = 1000000/1477;
    } else if(PORTB_BIT6 == 0){
      PWMPER23 = 2000000/941;  
      PWMPER45 = 2000000/1336;
      PWMDTY23 = 1000000/941;
      PWMDTY45 = 1000000/1336;
    } else if(PORTB_BIT7 == 0){
      PWMPER23 = 2000000/941; 
      PWMPER45 = 2000000/1209;
      PWMDTY23 = 1000000/941;
      PWMDTY45 = 1000000/1209;
    } else{
      ismiss4 = 1;
    }
    count = 0;
  }
  if(ismiss1 * ismiss2 * ismiss3 * ismiss4 == 1){
    PWMDTY23 = 0;
    PWMDTY45 = 0;
    ismiss1 = 0;
    ismiss2 = 0;
    ismiss3 = 0;
    ismiss4 = 0;
  }
}

void main() {
  TERMIO_Init(); //Initialize the Serial Port
  TSCR1 |= 0x80; //enable the free running counter
  DDRB = 0x0F; //set PB0-PB3 as output and PB4-PB7 as input
  PORTB |= 0xFF; //initialize PB0-PB7 to high
  
  PWMCLK = 0x00; //select clock A as clock source for channel 3 and 5
  PWMPOL = 0x3C; //make waveform to start with high level
  PWMCTL = 0X6C; //cancatenate channel 4, 5 and channel 2,3
  PWMPRCLK = 0x00;//set the prescalor as 32
  PWMCAE = 0x00;  //let channels operate in left aligned output mode
  PWME |= 0x3C; //enable channel 2,3,4,5  
  
  TFLG1 = 0xFF; //clear output compare and input capture 
  count = 0; 
  RTICTL = 0x62; //set RTI counter
  CRGINT |= 0x80; // enable RTI interrupt  
  EnableInterrupts;
  while(1);

}
