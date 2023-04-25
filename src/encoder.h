#include <Arduino.h>

#define salidaA 9
#define salidaB 2
#define boton 12

int contador = 0; 
int estadoA;
int estadoPrevioA;

void encoderSetup()
{
    pinMode (salidaA,INPUT);  
    pinMode (salidaB,INPUT);
    pinMode (boton, INPUT_PULLUP);

    Serial.begin (9600);
    estadoPrevioA = digitalRead(salidaA); 
}

int encoder()
{
    estadoA = digitalRead(salidaA);
    if (estadoA != estadoPrevioA){     
    if (digitalRead(salidaB) != estadoA) { 
    contador ++;
    } else {
        contador --;
        }
    } 
    estadoPrevioA = estadoA;
    return contador;
}