const int sensorPin = A0;
const int buzzerPin = 2;
const int ledPin = 13;
const int relayPin = 3;      //for pump
const int sprayDuration = 5000; //water-spray-timer(millisec)

int threshold = 300;
bool spraying = false;
unsigned long sprayStartTime = 0;

unsigned long lastPrint = 0;
const unsigned long printInterval = 1000;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
  delay(2000);
  Serial.println("MQ-2 Smoke Detector Ready");
}

void loop() {
  int raw = analogRead(sensorPin);

  if (raw > threshold && !spraying) {
    // detected-smoke -> spray-water
    spraying = true;
    sprayStartTime = millis();

    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH); //turn-on the pump
    Serial.println("Smoke detected! Spraying water...");
  }

  // spray-water in time checker
  if (spraying && millis() - sprayStartTime >= sprayDuration) {
    spraying = false;
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(relayPin, LOW); //turn-off the pump
    Serial.println("Spray complete. System reset.");
  }

  if (millis() - lastPrint > printInterval) {
    lastPrint = millis();
    Serial.print("MQ-2 raw: ");
    Serial.print(raw);
    Serial.print("  threshold: ");
    Serial.println(threshold);
  }

  delay(100);
}
