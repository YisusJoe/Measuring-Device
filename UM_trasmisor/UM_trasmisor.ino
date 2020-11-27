/* 1byte LORa SX1278 TRANSMITTER example.
/* Tutorial link: http://electronoobs.com/eng_arduino_tut97.php
 * Code: http://electronoobs.com/eng_arduino_tut97_code1.php
 * Scheamtic: http://electronoobs.com/eng_arduino_tut97_sch1.php
 * Youtube Channel: http://www.youtube/c/electronoobs   
 * 
  Module SX1278 // Arduino UNO/NANO    
    GND         ->   GND
    Vcc         ->   3.3V
    MISO        ->   D12
    MOSI        ->   D11     
    SLCK        ->   D13
    Nss         ->   D10
    Di00        ->   D2
    RST         ->   D9      
 */
#include <SPI.h>
#include <LoRa.h> //Download here: http://electronoobs.com/eng_arduino_LoRa_SX1278.php.php
int pot = A2;

void setup() {
    Serial.begin(9600);
    pinMode(pot,INPUT);
  
    while (!Serial);  
    Serial.println("LoRa Sender");
    if (!LoRa.begin(915E6)) { // or 915E6, the MHz speed of yout module
        Serial.println("Starting LoRa failed!");
        while (1);
    }
    Serial.println("LoRa Start");
}

void loop() {
    int val = map(analogRead(pot),0,1024,0,255);
    LoRa.beginPacket();  
    LoRa.print(val);
    LoRa.endPacket();
    delay(50);
}