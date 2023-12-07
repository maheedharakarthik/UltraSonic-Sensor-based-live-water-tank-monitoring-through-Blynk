#define BLYNK_TEMPLATE_ID "TMPL361ljD3yn"
#define BLYNK_TEMPLATE_NAME "IOT"
#define BLYNK_AUTH_TOKEN "Zr8bxbBmwKDUxkMYKMKrmkqvqjuAq0KD"
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define trig D5   // Trig pin
#define echo D6   // echo pin
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Karthik";
char pass[] = "eswar@12345";
int depth =20;

BlynkTimer timer;
 
void waterlevel()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  long level= depth-cm;
  if (level<0)
  level=0;
  level = map(level,0,depth-3,0,100);
  Blynk.virtualWrite(V1, level);
}
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, waterlevel);
  
}
void loop()
{
 
  Blynk.run();
  timer.run();
  }