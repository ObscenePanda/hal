/******************************************************************************
 * Includes
 ******************************************************************************/

#include "WiFiStream.h"


/******************************************************************************
 * Definitions
 ******************************************************************************/

 WiFiStream::WiFiStream()
 {
    
 }

int WiFiStream::begin(char *ssid, uint16_t port)
{
	if( WiFi.status() == WL_NO_SHIELD ) return 0;
	if( WiFi.status() != WL_CONNECTED )
	{
		int result = WiFi.begin( ssid );
		if( result == 0 )
			return 0;

		delay( 10000 );
		server = WiFiServer( port );
		server.begin();
		return result;
	}
	return 0;
}

void WiFiStream::begin(char *ssid, IPAddress local_ip, uint16_t port)
{
	WiFi.config( local_ip );
	WiFi.begin( ssid );
    server = WiFiServer(port);
    server.begin();
}

IPAddress WiFiStream::localIP()
{
    return WiFi.localIP();
}

int WiFiStream::connect_client() 
{
    if (!(client && client.connected()))
	{
        WiFiClient newClient = server.available();
        if (!newClient)
		{
            return 0;
		}

        client = newClient;
    }
    return 1;
}

int WiFiStream::available()
{
    return connect_client() ? client.available() : 0;
}

int WiFiStream::read()
{
    return connect_client() ? client.read() : 0;
}

void WiFiStream::flush() {
    if (client) client.flush();
}

int WiFiStream::peek() {
    return client ? client.peek(): 0;
}

size_t WiFiStream::write(uint8_t outgoingByte) {  
    if(connect_client()) client.write(outgoingByte);
}
