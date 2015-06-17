#ifndef WIFI_STREAM_H
#define WIFI_STREAM_H

#include <inttypes.h>
#include <Stream.h>
#include <SPI.h>
#include <WiFi.h>


class WiFiStream : public Stream
{
  private:
    WiFiServer server = WiFiServer(23);
    WiFiClient client;
    
    int connect_client();

  public:       
    WiFiStream();
    
    // begin with dynamic IP:port (DHCP)
    int begin(char *ssid, uint16_t port);

    // begin with static IP:port
    void begin(char *mac_address, IPAddress local_ip, uint16_t port);

    // get DCHP IP
    IPAddress localIP();

    // overriden Stream class functions
    virtual size_t write(uint8_t byte);
    virtual int read();
    virtual int available();
    virtual void flush();
    virtual int peek();
};

#endif
