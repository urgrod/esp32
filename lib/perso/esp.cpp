#include <WiFi.h>
#include <Arduino.h>
#include "esp.h"

Esp::Esp(){}

Esp::~Esp(){}

void Esp::connectWifi(const char* ssid, const char* password){
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

const char * Esp::getPassword(){
    return password;
}  

const char* Esp::getSsid(){
    return ssid;
}

void Esp::setPassword(const char* passwordSet){
    password = passwordSet;
}

void Esp::setSsid(const char* ssidSet){
    ssid = ssidSet;
}