# Standard Firmata - Networking

Deploy Standard Firamta which uses a networking stream instead of the serial port.


## Installation

#### Option 1: (Best for unix/mac)
1. Install [PlatformIO](http://platformio.org/)
2. `git clone https://github.com/peterschwarz/standard-firmata-networking`
3. `git submodule init`
4. Customize the WiFi sketch as necessary to specify your SSID and encryption type, if necessary.
5. Build and upload to your device 
    
    ```
    platformio run --target upload
    ```
	
#### Option 2: (Best for Windows)
1. `git clone --recursive  https://github.com/peterschwarz/standard-firmata-networking.git`
2. Copy the "EthernetStream" and "WiFiStream" folders from \lib\ to your Arduino libraries directory. This is usually `%HOMEPATH%\Documents\Arduino\libraries`
3. Run the appropriate sketch in the Arduino IDE.
4. Customize the WiFi sketch as necessary to specify your SSID and encryption type, if necessary.
5. Upload to your device.

## Adding additional boards


Currently, the build supports the Arduino Uno.  If you'd like to add additional board targets,
see the PlatformIO [docs](http://docs.platformio.org/en/latest/platforms/index.html) and add
add your board. 
