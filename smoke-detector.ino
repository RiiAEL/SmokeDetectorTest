// MQ-2 smoke detector for Arduinoo nano board only
const int sensorPin = A0;     //MQ-2 A0
const int buzzerPin = 2;      //activeBuzzer
const int ledPin = 13;        //LED
const relayPin = 3;           //relay

int threshold = 300;          //standard setting - should calobrate

unsigned long = lastPrint = 0;
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
  Serial.println("MQ-2 Smoke Detector Start")
  Serial.println("Please Allow")
}

void loop() {
  int raw = analogRead(sensorPin);    //0-1023

  //if you want to convert to pressure : float voltage raw * (5.0 / 1023.0);

  if (raw > threshold) {
    //alarm
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
    Serial.println(threhold);
  }
  delay(100);
}
