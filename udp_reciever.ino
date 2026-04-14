#include <WiFi.h>
#include <WiFiUdp.h>

// 🔥 WiFi credentials
const char* ssid = "WiFi Name";
const char* password = "WiFi Password";

// 🔥 UDP setup
WiFiUDP udp;
char packetBuffer[255];
const int udpPort = 4210;

// 🔥 DAC pin
const int dacPin = 25;

// 🔥 Control variable
int currentX = 0;

void setup() {
  Serial.begin(115200);

  // 🔥 Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Connected!");
  Serial.print("ESP IP: ");
  Serial.println(WiFi.localIP());

  // 🔥 Start UDP
  udp.begin(udpPort);
  Serial.println("UDP listening...");
}

void loop() {

  // 🔥 Check for incoming UDP packet
  int packetSize = udp.parsePacket();

  if (packetSize) {
    int len = udp.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len] = 0;

    String msg = String(packetBuffer);

    // 🔥 Parse X value
    if (msg.startsWith("X:")) {
      currentX = msg.substring(2).toInt();
    }
  }

  // 🔥 Map to DAC (0–255)
  int dacValue = map(currentX, -127, 127, 0, 255);

  // 🔥 Output to DAC pin
  dacWrite(dacPin, dacValue);

  // 🔥 Debug output
  Serial.print("X: ");
  Serial.print(currentX);
  Serial.print(" | DAC: ");
  Serial.println(dacValue);

  delay(10);
}
