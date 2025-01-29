// Transmissor:
// Conecte o pino TX do Arduino ao pino RX do HC-12.

// Conecte o pino RX do Arduino ao pino TX do HC-12.

// Conecte o pino VCC do HC-12 ao 5V do Arduino.

// Conecte o pino GND do HC-12 ao GND do Arduino.

// Conecte um terminal do botão ao GND e o outro terminal a um pino digital (ex: D2) do Arduino.

// Conecte um resistor de 10kΩ entre o pino digital (D2) e o 5V (pull-up).

const int botaoPin = 2;  // Pino onde o botão está conectado
char letra = 'A';        // Letra que será enviada

void setup() {
  pinMode(botaoPin, INPUT_PULLUP);  // Configura o pino do botão como entrada com pull-up
  Serial.begin(9600);               // Inicia a comunicação serial com o HC-12
}

void loop() {
  // Verifica se o botão foi pressionado
  if (digitalRead(botaoPin) == LOW) {
    Serial.write(letra);  // Envia a letra via serial
    delay(500);           // Debounce do botão
  }
}