//Get commands transiting from the broker and translate them into GPIO commands
#pragma once
class WiFiManager{
    public:
    WiFiManager();
    void WIFIConnect(const char* WIFI_SSID,const char* WIFI_PASSWORD);

};



