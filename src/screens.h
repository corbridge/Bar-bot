#include <Arduino.h>
#include <U8g2lib.h>
#include <U8x8lib.h>

U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* reset=*/ 8);

char bebidas[2][4][12] = {
    {"Margarita", "Mojito", "Sangria", "Bloody Mary"},
    {"Vampiro", "Tequila", "Vodka", "Limpieza"}
};

void screensSetup()
{
    u8g2.begin();
    u8g2.enableUTF8Print(); 
    u8g2.setColorIndex(1); 
}

void drawTitle()
{
    u8g2.setFont(u8g2_font_profont22_tf);
    u8g2.drawStr(25, 15, "BAR-BOT");
}

void cleanTitle()
{
    u8g2.drawStr(25, 5, "       ");
    u8g2.drawStr(25, 15, "       ");
}

void introPage(int up, int down, int mid, char (*bebidas)[4][12], int page){
    u8g2.drawLine(150, 18, 0, 18);
    u8g2.drawTriangle(0,up,0,down,5,mid);
    drawTitle();
    u8g2.setFont(u8g2_font_profont11_tf);
    u8g2.drawStr(10, 29, "Margarita");
    u8g2.drawStr(10, 39, "Mojito");
    u8g2.drawStr(10, 49, "Sangria");
    u8g2.drawStr(10, 59, "Bloody Mary");
}

void secondPage(int up, int down, int mid, char (*bebidas)[4][12], int page){
    u8g2.drawLine(150, 18, 0, 18);
    u8g2.drawTriangle(0,up, 0,down, 5,mid);
    drawTitle();
    u8g2.setFont(u8g2_font_profont11_tf);
    u8g2.drawStr(10, 29, "Vampiro");
    u8g2.drawStr(10, 39, "Tequila");
    u8g2.drawStr(10, 49, "Vodka");
    u8g2.drawStr(10, 59, "Limpieza");
}

void optionPage(int page, int up)
{
    drawTitle();
    int opcion = (up/10)-2;
    u8g2.drawLine(150, 18, 0, 18);
    u8g2.setFont(u8g2_font_profont11_tf);
    u8g2.drawStr(10, 29, bebidas[page][opcion]);
    u8g2.drawStr(10, 39, "SELECCIONADA");
}
