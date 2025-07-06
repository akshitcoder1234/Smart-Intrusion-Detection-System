#include <WiFi.h>
#include <HTTPClient.h>

// WiFi Credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Webhook URL (replace with your own from webhook.site)
const char* webhookUrl = "[https://webhook.site/your-unique-url](https://webhook.site/your-unique-url)";

// Pin Definitions
const int pirPin = 15; // PIR Sensor output pin
const int ledPin = 12; // LED pin

// State Variables
int pirState = LOW;
int val = 0;

void setup() {
  Serial.begin(115200);

  // Initialize pins
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  val = digitalRead(pirPin); // Read PIR sensor state

  if (val == HIGH) { // If motion is detected
    if (pirState == LOW) {
      // Motion has just been detected
      Serial.println("Motion detected! Sending alert...");
      digitalWrite(ledPin, HIGH); // Turn on LED

      // Send alert to cloud
      sendAlert();

      pirState = HIGH;
      delay(5000); // Wait for 5 seconds to avoid multiple triggers
    }
  } else {
    if (pirState == HIGH) {
      // Motion has stopped
      Serial.println("Motion stopped.");
      digitalWrite(ledPin, LOW); // Turn off LED
      pirState = LOW;
    }
  }
  delay(100);
}

void sendAlert() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(webhookUrl);
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{\"message\":\"Unauthorized Access Detected!\", \"sensor\":\"PIR\", \"location\":\"Restricted Area\"}";

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected. Cannot send alert.");
  }
}