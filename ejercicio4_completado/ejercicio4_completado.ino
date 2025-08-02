// Pines analógicos (potenciómetros)
int potRojo = A0;
int potVerde = A1;
int potAzul = A2;

// Pines analògicos (salidas)
int led_rojo = 11;
int led_azul = 10;
int led_verde = 9;

// INTENSIDAD de colores 0-1023
int rojo = 0;
int verde = 0;
int azul = 0;

void setup() {
  // put your setup code here, to run once:

  // Configuracion de entradas
  pinMode(potRojo, INPUT);
  pinMode(potVerde, INPUT);
  pinMode(potAzul, INPUT);

  //Configuracion de salidas
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);


}

void loop() {
  //Leer potenciómetros valor inicial de las entradas: 1023 (LUZ BLANCA)
  rojo = analogRead(potRojo);
  verde = analogRead(potVerde);
  azul = analogRead(azul);

  // Mapeo de 0-1023 (rango de entradas analogicas) a 0-255 (rango de salidas analogicas)
  rojo = map(rojo, 0, 1023, 0, 255);
  verde = map(verde, 0, 1023, 0, 255);
  azul = map(azul, 0, 1023, 0, 255);

  // Prender Led RGB, establecer color
  analogWrite(led_rojo, rojo);
  analogWrite(led_verde, verde);
  analogWrite(led_azul, azul);


}







