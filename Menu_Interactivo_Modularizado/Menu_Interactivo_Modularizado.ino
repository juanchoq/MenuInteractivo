#include "menu.h"
#include "operaciones.h"

char opcion;

void setup() {
  Serial.begin(9600);
  mostrarMenu();
}

void loop() {
  if (Serial.available() > 0) {
    opcion = Serial.readStringUntil('\n').charAt(0);
    procesarOpcion(opcion);
    mostrarMenu();
  }
}