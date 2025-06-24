#include <DHT.h>

#define FAN_PWM_PIN     23
#define DHT_PIN         4
#define BUTTON_PIN      2
#define LED_PIN         13

#define DHTTYPE DHT11
#define PWM_CHANNEL 0
#define PWM_FREQ 25000
#define PWM_RESOLUTION 8

DHT dht(DHT_PIN, DHTTYPE);

bool autoMode = true;
int pwmValue = 0;
bool buttonState = HIGH;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(115200);
  dht.begin();

  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(FAN_PWM_PIN, PWM_CHANNEL);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("System started. Waiting for sensor...");
  delay(2000);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && buttonState == HIGH) {
      autoMode = !autoMode;
      Serial.print("Mode toggled to: ");
      Serial.println(autoMode ? "AUTO" : "MANUAL");
    }
    buttonState = reading;
  }

  lastButtonState = reading;

  digitalWrite(LED_PIN, autoMode ? HIGH : LOW);

  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("DHT sensor read failed.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C");

    if (autoMode) {
      pwmValue = map(temp, 20, 40, 50, 255);
      pwmValue = constrain(pwmValue, 0, 255);
    } else {
      pwmValue = 128;
    }

    Serial.print("PWM Output: ");
    Serial.println(pwmValue);

    ledcWrite(PWM_CHANNEL, pwmValue);
  }

  delay(2000);
}