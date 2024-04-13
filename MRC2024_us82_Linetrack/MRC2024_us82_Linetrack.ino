#include <Adafruit_MCP3008.h>
#include "nashi.h"

// ---Change here
#if TYPE == SPI  
Adafruit_MCP3008 NEW;
#else
int pin[numsensor] = {A0, A1, A2, A3, A4, A5, A6, A7}
#endif 


//total sensor
#define numsensor 8  // ---Change here
int MAX[numsensor] = { 741, 870, 875, 870, 874, 878, 874, 864 };  // ---Change here
int MIN[numsensor] = { 318, 330, 407, 334, 390, 410, 368, 373 };  // ---Change here
unsigned long F[numsensor];
int last_value = 0;
float leftmotor, rightmotor, position, lasterror, powermotor, error;


void setup() {
  Serial.begin(9600);
  Setup_Motor();
  //^ begin(cl, mo, mi, ce);
  #if TYPE == SPI
  NEW.begin(A0, A2, A1, A3);  // ---Change here
  #endif

  //Read-Senser menu
  // wait_SW8();
  //view()
  // viewReadLine()

  wait_SW8();

  //code-here----
  ttime(50, 0.025, 0.2, 5000);


  //---End

}

void loop() {
  motor(0, 0);
}
