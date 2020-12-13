#include <esp.h>
#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"


#define DHT11_PIN 15
#define DHTTYPE DHT11

const char* ssid = "Livebox-b1b0";
const char* password = "0123456789";

unsigned long channelNumber = 1234590;
String apiKey = "EBWVQ2QXBUGMPHZS";
const char* host = "api.thingspeak.com";

float T, H;
DHT dht(DHT11_PIN, DHTTYPE);
WiFiClient client;


void connectWifi(){
  
  WiFi.begin(ssid, password);
  Serial.println("Tentative de connexion ...");
  Serial.println(ssid);
  Serial.println(password);

  while(WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(100);
  }
  Serial.println("\n");
  Serial.println("Connexion etablie");
  Serial.println("Adresse IP:");
  Serial.println(WiFi.localIP());
}

void tempHum(){
  H = dht.readHumidity();
  T = dht.readTemperature();
  Serial.println("t:");
  Serial.println(T);
  Serial.println("h:");
  Serial.println(H);
}

void setup(){
  Serial.begin(9600);

  dht.begin();
  connectWifi();
  //esp.connectWifi(ssid, password);
  client.connect(host, 80);
}

void loop(){
  client.connect(host, 80);
  tempHum();
  client.print("GET https://api.thingspeak.com/update?api_key=EBWVQ2QXBUGMPHZS&field1=");
  client.print(String(T));
  client.print("&field2=");
  client.print(String(H));
  client.print("HTTP/1.0\r\nHost: api.thingspeak.com\r\n\r\n");
  delay(10000);
}