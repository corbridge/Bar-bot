//#include "encoder.h"
//#include "screens.h"
#include "pumps.h"

#define RS 10
#define RW 11
#define Enable 13
#define RST 8

float volatile time;
float volatile timeActual;

void sendSubMenu(int up);

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
    sendSubMenu(up);
    switch(page){
      case 0:
        introPage(up, down, mid, bebidas, page);
        break;
      case 1:
        secondPage(up, down, mid, bebidas, page);
        break;
      case 2:
        optionPage(page_ant, up);
        break;
      case 3:
        fillingPage(up, bebidas, page_ant);
        //timeActual = millis();
        if(not Pumps){
          pumpsActivation(up, page_ant);
          //Serial.println("Activadas");
        }else{
          pumpsDeactivation(time);
          //Serial.println("Desactivadas");
        }
    
        // if(timeActual - time > 2000){
        //   page = 0;
        // } 
        break;
    }
  }while( u8g2.nextPage() );
  //Serial.println("Loop");
}

void sendSubMenu(int up)
{
    encoderButton();
    if(click == 1){
      if(page == 0 or page == 1){
      
            page_ant = page;
            page = 2;
          
        }
    }else if(click == 0){
      if(page == 2){
        //whitePage();
        if(upSub == minUpSub){

          page = 3;
          time = millis();
        }else{
          page = page_ant;
        }
      }
    }
}