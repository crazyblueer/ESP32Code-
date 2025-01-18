#define BLYNK_TEMPLATE_ID "TMPL6rC1K0N6h"
#define BLYNK_TEMPLATE_NAME "ESP Device"
#define BLYNK_AUTH_TOKEN "CJxP9_qYszfF6my-LmGA023V84QUW4fJ"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
#define relayPin1 2
#define servoPin 22
#define RELAY1 V0
#define SERVO V1
Servo myservo;



void setup(){
  Serial.begin(9600);
  pinMode(relayPin1,OUTPUT);
  myservo.attach(servoPin, 500, 2400);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}
BLYNK_WRITE(SERVO){
  int p = param.asInt();
  myservo.write(p);
  if (p>90){
      digitalWrite(relayPin1,HIGH);

   Blynk.virtualWrite(RELAY1, 1);
}
else{
   digitalWrite(relayPin1,LOW);

   Blynk.virtualWrite(RELAY1, 0);
}
  }



void loop(){
  Blynk.run();
}
