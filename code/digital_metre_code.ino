#include <ESP8266WiFi.h>

const int trigPin = D1; //trig
const int echoPin = D2; //echo

long duration; //süre
float distance; //mesafe

void setup() {
  Serial.begin(115200);
  
  // Pin modları
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // TRIG pinini düşük seviyeye çek ve 2 mikrosaniye bekle
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // TRIG pinini yüksek seviyeye çek ve 10 mikrosaniye bekle
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Mesafeyi hesapla
  distance = (duration * 0.0343) / 2;
  
  Serial.print("Mesafe: ");
  Serial.print(distance, 2); //2 ondalıklı
  Serial.println(" cm");
}
