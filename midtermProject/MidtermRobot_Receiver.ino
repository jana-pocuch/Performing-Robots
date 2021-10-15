/*
   Example using the nRF24L01 radio module to communicate
   between two Arduinos,
   the transmitter is connected to some pushbuttons
   the receiver is connected to a motor driver
*/

// Pin usage
// nRF24L01 uses SPI which is fixed on pins 11, 12, and 13.
// It also requires two other signals
// (CE = Chip Enable, CSN = Chip Select Not)
// Which can be any pins:

const int CEPIN = 9;
const int CSNPIN = 10;

// In summary,
// nRF 24L01 pin    Arduino pin   name
//          1                     GND
//          2                     3.3V
//          3             9       CE
//          4             10      CSN
//          5             13      SCLK
//          6             11      MOSI/COPI
//          7             12      MISO/CIPO

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);  // CE, CSN


 
// Byte of array representing the address.
// This is the address where we will send the data.
// This should be same on the receiving side.
const byte address[6] = "00001";

// Motor controller pins
const int rightDirPin = 4;
const int rightPWMPin = 5;
const int leftDirPin = 7;
const int leftPWMPin = 6;

//Neopixel data
const int neoPixelFast = 0b00000100;
const int neoPixelSlow = 0b00000110;

//NEOPIXEL SETUP
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR 
#endif
#define PIN 2
  Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 3, 1, PIN,
  NEO_TILE_TOP   + NEO_TILE_LEFT   + NEO_TILE_ROWS   + NEO_TILE_PROGRESSIVE +
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);
int countA= 9;
int countB= 9;
int delayInterval= 5;
int brightness = 9;
int x    = matrix.width();
int pass = 0;

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(255, 255, 0), matrix.Color(57, 255, 20) };


//SERVO SETUP
#include <Servo.h>

  Servo myservo;  // create servo object to control a servo
  int pos = 1000;  // variable to store the servo position
  unsigned long servoTimer; //variable to hold the timer value
  unsigned long servoInterval = 800; //blink period in millisecond
  int potpin = A5;  // analog pin used to connect the potentiometer
  int val;    // variable to read the value from the analog pin


//BUTTON SETUP
#define DELAY_TIMEA (2000)
#define DELAY_TIMEB (2000)
// stores the start time, use unsignged long to prevent overflow
unsigned long startTimeA;
unsigned long startTimeB;     
 boolean bSwitchDownA = false;
 boolean bSwitchDownB = false;


void setup() {

//neopixel setup
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(brightness);
  matrix.setTextColor(colors[0]);
  
  startTimeA = millis();
  startTimeB = millis();
  
// Motor controller pins
  pinMode(rightDirPin, OUTPUT);
  pinMode(leftDirPin, OUTPUT);
  myservo.attach(3);
  
  Serial.begin(115200);

// RF24 setup
  if (!radio.begin()) {
    Serial.println("radio  initialization failed");
    while (1)
      ;
  } else {
    Serial.println("radio successfully initialized");
  }
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();             // sets  module as receiver

  //neopixel setup
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  }

  
void loop() {
//servo move
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);
  
  uint8_t pipeNum;

  if (radio.available(&pipeNum))  //Looking for the data.
  {
    int data;

    //Serial.print("data available on pipe ");
    //Serial.println(pipeNum);

    radio.read(&data, sizeof(data));  //Reading the data
    Serial.print("\ndata = ");
    Serial.println( data, BIN);

    // split data into neoPixelData and switchData
    int switchData = data & 0b0000000011111111;
    int neoPixelData = (data & 0b1111111100000000) >> 8;
    
    
if( neoPixelData) {
    bSwitchDownA = true;
    controlNeoPixel(neoPixelData);
    startTimeA = 0;
  } 
  
else {
    if( bSwitchDownA ) {
      bSwitchDownA = false;  
    }
    
    if( startTimeA + DELAY_TIMEA < millis() ) {
      startTimeA = millis();  
    }
  } 


switch (switchData) {
                              
      case 0b00000010:                       // if (data == 0b00000010) {
        Serial.println("forward");
        digitalWrite(rightDirPin, HIGH);
        analogWrite(rightPWMPin, 0);
        digitalWrite(leftDirPin, LOW);
        analogWrite(leftPWMPin, 255);
        break;  
       
      default:
        Serial.println("invalid code");
        stop();
        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, LOW);
        break;
    }
  } else {
    //Serial.println("stop");
    stop();
  }
  delay(5);
}

void stop() {
  
  digitalWrite(rightDirPin, LOW);
  analogWrite(rightPWMPin, 0);
  digitalWrite(leftDirPin, LOW);
  analogWrite(leftPWMPin, 0);

}

void controlNeoPixel(int pattern) {
  if (pattern == neoPixelFast) {
  doNeoPixelFast();

  } else if (pattern == neoPixelSlow)
  {
    doNeoPixelSlow();
  }
}

void doNeoPixelFast() {
  while ( countA > 0) {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("SEARCHING"));
  if(--x < -85) {
    x = matrix.width();
   if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
    countA = countA - 3;
    break;
  }
  matrix.show();
  delay(10);
  }
}
void doNeoPixelSlow() {
  while ( countB > 0) {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("GIVE UP"));
  if(--x < -85) {
    x = matrix.width();
   if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
    countB = countB - 3;
   brightness = brightness - 3;
   break;
    }
  matrix.show();
  matrix.setBrightness(brightness);
  delay(100);
  
  }
   
}
