#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

#define DHTPIN D4  // Change according to your ESP8266 board
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int MQ2_PIN = A0;  // MQ2 Gas Sensor analog pin

const char* ssid = "sai";
const char* password = "12345678";
unsigned long channelID = 2891146;
const char* apiKey = "516VAT80RND30ROQ";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int gasValue = analogRead(MQ2_PIN);  // Read MQ2 sensor

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" Humidity: "); Serial.print(hum);
  Serial.print(" Gas Level: "); Serial.println(gasValue);

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, hum);
  ThingSpeak.setField(3, gasValue);
  ThingSpeak.writeFields(channelID, apiKey);

  delay(15000); // Send data every 15 seconds
}

