# Esp8266-Thingspeak
# ESP8266 ‑ DHT11 & MQ‑2 Gas Sensor → ThingSpeak Logger

Monitor ambient **temperature**, **humidity**, and **gas concentration** in real time and push the data to **ThingSpeak** for effortless visualization and analysis.  
This project is ideal for home‑automation dashboards, air‑quality stations, or quick IoT demos.

---

## ✨ Features
- **Wi‑Fi connectivity** via ESP8266 (NodeMCU / Wemos D1 mini, etc.)
- Reads **DHT11** temperature & humidity and **MQ‑2** gas sensor (LPG, smoke)
- Publishes three fields to **ThingSpeak** (free IoT cloud)
- 15‑second default update interval (configurable)
- Serial console output for local debugging

---

## 🛠️ Hardware Required

| Qty | Component                               | Notes                                   |
|-----|-----------------------------------------|-----------------------------------------|
| 1   | ESP8266 development board              | NodeMCU, Wemos D1 mini, or equivalent   |
| 1   | DHT11 temperature & humidity sensor    | Any breakout (3‑pin or 4‑pin)           |
| 1   | MQ‑2 gas sensor module                 | Analog pin output                       |
| 1   | Breadboard & jumper wires              | For quick prototyping                   |
| –   | 5 V USB power source                   | 500 mA or higher                        |

### Pin Connections

| ESP8266 Pin | Sensor Module | Function  |
|-------------|---------------|-----------|
| **D4**      | DHT11 **DATA**| Data line |
| **3V3**     | DHT11 **VCC** | +3.3 V    |
| **GND**     | DHT11 **GND** | Ground    |
| **A0**      | MQ‑2 **AO**   | Analog‑out|
| **5V**¹     | MQ‑2 **VCC**  | +5 V      |
| **GND**     | MQ‑2 **GND**  | Ground    |

> ¹ Most MQ‑2 modules work best at 5 V. NodeMCU’s “VU” pin delivers USB‑5 V; Wemos boards often label it “5V”.

---

## 📦 Library Dependencies

Install these libraries in **Arduino IDE** or **PlatformIO**:

| Library            | Author / Link                                     |
|--------------------|---------------------------------------------------|
| `ESP8266WiFi`      | Built‑in (board package)                          |
| `DHT sensor library` | Adafruit (v1.4.4 or later)                      |
| `ThingSpeak`       | MathWorks (v2.1.1 or later)                       |

---

## 🔧 Setup & Configuration

1. **Clone / Download** this repository.  
2. Open `esp8266_dht11_mq2_thingspeak.ino` in Arduino IDE.
3. In the sketch, **replace** the placeholders:
   ```cpp
   const char* ssid     = "YOUR_SSID";
   const char* password = "YOUR_PASSWORD";
   unsigned long channelID = YOUR_CHANNEL_ID;   // Numeric
   const char* apiKey   = "YOUR_WRITE_API_KEY";

   Select Board & Port

Tools → Board → “NodeMCU 1.0 (ESP‑12E)” (or your variant)

Tools → Port → COM‑port shown.

Compile & Upload.
The Serial Monitor (115200 baud) should show connection progress and sensor values.

ThingSpeak Dashboard
Log in to ThingSpeak → Channels → My Channels → New Channel.
Enable Field 1 (Temperature °C), Field 2 (Humidity %), Field 3 (Gas Value).
Copy the Channel ID and Write API Key into the sketch.
Charts appear automatically after data starts flowing.
