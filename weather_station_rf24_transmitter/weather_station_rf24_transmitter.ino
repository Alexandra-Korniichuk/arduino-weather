/*
Transmitter Code
*                
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
* 
* Library: Adafruit/DHT11/22, https://github.com/adafruit/DHT-sensor-library
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>

#define DHTPIN 4 //Arduino 4 Digital pin -> DHT11/22 Signal pin 

DHT dht(DHTPIN, DHT11);    //Use this if you have DHT11
//DHT dht(DHTPIN, DHT22); // Use this if you have DHT22

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  radio.begin();
  dht.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  char text[100];
  delay(2000);                 // 2 sec of delay
  int h = dht.readHumidity(); //Measure humidity
  int t = dht.readTemperature(); //Measure temperarure
  if (h ==0 && t==0) {  // If can't read data from sensor(temperarute and humidity should be equal 0) send error
    const char error[] = "Can't read from sensor";
    radio.write(&error, sizeof(error));
    delay(2000);
  }else{      // Else send information about humidity and temperature with 1 sec of delay
    String str1 = "Humidity: ";
    str1 += h;
    str1.toCharArray(text,100);
    radio.write(&text, sizeof(text));
    delay(1000);
    
    String str2 = "Temperature: ";
    str2 += t;
    str2.toCharArray(text,100);
    radio.write(&text, sizeof(text));
    delay(1000);}
}
