// MQ-2 smoke detector for Arduinoo nano board only
const int sensorPin = A0;
const int buzzerPin = 2;
const int ledPin = 13;
const int  relayPin = 3;

int threshold = 300;

unsigned long lastPrint = 0;
const unsigned long printInterval = 1000;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(buzzerPin, LOW)
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
  delay(200);
  Serial.println("MQ-2 Smoke Detector Start");
  Serial.println("Please Allow");
}

void loop() {
  int raw = analogRead(sensorPin);

  if (raw > threshold) {
    digitalWrite(buzzerPin, HIGH)
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW)
    digitalWrite(ledPin, LOW);
    digitalWrite(relayPin, LOW);
  }

  if (millis() - lastPrint > printInterval) {
    lastPrint = millis();
    Serial.print("MQ-2 raw");
    Serial.print(raw);
    Serial.print("threhold :");
    Serial.println(threshold);
  }
  delay(100);
}
