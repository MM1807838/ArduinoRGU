#include <Mouse.h>
#include <toneAC.h>
#include <Timer.h>

const int trigpin= 8;
const int echopin= 7;
long duration;
int distance;

// buzzer variables
Timer t;
int melody[] = { 262, 196, 196, 220, 196, 0, 247, 262 };
int noteDurations[] = { 400, 800, 800, 400, 400, 400, 400, 400 };
int melodyPosition = 0;

// volume is a whole number from range 0 - 10
int volume = 0;
int maximumRange = 400;

// timer event IDs incase needed
int afterEvent;

void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);

  afterEvent = t.after(1000, *playBuzzer, melodyPosition);
}

void loop()
{
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);


  // should produce a tone whose volume is determined by distance
  if (distance > maximumRange){
    volume = 0;
  } else {
    volume = (1 - (distance / maximumRange)) * 10;
  }

}

void playBuzzer()
{
  toneAC(melody[melodyPosition], volume, noteDurations[melodyPosition], true);

  melodyPosition = (melodyPosition + 1) % (sizeof(melody) / sizeof(int));

  afterEvent = t.after(noteDurations[melodyPosition], *playBuzzer, melodyPosition);
}
