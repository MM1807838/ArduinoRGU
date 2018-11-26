#include <Mouse.h>
#include <toneAC.h>
#include <Timer.h>
#define  a3f    208     // 208 Hz
#define  b3f    233     // 233 Hz
#define  b3     247     // 247 Hz
#define  c4     261     // 261 Hz MIDDLE C
#define  c4s    277     // 277 Hz
#define  e4f    311     // 311 Hz    
#define  f4     349     // 349 Hz 
#define  a4f    415     // 415 Hz  
#define  b4f    466     // 466 Hz 
#define  b4     493     // 493 Hz 
#define  c5     523     // 523 Hz 
#define  c5s    554     // 554 Hz
#define  e5f    622     // 622 Hz  
#define  f5     698     // 698 Hz 
#define  f5s    740     // 740 Hz
#define  a5f    831     // 831 Hz 

#define rest    -1

const int buzzerPin = 9;
const int trigPin = 8;
const int echoPin = 7;

float duration, distance;

// buzzer variables
Timer t;
int timer = 100;
int melody[] =
{ rest, c4s, c4s, c4s, c4s, e4f, rest, c4, b3f, a3f,
  rest, b3f, b3f, c4, c4s, a3f, a4f, a4f, e4f,
  rest, b3f, b3f, c4, c4s, b3f, c4s, e4f, rest, c4, b3f, b3f, a3f,
  rest, b3f, b3f, c4, c4s, a3f, a3f, e4f, e4f, e4f, f4, e4f,
  c4s, e4f, f4, c4s, e4f, e4f, e4f, f4, e4f, a3f,
  rest, b3f, c4, c4s, a3f, rest, e4f, f4, e4f
};

int noteDurations[] =
{ 2, 1, 1, 1, 1, 2, 1, 1, 1, 5,
  1, 1, 1, 1, 3, 1, 2, 1, 5,
  1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3,
  1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4,
  5, 1, 1, 1, 1, 1, 1, 1, 2, 2,
  2, 1, 1, 1, 3, 1, 1, 1, 3
};
int melodyPosition = 0;

// volume is a whole number from range 0 - 10
int volume = 0;
int maximumRange = 100;

//buzzer song
int beatLength = 100;
float beatseparationconstant = 0.3;
int distortion = 50;

// timer event IDs incase needed
int afterEvent;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
  afterEvent = t.after(100, *playBuzzer, 0);
}

void loop()
{
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);


  // should produce a tone whose volume is determined by distance
  if (distance > maximumRange){
    volume = 0;
  } else {
    volume = (1 - (distance / maximumRange)) * 10;
  }

  playBuzzer();

  t.update();
}

void playBuzzer()
{
    toneAC(melody[melodyPosition], volume, noteDurations[melodyPosition] * beatLength, true);

    int timeToWait = noteDurations[melodyPosition] * beatLength + noteDurations[melodyPosition] * beatLength * beatseparationconstant;

    melodyPosition = (melodyPosition + 1) % (sizeof(melody) / sizeof(int));

    afterEvent = t.after(timeToWait, *playBuzzer, 0);

}
