#include <Arduino.h>
#include <U8g2lib.h>
#include <U8x8lib.h>

#define RS 10
#define RW 11
#define Enable 13
#define RST 8

#define motor_1 3
#define motor_2 4
#define motor_3 5
#define motor_4 6
#define motor_5 7

#define SW 12
#define DT 1
#define CLK 2

U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* reset=*/ 8);

void drawTitle();

void setup() {
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  pinMode(motor_5, OUTPUT);

  u8g2.begin();
  u8g2.enableUTF8Print(); 
  u8g2.setColorIndex(1); 
}

void loop() {
  u8g2.firstPage();
    do
    {   
      u8g2.drawTriangle(0,20, 0,30, 5,25);
      drawTitle();
      u8g2.setFont(u8g2_font_profont11_tf);
      u8g2.drawStr(10, 29, "Margarita");
      u8g2.drawStr(10, 39, "Sangria");
      u8g2.drawStr(10, 49, "Mojito");
      u8g2.drawStr(10, 59, "Bloody Mary");

    } while( u8g2.nextPage() );
}

void drawTitle()
{
  u8g2.setFont(u8g2_font_profont22_tf);
  u8g2.drawStr(25, 15, "BAR-BOT");
}
