#include <Arduino.h>

/*  Codificador rotativo Keyes KY-040
 *  ( KY-007 para algunos vendedores )
 *  Prueba de conteo, direccion y  pulsador
 *  No se filtra los ruidos de contacto
 */
 
 #define salidaA 9
 #define salidaB 2
 #define boton 12
  
 int contador = 0; 
 int estadoA;
 int estadoPrevioA;  
 void setup() { 
   pinMode (salidaA,INPUT); // pin 2 
   pinMode (salidaB,INPUT); // pin 3
   // el pulsador debe ser polarizado a valor ALTO
   pinMode (boton, INPUT_PULLUP);
   
   Serial.begin (9600);
   // Lee el estado inicial de la salida A
   estadoPrevioA = digitalRead(salidaA);   
 } 
 void loop() 
 {
   // Lee el estado de la salida A
   estadoA = digitalRead(salidaA);
   // Si el estado previo de la salida A era otro
   // significa que se ha producido un pulso
   if (estadoA != estadoPrevioA){     
     // Si el estado de salida B es diferente del estado
     // de salida A el codificador esta girando a la derecha
     if (digitalRead(salidaB) != estadoA) { 
       contador ++;
     } else {
       contador --;
     }
     Serial.print("Posición: ");
     Serial.println(contador);
   } 
   // actualiza el estado guardado
   estadoPrevioA = estadoA;

  bool Bot = digitalRead(boton);
  //Serial.print(B);
   if (!Bot) // si se pulsa el boton su valor va a BAJO
    { 
        String respuesta = "Boton pulsado: Contador a " + contador;
        Serial.println(respuesta);
      contador = 0 ;
      delay(300);
    }
 }