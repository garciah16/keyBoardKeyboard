#include "waves.h"

int key[] = {46, 44, 42, 40, 38, 36, 34, 32, 30};
int scanOut[] = {22, 24};
int freq[] = {221, 208, 196, 185, 174, 164, 155, 146, 138, 130, 122, 115, 109};

void setup() {
  for(int i = 0; i <13; i++)
  {
    pinMode(key[i], INPUT);
  }
  pinMode(scanOut[0], OUTPUT);
  pinMode(scanOut[1], OUTPUT);
  pinMode(26, OUTPUT);
  analogWriteResolution(12);
  analogReadResolution(12);
}

void loop() {

   
  while(true) //testing digital pins. why won't they work????
  {
    digitalWrite(26, LOW);
    delay(100);
    digitalWrite(26, HIGH);
    delay(100);
//   while(key[8] == HIGH)
//   {
//    playKey(221);
//   }
  }
  
  //go through our array of buttons
 digitalWrite(scanOut[0], HIGH);
 digitalWrite(scanOut[1], LOW);
 //scan through the keys and find one that is pressed
 for(int i = 1; i < 9; i++)
 {
   while(key[i] == HIGH)
   {
      if(i == 8)
      {
        playKey[0]; //special case where the wires don't match
      }
      else
      {
        playKey(i);
      }
   }
 }
 digitalWrite(scanOut[0], LOW);
 digitalWrite(scanOut[1], HIGH);
 for(int j = 0; j < 5; j++)
 {
   while(key[j] == HIGH)
   {
    playKey(j+8);
   }
 }
 
}


void playKey(float delayTime){
  int j = 0;
  for(int i=0; i<271; i++) { //
    analogWrite(DAC1, bassTable[i]);//sin table
    delayMicroseconds(delayTime); //determines the frequency of the sine wav
    i+=3;
  }
}


//end

