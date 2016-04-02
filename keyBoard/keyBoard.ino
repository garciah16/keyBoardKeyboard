#include "waves.h"
#include "lfo.h"

const int key[] = {30, 44, 42, 40, 38, 36, 34, 32, 46}; //digital pins assigned to keys
const int scanOut[] = {22, 24}; //digital outputs for matrix scan
const int freq[] = {221, 208, 196, 185, 174, 164, 155, 146, 138, 130, 122, 115, 109}; //high octave delay times
const int freq2[] = {444,419,395,373,352,333,313,295,279,263,248,234, 221}; //low octave delay times

boolean playNote = true;

//tremolo btn pin number and boolean to tell when active
const int tremolo = 49;
boolean tremOn = false;

//tremolo rate button and int to tell the rate of tremolo effect
int tremRate = 10;
const int tremRateBtn = 47;

//octave btn pin number and boolean to tell when to switch octaves
const int octaver = 51;
boolean octaveDown = false;


void setup() {
  //Serial.begin(9600); //for printing
  
  //set up keyboard inputs
  for(int i = 0; i <9; i++)
  {
    pinMode(key[i], INPUT_PULLUP);
  }
  analogWriteResolution(12);
  analogReadResolution(12);
  
  //activate interrupts for control buttons
  //interrupts solve the timing issue
  attachInterrupt(digitalPinToInterrupt(tremolo), tremoloISR, RISING);
  attachInterrupt(digitalPinToInterrupt(octaver), octaveISR, RISING);
  attachInterrupt(digitalPinToInterrupt(tremRateBtn), tremRateISR, RISING);

}//end setup

void loop() {
 
 playNote = true;  
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
      if(i == 8) //special case where the wires don't match
      {
        if(tremOn)
        {
          playKeyTrem(0, i);
        }
        else
        {
          playKey(0, i); 
        }
      }
      else
      {
        if(tremOn)
        {
          playKeyTrem(i,i);
        }
        else
        {
          playKey(i, i);
        }
      }
   }
 }
 delay(5);
 //check the other part of the matrix
 pinMode(scanOut[0], INPUT_PULLUP);
 pinMode(scanOut[1], OUTPUT);
 digitalWrite(scanOut[1], LOW);
 for(int j = 0; j < 5; j++)
 {
   while(digitalRead(key[j]) == LOW)
   {
      if(tremOn)
      {
        playKeyTrem(j+8, j);
      }
      else
      {
        playKey(j+8, j);
      }
   }
  
 }
}//end loop

/**
 * this function generates tones
 * and applys effects to the tone generated
 */
void playKey(int freqNum, int keyNum)
{
  if(!playNote)
  {
    return;
  }
  for (int j = 0; j< 298; j++)
  { //loop for the envelope
    
  
    for(int i=0; i<199; i++) 
    { 
      analogWrite(DAC1, (int)(env1[j]*pianoTable[i]));//sin table
      
      if(octaveDown)
      {
          delayMicroseconds(freq2[freqNum]-2); //determines the frequency of the sine wav
      }
      else
      {
           delayMicroseconds(freq[freqNum]-2); //determines the frequency of the sine wav
      }
      i+=2; //for tuning the note to C scale
    }
    if(digitalRead(key[keyNum]) != LOW) //don't continue note while key is not pressed
    {
      playNote = true;
      analogWrite(DAC1, 4095);
      break;
    }
    if(octaveDown)
    {
      j = j + (freq2[freqNum] / 150);
    }
    else
    {
      j = j + (freq[freqNum] / 150);
    }
    if(j > 290)
    {
      playNote = false;
    }
  }
}//end playKey

/**
 * this function generates a tone and applies
 * the tremolo effect to modulate the amplitude
 */
void playKeyTrem(int freqNum, int keyNum)
{
  
   for (int j = 0; j< 499; j++){ 

    for(int i=0; i<199; i++) 
    { 
      //multiplying my lfo creates the effect
      
        analogWrite(DAC1, (int)(lfo[j]*pianoTable[i]));//sin table
     
      if(octaveDown)
      {        
          delayMicroseconds(freq2[freqNum]-2); 
          // -2 is to fix tuning problem in tremolo
      }
      else
      {
          delayMicroseconds(freq[freqNum]-2);
      }
      i+=2; //for tuning the note to C scale
    }
    if(digitalRead(key[keyNum]) != LOW) //don't continue note while key is not pressed
    {
      
      analogWrite(DAC1, 0);
      break;
    }
    if(octaveDown)
    {
      j = j + (freq2[freqNum] / tremRate);
    }
    else
    {
      j = j + (freq[freqNum] / tremRate);
    }
  }
}

/**
 * tremelo interrupt
 * toggle tremolo when button is pressed
 */
void tremoloISR()
{
  tremOn = !tremOn;
}

/**
 * tremolo rate interrupt
 * increase tremolo rate when button is pressed
 */
void tremRateISR()
{
  tremRate += 4;
  if(tremRate > 25)
  {
    tremRate = 2;
  }
}

/**
 * octave interrupt
 * toggle octave when button is pressed
 */
void octaveISR()
{
  octaveDown = !octaveDown;
}


//end

