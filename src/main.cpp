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
        if(not Pumps){
          pumpsActivation(up, page_ant);
        }else{
          pumpsDeactivation(time);
        }
        break;
    }
  }while( u8g2.nextPage() );
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
      //Si cambia el estado del boton estando en la pagina 2
      if(page == 2){
        //Vamos a la pagina de filling si seleccionaron la primera opcion
        if(upSub == minUpSub){  
          page = 3;
          //Se toma el tiempo en el que se van a encender las bombas ppor primera vez
          time = millis();
        //Si era la segunda opcion, se regresa el menu a el anterior
        }else{
          page = page_ant;
        }
      }
    }
}