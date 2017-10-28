
Attiny85 read ds18b20 sensor with OneWire and send data from I2C

Basically, this project reads ds18b20 data by onewire method and then send that data with I2C when master asked.

To be more specific, this program combines slave library and the ds18b20 library. When power enabled, attiny85 directly starts to wait command from the master. When write command detected attiny85 uses ds18b20 and onwire library to get data from the sensor. Then sends the data at the read command. 

You can use the Makefile without changing. Master.cpp file is not for the attiny. Raspberry pi used as a master device in this project. 

Slave libraries are used from the "https://github.com/eriksl/usitwislave". If you want the original ones you can access from here.

Onewire and ds18b20 libraries are used from the "https://github.com/Jacajack/avr-ds18b20". If you want the original ones you can access from here.
