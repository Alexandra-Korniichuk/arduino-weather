# :zap: arduino-weather :zap:

## Description

This is simple Arduino weather station that would:
- get humidity and temperature data from sensor
- send data from sensor to server

## ToDo

- [x] Receive data from sensor to Arduino Nano
- [x] Connect Arduino Nano with Arduino Uno by using NRF24L01+ modules
- [x] Send data about temperature and humidity from Arduino Nano to Arduino Uno
- [ ] Make Arduino Nano to get power from sun battery (list of hard ware would be updated)
- [ ] Send data from Arduino Uno to server
- [ ] Collect data on server and make data visualisation

## Hardware

For this project I would use following hardware:
- Arduino Nano (for trasmitter)
- Arduino Uno (for receiver)
- **DHT22** sensor (Supply Voltage: 3.3V ~ 6V, Temperature range :-40°C ~ 80°C °C error of ± 2 °C, Humidity :0-100% RH ± 5% RH error, Interface: Digital) or DHT11 (Supply Voltage: +5 V, Temperature range :0-50 °C error of ± 2 °C, Humidity :20-90% RH ± 5% RH error, Interface: Digital)
- Two NRF24L01+ wireless transceiver modules
- Some wires to connect all together
- Breadboard

## Software

- Arduino IDE

## How to connect

![alt text](https://github.com/Alexandra-Korniichuk/arduino-weather/blob/master/fritzing_img/trasmitter-receiver-img_bb.jpg?raw=true)



