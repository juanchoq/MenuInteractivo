#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

void mostrarMenu();
void procesarOpcion(char op);
String solicitarNumero(String mensaje);
bool repetirOperacion(String pregunta);

#endif