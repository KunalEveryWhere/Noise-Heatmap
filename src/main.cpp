#include <Arduino.h>
#include <Wire.h>

 
const int sampleWindow = 50;                              // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
 
#define SENSOR_PIN 33

 
void setup ()  
{   
  pinMode (SENSOR_PIN, INPUT); // Set the signal pin as input  
  Serial.begin(115200);

  Serial.println("Sensor_RAW dB 3_Stage_Level");
}  
 
   
void loop ()  
{ 
   unsigned long startMillis= millis();                   // Start of sample window
   float peakToPeak = 0;                                  // peak-to-peak level
 
   unsigned int signalMax = 0;                            //minimum value
   unsigned int signalMin = 1024;                         //maximum value
 
                                                          // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(SENSOR_PIN);                    //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;                           // save just the min levels
         }
      }
   }
 
   peakToPeak = signalMax - signalMin;                    // max - min = peak-peak amplitude
   int db = map(peakToPeak,20,900,49.5,90);             //calibrate for deciBels
  
  //Writing Code: Raw Sensor Data \t dB Data \t 3-Stage Level Indicator

  Serial.print(analogRead(SENSOR_PIN)); Serial.print("     ");
  Serial.print(db); Serial.print("     ");
  if (db <= 60)
  {
    Serial.println("Quite");
  }
  else if (db > 60 && db<85)
  {
    Serial.println("Moderate");
  }
  else if (db>=85)
  {
    Serial.println("High");
  }
  
 
   delay(200);      // thingspeak needs minimum 15 sec delay between updates.
}