#include "MaxMatrix.h"
#include "avr/pgmspace.h"

#define CH_SIZE 10

PROGMEM const unsigned char CH[] = {
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
//4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
4, 8, B00010000, B00010000, B00010000, B00010000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};


PROGMEM const unsigned char Right[] = {
8,8,B00001000,B00000100,B00000010,B11111111,B00000010,B00000100,B00001000,B00000000,
};

PROGMEM const unsigned char Left[] = {
8,8,B00010000,B00100000,B01000000,B11111111,B01000000,B00100000,B00010000,B00000000,
};

PROGMEM const unsigned char Stop[] = {
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
};

PROGMEM const unsigned char Warning[] = {
8,8,B00011000,B00111100,B00111100,B00011100,B00011000,B00000000,B00011000,B00011000,
};

int data = 8;    // DIN pin of MAX7219 module
int load = 9;    // CS pin of MAX7219 module
int clock = 10;  // CLK pin of MAX7219 module

int maxInUse = 1;  //how many MAX7219 are connected

/*
int data = 8;    // DIN pin of MAX7219 module
int load = 9;    // CS pin of MAX7219 module
int clock = 10;  // CLK pin of MAX7219 module
 */

MaxMatrix m(data, load, clock, maxInUse); // define Library

byte buffer[CH_SIZE];

const int trig = 11;
const int echo = 12;
const int inter_time = 1000;
int time = 0;

void setup(){
  m.init(); // module MAX7219
  m.setIntensity(0); // LED Intensity 0-15
  Serial.begin(38400);
  pinMode(2, INPUT);  // left
  pinMode(3, INPUT);  // center
  pinMode(4, INPUT);  // right
  pinMode(5, INPUT);  // detect human
}

char string1[] = "  ";  // Scrolling Text
int left;
int center;
int right;
int state; // 0: stop, 1: right, 2: left
int human;
int object;
int preState = 0;
byte c;




void loop(){
  left = digitalRead(2);
  center = digitalRead(3);
  right = digitalRead(4);
  human = digitalRead(5);
  Serial.print("human: ");
  Serial.println(human);  
  delay(10);  


  // button
  if (!center || !left || !right ){
    if (center == 0 ){  // '0' is pressed
      state = 0;
    }
    else if (left == 0 ){  // '0' is pressed
      state = 2;
    }
    else if (right == 0){
      state = 1;
    }
  }else{
    state = preState;
  }

  if(state == 0){
    for (int c=0; c<sizeof(Stop)/CH_SIZE; c++)
    {
      memcpy_P(buffer, Stop + CH_SIZE*c, CH_SIZE);
      m.writeSprite(0, 0, buffer);
      m.setColumn(0 + buffer[0], 0);
    }
  }
  else if(state == 1){
    for (int c=0; c<sizeof(Right)/CH_SIZE; c++)
    {
      memcpy_P(buffer, Right + CH_SIZE*c, CH_SIZE);
      m.writeSprite(0, 0, buffer);
      m.setColumn(0 + buffer[0], 0);
    }
  }
  else if(state == 2){ //left
    // sonar distance
    float duration, distance;
    digitalWrite(trig, HIGH);
    delayMicroseconds(500);
    digitalWrite(trig, LOW);
    duration = pulseIn (echo, HIGH);
    distance = (duration/2)/29;
    Serial.print("d = ");
    Serial.print(distance);
    Serial.println(" cm");
    if (distance < 150 && distance > 3 ){
      object = 1;
    }
    else{
      object = 0;
    }
    
    if(human || object){
      for (int c=0; c<sizeof(Warning)/CH_SIZE; c++)
      {
        memcpy_P(buffer, Warning + CH_SIZE*c, CH_SIZE);
        m.writeSprite(0, 0, buffer);
        m.setColumn(0 + buffer[0], 0);
      }
    }
    else{
      for (int c=0; c<sizeof(Left)/CH_SIZE; c++)
      {
        memcpy_P(buffer, Left + CH_SIZE*c, CH_SIZE);
        m.writeSprite(0, 0, buffer);
        m.setColumn(0 + buffer[0], 0);
      }
    }


  }
  delay(100);
  // reset to black
  for (int c=0; c<sizeof(Stop)/CH_SIZE; c++)
  {
    memcpy_P(buffer, Stop + CH_SIZE*c, CH_SIZE);
    m.writeSprite(0, 0, buffer);
    m.setColumn(0 + buffer[0], 0);
  }
  preState = state;
  Serial.println(state);
  delay(100);

  

  

}

// Put extracted character on Display
void printCharWithShift(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxInUse*8, 0, buffer);
  m.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i = 0; i < buffer[0]+1; i++) 
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}

// Extract characters from Scrolling text
void printStringWithShift(char* s, int shift_speed){
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

void printLED(char* CH){
  for (int c=0; c<sizeof(CH)/CH_SIZE; c++)
  {
    memcpy_P(buffer, CH + CH_SIZE*c, CH_SIZE);
    m.writeSprite(0, 0, buffer);
    m.setColumn(0 + buffer[0], 0);
    delay(1000);
  }
}

/*
    if (center == 0 ){  // '0' is pressed
      m.shiftLeft(false, true);
      for(int i=0; i<2; ++i){
        string1[i] = " ";
      }
      printStringWithShift(string1, 100);  // Send scrolling Text    
    }
    else if (left == 0 ){  // '0' is pressed
      m.shiftLeft(false, true);
      char str[] = "<-";
      for(int i=0; i<2; ++i){
        string1[i] = str[i];
      }
      printStringWithShift(string1, 100);  // Send scrolling Text    
    }
    else if (right == 0){
      m.shiftRight(false, true);
      char str[] = "->";
      for(int i=0; i<2; ++i){
        string1[i] = str[i];
      }
    }
 */
  
