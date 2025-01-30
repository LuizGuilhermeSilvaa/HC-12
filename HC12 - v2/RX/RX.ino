void setup() {
  Serial.begin(9600);  // Inicia a comunicação serial com o HC-12
}

void loop() {
  // Verifica se há dados disponíveis para leitura
  if (Serial.available() > 0) {
    int receivedNumber = Serial.read();  // Lê o número recebido
    // Exibe o número recebido no monitor serial
    Serial.print("Recebido: ");
    Serial.println(receivedNumber);
  }
}