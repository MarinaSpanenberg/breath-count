#define flexPin A0
int ledPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
int numLeds = 10;

int flexReading;
int ledBrightness;

int breathCount = 0;
int threshold = 50; 
int lastState = 0;
unsigned long startTime;

void update_leds(int breathing) { //conforme a torcao do sensor flex, os leds acendem de forma que seu brilho varie (+ torcao = * brilho e vice-versa)
    if (breathing < 40) {
    ledBrightness = map(breathing, 80, 0, 0, 255);
    ledBrightness = constrain(ledBrightness, 0, 255);
    for (int i = 0; i < numLeds; i++) {
        analogWrite(ledPins[i], ledBrightness);
      }
  } else {
    for (int i = 0; i < numLeds; i++) {
        analogWrite(ledPins[i], 0);
    }    
  }  
}

void count_breaths(int breathing) { //contabiliza uma respiracao que o sensor ultrapassa o threshold caso seu estado atual seja diferente do anterior
  int state = breathing < threshold ? 1 : 0;

  if (state == 1 && lastState == 0) {
    breathCount++;
  }
  lastState = state;
}

void time_remaining(unsigned long hasPassed) { //conta e exibe na tela quantos segundos faltam até a próxima medicao
  int seconds = (60000 - hasPassed) / 1000;
  Serial.print("Tempo restante: ");
  Serial.print(seconds);
  Serial.println("s");
}

void check_RPM(unsigned long hasPassed) { //exibe na tela todas as respiracoes realizadas dentro do período de 1 minuto
  if (millis() - startTime >= 60000) {
    int rpm = breathCount;
    Serial.print("RPM: ");
    Serial.println(rpm);
    delay(5000);
    breathCount = 0;
    startTime = millis();
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  startTime = millis();
}

void loop() {
  flexReading = analogRead(flexPin);

  update_leds(flexReading);
  count_breaths(flexReading);

  unsigned long now = millis() - startTime;
  time_remaining(now);
  check_RPM(now);

  delay(100);
}