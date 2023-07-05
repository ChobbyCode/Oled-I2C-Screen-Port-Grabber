#include <Wire.h>

void setup()

{
  Serial.begin (9600);
   while (!Serial)
    {
    }

  Serial.println(); //Acts as break
  Serial.println("Getting I2C port...");
  Serial.println("If this takes longer than 10 seconds make sure your Arduino & Screen is connected correctly");
  byte count = 0;
  pinMode(13,OUTPUT); 
  digitalWrite(13,HIGH);
  Wire.begin();
  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1); 
      } 
  } 
  Serial.println ("Complete.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
} 

void loop() {}
