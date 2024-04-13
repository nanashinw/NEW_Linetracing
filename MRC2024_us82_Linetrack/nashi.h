//Global Read
#define ANALOG 0
#define SPI 1

#define TYPE SPI // ---Change here

#if TYPE == ANALOG
#define nashi(x) analogRead(x)

#else
#define nashi(x) NEW.readADC(x)
//#define nashi(x) NEW.readADC(7-x)
#endif


//SW_OK
#define is_D8 digitalRead(8)

#define wait_SW8()\
  while(is_D8 == 0)\
  ;