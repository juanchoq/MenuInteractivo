#include "menu.h"
#include "operaciones.h"

void mostrarMenu() {
  Serial.println("\n===== MENU PRINCIPAL =====");
  Serial.println("1. Sumar dos numeros");
  Serial.println("2. Restar dos numeros");
  Serial.println("3. Multiplicar dos numeros");
  Serial.println("4. Dividir dos numeros");
  Serial.println("5. Generar contador de numeros");
  Serial.println("=========================");
  Serial.println("Seleccione una opcion (1-5):");
}

void procesarOpcion(char op) {
  Serial.println("Ha seleccionado la opcion " + String(op));
  switch (op) {
    case '1':
      operacionSuma();
      break;
    case '2':
      operacionResta();
      break;
    case '3':
      operacionMultiplicacion();
      break;
    case '4':
      operacionDivision();
      break;
    case '5':
      operacionContador();
      break;
    default:
      Serial.println("Opcion no valida. Intente nuevamente.");
      break;
  }
}

String solicitarNumero(String mensaje) {
  Serial.print(mensaje);
  while (true) {
    if (Serial.available() > 0) {
      String numero = Serial.readStringUntil('\n');
      Serial.println(numero);
      return numero;
    }
  }
}

bool repetirOperacion(String pregunta) {
  Serial.print(pregunta);
  while (!Serial.available()) { }
  String mensaje = Serial.readStringUntil('\n');
  Serial.println(mensaje);
  
  if (mensaje.charAt(0) == 'N' || mensaje.charAt(0) == 'n') {
    return false;
  }
  else {
    return true;
  }
}