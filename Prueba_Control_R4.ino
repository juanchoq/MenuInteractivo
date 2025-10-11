#include <ESP8266WiFi.h>
//#include <ESP8266Servo.h>
#include <Servo.h>

// 🔹 Pines del motor y servo
int AIN1 = 0;   // GPIO0 - motor dirección
int AIN2 = 2;   // GPIO2 - motor dirección
Servo servoMotor;

WiFiServer server(80);

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  servoMotor.attach(3); // GPIO3 - señal servo

  //Serial.begin(9600);

  // 🔹 Configurar ESP8266 como Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP("Control-Motor", "12345678"); // SSID y contraseña

  Serial.println("✅ Punto de acceso creado");
  Serial.print("🌐 IP del ESP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;
  while (!client.available()) delay(1);

  String request = client.readStringUntil('\r');
  client.flush();

  // 🔹 Control del motor
  if (request.indexOf("/adelante") != -1) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  if (request.indexOf("/atras") != -1) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }
  if (request.indexOf("/stop") != -1) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }

  // 🔹 Control del servo
  if (request.indexOf("/servo/") != -1) {
    int pos = request.substring(request.indexOf("/servo/") + 7).toInt();
    servoMotor.write(pos);
  }

  // 🔹 Interfaz web HTML
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println(R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Control Motor y Servo</title>
  <style>
    body { background:#101820; color:#F2AA4C; font-family:Arial,sans-serif; text-align:center; margin-top:40px; }
    h1 { font-size:28px; margin-bottom:20px; }
    button { background:#F2AA4C; color:#101820; border:none; padding:15px 30px; margin:10px; font-size:18px; border-radius:12px; cursor:pointer; transition:0.2s; }
    button:hover { background:#FFD580; }
    .slider { width:70%; margin-top:25px; }
    .servo-label { font-size:18px; margin-top:15px; }
  </style>
</head>
<body>
  <h1>🚀 Control Motor y Servo</h1>
  <div>
    <button onclick="sendCmd('adelante')">⬆️ Adelante</button>
    <button onclick="sendCmd('stop')">⏹️ Detener</button>
    <button onclick="sendCmd('atras')">⬇️ Atrás</button>
  </div>
  <div class="servo-label">Ángulo del Servo: <span id="servoValue">90</span>°</div>
  <input type="range" min="0" max="180" value="90" class="slider" id="servoSlider" 
         oninput="updateServo(this.value)">
  <script>
    function sendCmd(cmd){ fetch('/'+cmd); }
    function updateServo(val){ document.getElementById('servoValue').innerText=val; fetch('/servo/'+val); }
  </script>
</body>
</html>
)rawliteral");
  delay(1);
}
