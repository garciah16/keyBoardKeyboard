#include "waves.h"
#include "lfo.h"

//int key[] = {30, 32, 34, 36, 38, 40, 42, 44, 46};
int key[] = {30, 44, 42, 40, 38, 36, 34, 32, 46};
int scanOut[] = {22, 24};
int freq[] = {221, 208, 196, 185, 174, 164, 155, 146, 138, 130, 122, 115, 109};
int freq2[] = {444,419,395,373,352,333,313,295,279,263,248,234, 221};


int tremolo = 49;
boolean tremOn = false;

int octaver = 51;
boolean octaveDown = false;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i <9; i++)
  {
    pinMode(key[i], INPUT_PULLUP);
  }
  analogWriteResolution(12);
  analogReadResolution(12);
  attachInterrupt(digitalPinToInterrupt(tremolo), tremoloISR, RISING);
  attachInterrupt(digitalPinToInterrupt(octaver), octaveISR, RISING);
}

void loop() {
 
   
//go through our array of buttons
 delay(5);
 pinMode(scanOut[0], OUTPUT);
 pinMode(scanOut[1], INPUT_PULLUP);
 digitalWrite(scanOut[0], LOW);
 //scan through the keys and find one that is pressed
 for(int i = 1; i < 9; i++)
 {
   while(digitalRead(key[i]) == LOW)
   {
      if(i == 8)
      {
        playKey(0, i); //special case where the wires don't match
      }
      else
      {
        playKey(i, i);
      }
   }
 }
 delay(5);
 pinMode(scanOut[0], INPUT_PULLUP);
 pinMode(scanOut[1], OUTPUT);
 digitalWrite(scanOut[1], LOW);
 for(int j = 0; j < 5; j++)
 {
   while(digitalRead(key[j]) == LOW)
   {
    playKey(j+8, j);
   }
  
 }
}//end loop


void playKey(int freqNum, int keyNum){
  int k = 1;
  for (int j = 0; j< 499; j++){ 

    for(int i=0; i<271; i++) { //
      //multiplying my lfo creates the effect
      if(tremOn){
        analogWrite(DAC1, (int)(lfo[j]*bassTable[i]));//sin table
      }
      else{
        analogWrite(DAC1, (bassTable[i]));//sin table
      }
      
      if(octaveDown){
        delayMicroseconds(freq2[freqNum]); //determines the frequency of the sine wav
      }
      else
      {
        delayMicroseconds(freq[freqNum]);
      }
      i+=3;
    }
    if(digitalRead(key[keyNum]) != LOW) //don't continue note while key is not pressed
    {
      break;
    }
    if(octaveDown){
      j = j + (freq2[freqNum] / 10);
    }
    else{
      j = j + (freq[freqNum] / 10);
    }
  }
}

void tremoloISR()
{
  tremOn = !tremOn;
}

void octaveISR()
{
  octaveDown = !octaveDown;
}


//end

