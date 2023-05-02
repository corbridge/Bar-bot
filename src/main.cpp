#include "encoder.h"
//#include "screens.h"
#include "pumps.h"

#define RS 10
#define RW 11
#define Enable 13
#define RST 8

void setup() {
  pumpsSetup();
  encoderSetup();
  screensSetup();
}

void loop() {

  u8g2.firstPage();
  do{ 
    encoder();
    encoderAlgorithm();
    encoderButton();
    switch(page){
      case 0:
        introPage(up, down, mid, bebidas, page);
        if(click == 1)
        {
          do
          {
            optionPage(page, up);
            if(click == 0) break;
          } while (u8g2.nextPage());
          
        }
        break;
      case 1:
        secondPage(up, down, mid, bebidas, page);
        break;  
    }
  }while( u8g2.nextPage() );
}
