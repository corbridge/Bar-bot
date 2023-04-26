#include <Arduino.h>

#define salidaA 9
#define salidaB 2
#define boton 12

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

int up = 20;
int mid = 25;
int down = 30;

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

    if(up > maxUp){
        up = minUp;
        mid = minMid;
        down = minDown;
    }
    if(up < minUp){
        up = maxUp;
        mid = maxMid;
        down = maxDown;
    }
}