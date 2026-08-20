// ESP8266 + Eye Blink Sensor + L298N + DC Motor + Buzzer
// Condition: if blink detected -> motor off, else -> motor on

const int IN1 = D1; // GPIO5
const int IN2 = D2; // GPIO4
const int ENA = D5; // GPIO14 (PWM)
const int BLINK_PIN = D6; // GPIO12 (sensor)
const int BUZZER = D7; // GPIO13 (optional buzzer)

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BLINK_PIN, INPUT); // use INPUT or INPUT_PULLUP depending on your sensor

  // Motor initially off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  Serial.println("System Ready: Motor control by Eye Blink sensor");
}

void loop() {
  int blinkState = digitalRead(BLINK_PIN); // HIGH = blink detected

  if (blinkState == HIGH) {
    // Blink detected → Motor OFF
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(BUZZER, HIGH); // buzzer ON
    Serial.println("Blink detected → Motor OFF");
  } else {
    // No blink → Motor ON
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 800); // speed (0–1023)
    digitalWrite(BUZZER, LOW); // buzzer OFF
    Serial.println("No blink → Motor ON");
  }

  delay(100);
}
