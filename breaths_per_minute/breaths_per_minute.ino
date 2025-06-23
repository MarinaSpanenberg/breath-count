#define flexPin A0
int ledPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
int numLeds = 10;

int flexReading;
int ledBrightness;

int breathCount = 0;
int threshold = 50; 
int lastState = 0;
unsigned long startTime;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  startTime = millis();
}

void loop() {
  flexReading = analogRead(flexPin);
//  Serial.print("Leitura do sensor: ");
//  Serial.println(flexReading);
  if (flexReading < 60) {
    ledBrightness = map(flexReading, 80, 0, 0, 255);
    ledBrightness = constrain(ledBrightness, 0, 255);
    for (int i = 0; i < numLeds; i++) {
        analogWrite(ledPins[i], ledBrightness);
      }
  } else {
    for (int i = 0; i < numLeds; i++) {
        analogWrite(ledPins[i], 0);
    }    
  }  
  
  int state = flexReading < threshold ? 1 : 0;

  if (state == 1 && lastState == 0) {
    breathCount++;
  }
  lastState = state;

  if (millis() - startTime >= 60000) {
    int rpm = breathCount;
    Serial.print("Respirações por minuto (RPM): ");
    Serial.println(rpm);
    breathCount = 0;
    startTime = millis();
  }
  

  delay(100);
}
