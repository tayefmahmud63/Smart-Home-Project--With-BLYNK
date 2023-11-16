#define BLYNK_TEMPLATE_ID "TMPL6fRtIGAN9"
#define BLYNK_TEMPLATE_NAME "Smart Lab"
#define BLYNK_AUTH_TOKEN "TFGadnsFDoRvALViBCAnHiJLrfe-4aIA"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wifi Name"; // Change your Wifi/ Hotspot Name
char pass[] = "Wifi Password"; // Change your Wifi/ Hotspot Password

BlynkTimer timer;

#define MQ2 A0

int MQ2_Val = 0;




void setup() //Setup function - only function that is run in deep sleep mode
{
  Serial.begin(9600); //Start the serial output at 115,200 baud

  
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000);
  timer.setInterval(1000L, mySensor);
}

void loop() //Loop function
{
  Blynk.run();
  timer.run();
}

void mySensor()
{
  MQ2_Val = analogRead(MQ2);
  
  
  Blynk.virtualWrite(V0, MQ2_Val);
    
  Serial.print("MQ2 Level: ");
  Serial.println(MQ2_Val);
  
}
