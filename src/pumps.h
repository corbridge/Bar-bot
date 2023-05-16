#include <Arduino.h>
#include "encoder.h"

int timeP1;
int timeP2;
int timeP3;
int timeP4;
int timeP5;
int timePumps[5];
int timeMax = 0;
int Pumps = 0;

int stateP1 = 0;
int stateP2 = 0;
int stateP3 = 0;
int stateP4 = 0;
int stateP5 = 0;

#define motor_1 3
#define motor_2 4
#define motor_3 5
#define motor_4 6
#define motor_5 7

#define n_pumps 5
#define n_drinks 8

/*
                        bebida------>[bomba1,bomba2,bomba3,bomba4,bomba5]
                        1ra bomba = tequila
*/
float timeDrinks[n_drinks][n_pumps] = {{3,0,0,0,0},
                                       {0,3,0,0,0},
                                       {0,0,3,0,0},
                                       {0,0,0,3,0},
                                       {0,0,0,0,3},
                                       {0,0,0,3,0},
                                       {0,0,3,0,0},
                                       {3,3,3,3,3}};

//1 segundo equivale aprox a 20 ml, una vez seteada la maquina

void pumpsSetup()
{
    pinMode(motor_1, OUTPUT);
    pinMode(motor_2, OUTPUT);
    pinMode(motor_3, OUTPUT);
    pinMode(motor_4, OUTPUT);
    pinMode(motor_5, OUTPUT);
}

void pumpsActivation(int up, int page){
    //Recolectamos el tiempo de cada bomba dentro de un vector
    int bebida = (up/10)-2;
    if(page == 1){
        bebida += 4;
    }
    for(int i=0;i<5;i++){
        timePumps[i] = timeDrinks[bebida][i]*1000.0;
    }
    //Con el vector anterior, guardamos el tiempo de cada bomba en una variable
    timeP1 = timePumps[0];
    timeP2 = timePumps[1];
    timeP3 = timePumps[2];
    timeP4 = timePumps[3];
    timeP5 = timePumps[4];

    //Encontramos cual es el maximo tiempo que va a estar encendida la ultima bomba
    for(int i=0;i<5;i++){
        if(timePumps[i] > timeMax){
            timeMax = timePumps[i];
        }
    }

    //Encendemos bombas
    if(timeP1 != 0){
        digitalWrite(motor_1, HIGH);
        Serial.println("Bomba 1 Encendida");
        stateP1 = 1;
    }
    if(timeP2 != 0){
        digitalWrite(motor_2, HIGH);
        Serial.println("Bomba 2 Encendida");
        stateP2 = 1;
    }
    if(timeP3 != 0){
        digitalWrite(motor_3, HIGH);
        Serial.println("Bomba 3 Encendida");
        stateP3 = 1;
    }
    if(timeP4 != 0){
        digitalWrite(motor_4, HIGH);
        Serial.println("Bomba 4 Encendida");
        stateP4 = 1;
    }
    if(timeP5 != 0){
        digitalWrite(motor_5, HIGH);
        Serial.println("Bomba 5 Encendida");
        stateP5 = 1;
    }
    //Se activa la bandera de las bombas
    Pumps = 1;
}

void pumpsDeactivation(float volatile time){
    //Tomamos el tiempo actual
    float volatile time_drinks = millis();

    //Comparamos el tiempo actucal con el tiempo en el que se encendrieron las bombas y si es mayor al tiempo que debe estar encendida, se apaga dicha bomba
    if(time_drinks - time >= timeP1 and stateP1){
        digitalWrite(motor_1, LOW);
        Serial.println("Bomba 1 Apagada");
        stateP1 = 0;
    }
    if(time_drinks - time >= timeP2 and stateP2){
        digitalWrite(motor_2, LOW);
        Serial.println("Bomba 2 Apagada");
        stateP2 = 0;
    }
    if(time_drinks - time >= timeP3 and stateP3){
        digitalWrite(motor_3, LOW);
        Serial.println("Bomba 3 Apagada");
        stateP3 = 0;
    }
    if(time_drinks - time >= timeP4 and stateP4){
        digitalWrite(motor_4, LOW);
        Serial.println("Bomba 4 Apagada");
        stateP4 = 0;
    }
    if(time_drinks - time >= timeP5 and stateP5){
        digitalWrite(motor_5, LOW);
        Serial.println("Bomba 5 Apagada");
        stateP5 = 0;
    }

    //Si ya se apago la ultima bomba, desactivamos la bandera de las bombas y salimos de la pagina de filling
    if(time_drinks - time >= timeMax){
        Pumps = 0;
        page = 0;
    }

}