#include "nashi.h"

void readRaw() {
  for (int i = 0; i < numsensor; i++) {
    F[i] = nashi(i);
  }
}

void Read() {
  int x = 0;
  for (int i = 0; i < numsensor; i++) {
    x = map(nashi(i), MIN[i], MAX[i], 1000, 0);
    if (x > 1000) x = 1000;
    if (x < 0) x = 0;
    F[i] = x;
  }
}



//Auto Calibrate
void _CalibrateSensor(unsigned int samples) {
  for (unsigned int ii = 0; ii <= samples; ii++) {
    readRaw();
    for (unsigned int jj = 0; jj < numsensor; jj++) {
      MIN[jj] = (F[jj] <= MIN[jj] ? F[jj] : MIN[jj]);
      MAX[jj] = (F[jj] >= MAX[jj] ? F[jj] : MAX[jj]);
    }
    delay(2);
  }
}


void _ResetValue(void)
{
	for (unsigned char i = 0; i < numsensor; i++)
	{
		MIN[i] = 1023; //change to bit of board <---- 8-bit
		MAX[i] = 0;
	}
}