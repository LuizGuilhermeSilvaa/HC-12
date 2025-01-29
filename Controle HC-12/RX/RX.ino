// Receptor:
// Conecte o pino TX do Arduino ao pino RX do HC-12.

// Conecte o pino RX do Arduino ao pino TX do HC-12.

// Conecte o pino VCC do HC-12 ao 5V do Arduino.

// Conecte o pino GND do HC-12 ao GND do Arduino.

void setup() {
  Serial.begin(9600);  // Inicia a comunicação serial com o HC-12
}

void loop() {
  // Verifica se há dados disponíveis para leitura
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Lê o caractere recebido
    // Exibe o caractere recebido no monitor serial
    Serial.print("Recebido: ");
    Serial.println(receivedChar);
  }
}