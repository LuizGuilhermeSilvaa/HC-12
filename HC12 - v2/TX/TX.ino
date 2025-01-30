const int numBotoes = 4;  // Número de botões
const int pinosBotoes[numBotoes] = {2, 3, 4, 5};  // Pinos dos botões
const int numeros[numBotoes] = {1, 2, 3, 4};  // Números correspondentes a cada botão
bool estadoAnterior[numBotoes] = {HIGH, HIGH, HIGH, HIGH};  // Estado anterior dos botões

void setup() {
  for (int i = 0; i < numBotoes; i++) {
    pinMode(pinosBotoes[i], INPUT_PULLUP);  // Configura os pinos dos botões como entrada com pull-up
  }
  Serial.begin(9600);  // Inicia a comunicação serial com o HC-12
}

void loop() {
  bool botaoPressionado[numBotoes] = {false, false, false, false};  // Armazena quais botões estão pressionados

  // Verifica o estado de todos os botões
  for (int i = 0; i < numBotoes; i++) {
    bool estadoAtual = digitalRead(pinosBotoes[i]);  // Lê o estado atual do botão

    // Verifica se o botão está pressionado
    if (estadoAtual == LOW) {
      botaoPressionado[i] = true;  // Marca o botão como pressionado
    }

    estadoAnterior[i] = estadoAtual;  // Atualiza o estado anterior do botão
  }

  // Calcula a soma dos números dos botões pressionados
  int soma = 0;
  for (int i = 0; i < numBotoes; i++) {
    if (botaoPressionado[i]) {
      soma += numeros[i];  // Soma os números correspondentes aos botões pressionados
    }
  }

  // Se houver pelo menos um botão pressionado, envia a soma
  if (soma > 0) {
    Serial.write(soma);  // Envia a soma como um valor numérico
  }

  delay(100);  // Pequeno delay para evitar envio excessivo de dados
}