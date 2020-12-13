#ifndef Esp_h
#define Esp_h

#include <Arduino.h>
#include <WiFi.h>

class Esp{
    public:
        Esp();
        ~Esp();

        void connectWifi(const char* ssid, const char* password);
       
        const char *getSsid();
        const char *getPassword();

        void setSsid(const char* ssidSet);
        void setPassword(const char* passwordSet);

    private:
        const char* ssid;
        const char* password;


    protected:



};



#endif