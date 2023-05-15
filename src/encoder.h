#include <Arduino.h>
#include "screens.h"

#define salidaA 9
#define salidaB 2
#define boton A0

int contador = 0; 
int estadoA;
int estadoPrevioA;

int contadorAnt = 0;
int maxUp = 50;
int maxMid = 55;
int maxDown = 60;

int minUp = 20;
int minMid = 25;
int minDown = 30;

int page = 0;

int up = 20;
int mid = 25;
int down = 30;

int contador_button = 0;
int contador_original = 0;
int click = 0;

byte state = LOW;
byte buttonState;
byte lastButtonState;

int submenu = 0;

int page_ant = 0;

unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;

void encoderSetup()
{
    pinMode (salidaA,INPUT);  
    pinMode (salidaB,INPUT);
    pinMode (boton, INPUT_PULLUP);

    Serial.begin (9600);
    estadoPrevioA = digitalRead(salidaA); 
}

void encoder()
{
    estadoA = digitalRead(salidaA);
    if (estadoA != estadoPrevioA){     
        if (digitalRead(salidaB) != estadoA) 
        { 
            contador ++;
        }
        else 
            {
            contador --;
            }
        delay(50);
    }
    estadoPrevioA = estadoA;
}

void encoderAlgorithm()
{
    if(page == 0 or page == 1){
        if(contador > contadorAnt){
            up += 10;
            mid += 10;
            down += 10;
        }
        if(contador < contadorAnt){
            up -= 10;
            mid -= 10;
            down -= 10;
        }

        contadorAnt = contador;

        if(up<minUp){
            switch(page){
            case 0:
                up = minUp;
                mid = minMid;
                down = minDown;
                break;
            case 1:
                page--;
                up = maxUp;
                mid = maxMid;
                down = maxDown;
                break;
            }
        }
        if(up>maxUp){
            switch(page){
                case 0:
                    page++;
                    up = minUp;
                    mid = minMid;
                    down = minDown;
                    break;
                case 1:  
                    up = maxUp;
                    mid = maxMid;
                    down = maxDown;
                    break;
            }
        } 
    }else{
        if(contador > contadorAnt){
            upSub += 10;
            midSub += 10;
            downSub += 10;
        }
        if(contador < contadorAnt){
            upSub -= 10;
            midSub -= 10;
            downSub -= 10;
        }

        contadorAnt = contador;

        if(upSub<minUpSub){
            upSub = maxUpSub;
            midSub = maxMidSub;
            downSub = maxDownSub;
        }
        if(upSub>maxUp){ 
            upSub = minUpSub;
            midSub = minMidSub;
            downSub = minDownSub;

        }
    }
  
}

void encoderButton()
{
    buttonState = digitalRead(boton);
    Serial.println(buttonState);
    
    if(buttonState != lastButtonState)
    {
        if(buttonState == LOW)
        {
            contador_button++;
        }
        delay(20);
    }
    lastButtonState = buttonState;

    if(contador_button % 2 != 0)
    {
        click = 1;
    }else
    {
        click = 0;
    }
}