#include "encoder.h"
//#include "screens.h"
#include "pumps.h"

#define RS 10
#define RW 11
#define Enable 13
#define RST 8

void sendSubMenu(int page, int up);

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
    switch(page){
      case 0:
        introPage(up, down, mid, bebidas, page);
        sendSubMenu(page, up);
        break;
      case 1:
        secondPage(up, down, mid, bebidas, page);
        sendSubMenu(page, up);
        break;  
    }
  }while( u8g2.nextPage() );
}

void sendSubMenu(int page, int up)
{
    encoderButton(); 
    if(click == 1)
        {
        do
        {
            optionPage(page, up);
            if(click == 0) break;
        } while (u8g2.nextPage());
        
        }
}