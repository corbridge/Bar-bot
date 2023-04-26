#include <Arduino.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
#include "encoder.h"

#define RS 10
#define RW 11
#define Enable 13
#define RST 8

#define motor_1 3
#define motor_2 4
#define motor_3 5
#define motor_4 6
#define motor_5 7

#define salidaA 9
#define salidaB 2
#define boton 12

// int contador = 0; 
// int estadoA;
// int estadoPrevioA;

int contadorAnt = 0;

int up = 20;
int mid = 25;
int down = 30;

int maxUp = 50;
int maxMid = 55;
int maxDown = 60;

int minUp = 20;
int minMid = 25;
int minDown = 30;

U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* reset=*/ 8);

void drawTitle();
void introPage(int, int, int);
void secondPage();

void setup() {
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  pinMode(motor_5, OUTPUT);

  encoderSetup();

  u8g2.begin();
  u8g2.enableUTF8Print(); 
  u8g2.setColorIndex(1); 
}

void loop() {
  int contador = 0;
  int up = 20;
  int down = 30;
  int mid = 25;
  
  // for(int i = 0; i < 4; i++)
  // {

  //   u8g2.firstPage();
  //     do
  //     { 
  //       introPage(up, down, mid);
  //     } while( u8g2.nextPage() );
  //   up = up+10;
  //   down = down + 10;
  //   mid = mid + 10;

  //   delay(1000);
  // }

  u8g2.firstPage();

  do{ 
    introPage(up, down, mid);
  }while( u8g2.nextPage() );

  contador = encoder();
  if(contador > contadorAnt){
      up += 10;
      mid += 10;
      down += 10;
  }else if(contador < contadorAnt){
      up -= 10;
      mid -= 10;
      down -= 10;
  }

  contadorAnt = contador;

  if(up > upMax){
      up = minUp;
      mid = minMid;
      down = minDown;
  }else if(up < upMin){
      up = maxUp;
      mid = maxMid;
      down = maxDown;
  }
}

void drawTitle()
{
  u8g2.setFont(u8g2_font_profont22_tf);
  u8g2.drawStr(25, 15, "BAR-BOT");
}

void introPage(int up, int down, int mid)
{
  u8g2.drawLine(150, 18, 0, 18);
  u8g2.drawTriangle(0,up, 0,down, 5,mid);
  drawTitle();
  u8g2.setFont(u8g2_font_profont11_tf);
  u8g2.drawStr(10, 29, "Margarita");
  u8g2.drawStr(10, 39, "Sangria");
  u8g2.drawStr(10, 49, "Mojito");
  u8g2.drawStr(10, 59, "Bloody Mary");
}

void secondPage()
{
  u8g2.drawLine(150, 18, 0, 18);
  u8g2.drawTriangle(0,30, 0,40, 5,35);
  drawTitle();
  u8g2.setFont(u8g2_font_profont11_tf);
  u8g2.drawStr(10, 29, "Margarita");
  u8g2.drawStr(10, 39, "Sangria");
  u8g2.drawStr(10, 49, "Mojito");
  u8g2.drawStr(10, 59, "Bloody Mary");
}