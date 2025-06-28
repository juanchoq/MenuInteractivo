#include "operaciones.h"
#include "menu.h"

void operacionSuma() {
  float num1, num2, resultado;
  String parametro;
  boolean continuar = true;
  
  while (continuar) {
    Serial.println("\n==== SUMA DE DOS NUMEROS ====");
    
    parametro = solicitarNumero("Ingrese el primer numero: ");
    num1 = parametro.toFloat();
    parametro = solicitarNumero("Ingrese el segundo numero:  ");
    num2 = parametro.toFloat();

    resultado = num1 + num2;
    Serial.println("Resultado: " + String(num1) + " + " + String(num2) + " = " + resultado);
    
    continuar = repetirOperacion("¿Desea realizar otra suma? (S/N):");
  }
}

void operacionResta() {
  float num1, num2, resultado;
  String parametro;
  boolean continuar = true;
  
  while (continuar) {
    Serial.println("\n==== RESTA DE DOS NUMEROS ====");
    
    parametro = solicitarNumero("Ingrese el primer numero: ");
    num1 = parametro.toFloat();
    parametro = solicitarNumero("Ingrese el segundo numero: ");
    num2 = parametro.toFloat();
    
    resultado = num1 - num2;
    Serial.println("Resultado: " + String(num1) + " - " + String(num2) + " = " + resultado);
    
    continuar = repetirOperacion("¿Desea realizar otra resta? (S/N):");
  }
}

void operacionMultiplicacion() {
  float num1, num2, resultado;
  String parametro;
  boolean continuar = true;
  
  while (continuar) {
    Serial.println("\n==== MULTIPLICACION DE DOS NUMEROS ====");
    
    parametro = solicitarNumero("Ingrese el primer numero: ");
    num1 = parametro.toFloat();
    parametro = solicitarNumero("Ingrese el segundo numero: ");
    num2 = parametro.toFloat();
    
    resultado = num1 * num2;
    Serial.println("Resultado: " + String(num1) + " * " + String(num2) + " = " + resultado);
    
    continuar = repetirOperacion("¿Desea realizar otra multiplicación? (S/N):");
  }
}

void operacionDivision() {
  float num1, num2, resultado;
  String parametro;
  boolean continuar = true;
  
  while (continuar) {
    Serial.println("\n==== DIVISION DE DOS NUMEROS ====");
    
    parametro = solicitarNumero("Ingrese el primer numero: ");
    num1 = parametro.toFloat();
    parametro = solicitarNumero("Ingrese el segundo numero: ");
    num2 = parametro.toFloat();
    
    if (num2 == 0) {
      Serial.println("Error: No se puede dividir por cero.");
    } else {
      resultado = num1 / num2;
      Serial.println("Resultado :" + String(num1) + " / " + String(num2) + " = " + resultado);
    }
    
    continuar = repetirOperacion("¿Desea realizar otra división? (S/N):");
  }
}

void operacionContador() {
  int limite;
  String parametro;
  boolean continuar = true;
  
  while (continuar) {
    Serial.println("\n==== CONTADOR DE NUMEROS ====");
    
    parametro = solicitarNumero("Ingrese el numero limite del contador:");
    limite = parametro.toInt();
    
    Serial.println("Contando desde 0 hasta " + String(limite));
    
    for (int i = 0; i < limite; i++) {
      Serial.print(String(i) + ", ");
    }
    Serial.print(limite);
    Serial.println();
    
    continuar = repetirOperacion("¿Desea realizar otro conteo? (S/N): ");
  }
}