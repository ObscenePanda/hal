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
	int verify_connection_ready();

  public:       
    WiFiStream();
    
	/* dynamic IP (DHCP) configurations */
	
	//OPEN networks
    int begin(char *ssid, uint16_t port);
	
	//WEP-encrypted networks
    int begin(char *ssid, uint8_t key_idx, const char *key, uint16_t port);
	
	//WPA-encrypted networks
    int begin(char *ssid, const char *passphrase, uint16_t port);
	
	/* static IP configurations */

    //OPEN networks with static IP
    int begin(char *mac_address, IPAddress local_ip, uint16_t port);
	
	//WEP-encrypted networks with static IP
    int begin(char *ssid, IPAddress local_ip, uint8_t key_idx, const char *key, uint16_t port);
	
	//WPA-encrypted networks with static IP
	int begin(char *ssid, IPAddress local_ip, const char *passphrase, uint16_t port);
	
	// allows another way to configure a static IP before begin is called
	void config(IPAddress local_ip);

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
