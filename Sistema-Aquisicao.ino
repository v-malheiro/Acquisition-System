/* Code to run 2 stepper motor and shaker */
// libraries
#include <TimerOne.h>
#define COMMON_ANODE

// declares
//int IN1 = 2; //define red led
//int IN2 = 3; //define white led
//int IN3 = 4; //define yellow led
int IN4 = 20; //define blue led
int acq = 5; //define acquisition module
int shaker = 6; //define shaker module -> nao utilizado
int acq2 = 21; //define acquisition module for triggering by function generator -> nao utilizado

//-------- Leds Pin --------//
const int ledR = 4; // define red led pin
const int ledG = 3; // define green led pin
const int ledB = 2; // define blue led pin
 
//motor 1 - rotation around axis
int PUL = 10;   //define Pulse pin - using just the positive 
int EN = 8;    //define Enable pin - using just the positive 
int DIR = 9;  //define Direction pin - using just the positive

//motor 2 - translation
int A = 10; // for rotation -> nao utilizado
int B = 11; // for rotation -> nao utilizado
int C = 12; // for rotation -> nao utilizado
int D = 13; // for rotation -> nao utilizado
int E = 14; // for enable -> nao utilizado
int F = 15; // for enable -> nao utilizado

const int buttonPin1 = 47; // define the pushbutton (white) pin for start
const int buttonPin2 = 49; // define the pushbutton (red) pin for translation in forward
const int buttonPin3 = 51; // define the pushbutton (yellow) pin for translation in backward
const int buttonPin4 = 45; // define the pushbutton (blue) pin for shaking acquision
const int buttonPin5 = 31; // define the pushbutton (none) pin for returning to initial point


// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
float frequencia = 0;
int contador = 0;
int contador2 = 0;
bool inicia_aquisicao = false;
bool inicia_aquisicao2 = false;
bool inicia_aquisicao3 = false;


// variable defines
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (EN, OUTPUT);
  digitalWrite (EN, LOW);
  Serial.begin(9600);
//  pinMode(IN1,OUTPUT);
//  pinMode(IN2,OUTPUT);
//  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(acq,OUTPUT);
  pinMode(acq2,OUTPUT);
  pinMode(shaker, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  Timer1.initialize(1000000);
//-------- Leds Mode --------//
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
}

//-------- Function: Define Colors to the Led --------//
void setColor(int red, int green, int blue){
  analogWrite(ledR, red);
  analogWrite(ledG, green);
  analogWrite(ledB, blue);
}

// code run
void loop() {
  int i;
  setColor(0, 255, 0);
  delay(1000);

///////////////////////////////////////////// FORWARD MOVIMENT /////////////////////////////////////////////

  // read the state of the pushbutton2 value:
  buttonState2 = digitalRead(buttonPin2); 
  // check if the pushbutton2 is pressed. If it is, the button state is LOW:
  if (buttonState2 == HIGH) {
    //digitalWrite(IN1, 1); // red led - ON
    Serial.println("inicio translacao para frente");
    setColor(255, 0, 0);
    delay(1000);
    // if i = 1575, it will move 4 cm, but we wanted a little  bit of overlap
    for (int i = 0; i <= 1500; i++) {
      digitalWrite(E, 1);
      digitalWrite(F, 1);
      
      digitalWrite(A, 1);  
      digitalWrite(B, 0);  
      digitalWrite(C, 0);  
      digitalWrite(D, 1);
      delay(10);
      
      digitalWrite(A, 0);  
      digitalWrite(B, 1);  
      digitalWrite(C, 0);  
      digitalWrite(D, 1);
      delay(10);

      digitalWrite(A, 0);  
      digitalWrite(B, 1);  
      digitalWrite(C, 1);  
      digitalWrite(D, 0);
      delay(10);

      digitalWrite(A, 1);  
      digitalWrite(B, 0);  
      digitalWrite(C, 1);  
      digitalWrite(D, 0);
      delay(10);

      delay(10);
      digitalWrite(E, 0);
      digitalWrite(F, 0);
      
      ////////////////////////////// STOP SYSTEM ////////////////////////////////
      buttonState4 = digitalRead(buttonPin4);
      //digitalWrite(IN4, 0); // blue led - ON 
  
      // check if the pushbutton1 is pressed. If it is, the button state is LOW:
      if (buttonState4 == HIGH) {
        setColor(0, 0, 255);
        delay(1000);
        i = 1500;
        //Serial.println("fim translacao para frente");
      }
    ///////////////////////////////////////////////////////////////////////////
      i;
    }

    //digitalWrite(IN1, 0); // red led - 0FF
    Serial.println("fim translacao para frente");
  }

///////////////////////////////////////////// BACKWARD MOVIMENT /////////////////////////////////////////////
  
  // read the state of the pushbutton3 value:
  buttonState3 = digitalRead(buttonPin3); 
  // check if the pushbutton2 is pressed. If it is, the button state is LOW:
  if (buttonState3 == HIGH) {
    // digitalWrite(IN3, 1); // yellow led - ON
    Serial.println("inicio translacao para trás");
    setColor(255, 255, 0);
    delay(1000);
    // if i = 1575, it will move 4 cm, but we wanted a little  bit of overlap
    for (int i = 0; i <= 1500; i++) {
      digitalWrite(E, 1);
      digitalWrite(F, 1); 
          
      digitalWrite(A, 1);  
      digitalWrite(B, 0);  
      digitalWrite(C, 1);  
      digitalWrite(D, 0);
      delay(10);

      digitalWrite(A, 0);  
      digitalWrite(B, 1);  
      digitalWrite(C, 1);  
      digitalWrite(D, 0);
      delay(10);

      digitalWrite(A, 0);  
      digitalWrite(B, 1);  
      digitalWrite(C, 0);  
      digitalWrite(D, 1);
      delay(10);

      digitalWrite(A, 1);  
      digitalWrite(B, 0);  
      digitalWrite(C, 0);  
      digitalWrite(D, 1);
      delay(10);
      
      delay(10);
      digitalWrite(E, 0);
      digitalWrite(F, 0);
 
      ////////////////////////////// STOP SYSTEM ////////////////////////////////
      buttonState4 = digitalRead(buttonPin4);
      //digitalWrite(IN4, 0); // blue led - ON 
  
      // check if the pushbutton1 is pressed. If it is, the button state is LOW:
      if (buttonState4 == HIGH) {
        setColor(0, 0, 255);
        delay(1000);
        i = 1500;
        //Serial.println("fim translacao para trás");
      }
    ///////////////////////////////////////////////////////////////////////////
      i;
    }
   
    //digitalWrite(IN3, 0); // yellow vermelho - OFF
    Serial.println("fim translacao para trás");
  }


///////////////////////////////////////////// ROTATION MOVIMENT + ACQUISITION /////////////////////////////////////////////

  // read the state of the pushbutton1 value:
  buttonState1 = digitalRead(buttonPin1);
  //digitalWrite(IN2, 0); // white led - OFF
  
  // check if the pushbutton1 is pressed. If it is, the button state is LOW:
  if (buttonState1 == HIGH) {
    inicia_aquisicao = true;
  }

  if (inicia_aquisicao){
    //digitalWrite(IN2, 1); // white led - ON
    Serial.println("inicio aquisição");
    setColor(255, 255, 255);
    delay(1000);
    // enable the stepper motor to run
    digitalWrite(DIR, HIGH); // HIGH or LOW depends on which direction do you want to rotate
    digitalWrite(acq, 1); //TTL pulse on for acquisition
    delayMicroseconds(50); //pulse length
    digitalWrite(acq, 0); //TTL pulse off
    delay(100);
    //delay(1000); // waiting time to begin
    do{ 
      for (int i = 0; i <= 720; i++) {
        digitalWrite(PUL,LOW);                 // send pulse 1
        delayMicroseconds(400);                // delay time between to pulses - it determinates the rotation velocity 
        digitalWrite(PUL,HIGH);                // send pulse2
        delayMicroseconds(400);                // delay time between to pulses - it determinates the rotation velocity
        i;
      }
     
      // acquisition
      delay(100);
      Serial.print("adquirindo passo: ");
      Serial.println(contador);
      digitalWrite(acq, 1); //TTL pulse on for acquisition
      delayMicroseconds(100); //pulse length
      digitalWrite(acq, 0); //TTL pulse off
      delay(1000); //delay time between two rotation+acquisition
    
      ////////////////////////////// STOP SYSTEM ////////////////////////////////
      buttonState4 = digitalRead(buttonPin4);
      //digitalWrite(IN4, 0); // blue led - ON 
  
      // check if the pushbutton1 is pressed. If it is, the button state is LOW:
      if (buttonState4 == HIGH) {
        setColor(0, 0, 255);
        delay(1000);
        inicia_aquisicao = false;
        contador = -1;
        Serial.println("fim aquisição");
      }
      /////////////////////////////////////////////////////////////////////////// 
    
      // stops the rotation by the time it gets 50 acquisition to not full sonix buffer
      if (++contador == 25){
        inicia_aquisicao = false;
        contador = 0;
        Serial.println("fim aquisição");
      }
     
    }while (inicia_aquisicao);
    //digitalWrite(IN2,0); // white led - OFF
 }

 

///////////////////////////////////////////// ROTATION MOVIMENT BACK TO INITIAL /////////////////////////////////////////////

  // read the state of the pushbutton1 value:
  buttonState5 = digitalRead(buttonPin5);
  
  if (buttonState5 == HIGH) {
    inicia_aquisicao3 = true;
  }
  
  if (inicia_aquisicao3){
    //digitalWrite(IN2, 1); // white led - ON
    Serial.println("retornando ao inicio");
    setColor(255, 0, 255);
    delay(1000);

    // enable the stepper motor to run
    digitalWrite(DIR,LOW); // HIGH or LOW depends on which direction do you want to rotate  
    //digitalWrite(acq2, 1); // sends trigger pulse to function generator (FG)
    //delayMicroseconds(50); //pulse length
    //digitalWrite(acq2,0);
    
    //delay(1000); // waiting time to begin
      do{ 
         for (int i = 0; i <= 720; i++) {
          digitalWrite(PUL,LOW);                 // send pulse 1
           delayMicroseconds(100);                // delay time between to pulses - it determinates the rotation velocity 
          digitalWrite(PUL,HIGH);                // send pulse2
           delayMicroseconds(100);                // delay time between to pulses - it determinates the rotation velocity
          i;
          }
     
    Serial.println(contador2);
    delay(300);
    //delay(50);

    ////////////////////////////// STOP SYSTEM ////////////////////////////////
    buttonState4 = digitalRead(buttonPin4);
    //digitalWrite(IN4, 0); // blue led - ON 
    
    // check if the pushbutton1 is pressed. If it is, the button state is LOW:
    if (buttonState4 == HIGH) {
      setColor(0, 0, 255);
      delay(1000);
      inicia_aquisicao3 = false;
      contador2 = -1;
      Serial.println("fim aquisição");
    }
    ///////////////////////////////////////////////////////////////////////////
    
    // stops the rotation at the initial point
    if (++contador2 == 250){ //271 OR 251
    inicia_aquisicao3 = false;
    contador2 = 0;
   }
     
  }while (inicia_aquisicao3);
 }

  
///////////////////////////////////////////// ROTATION MOVIMENT + ACQUISITION + SHAKER /////////////////////////////////////////////
  /*
  // read the state of the pushbutton4 value:
  buttonState4 = digitalRead(buttonPin4);
  digitalWrite(IN4, 0); // blue led - ON
  
  //frequencia = 200; 
  
  // check if the pushbutton1 is pressed. If it is, the button state is LOW:
  if (buttonState4 == LOW) {
    inicia_aquisicao2 = true;
  }
  
  if (inicia_aquisicao2){
  digitalWrite(IN4, 1); // blue led - ON
  Serial.println("inicio aquisição com shaker");

    // enable the stepper motor to run
    digitalWrite(DIR, HIGH); // HIGH or LOW depends on which direction do you want to rotate
    digitalWrite(acq, 1); //TTL pulse on for acquisition
    delayMicroseconds(50); //pulse length
    digitalWrite(acq, 0); //TTL pulse off
    delay(100);
    //delay(1000); // waiting time to begin
      do{ 
         for (int i = 0; i <= 7; i++) {
          digitalWrite(PUL,LOW);                 // send pulse 1
           delayMicroseconds(100);                // delay time between to pulses - it determinates the rotation velocity 
          digitalWrite(PUL,HIGH);                // send pulse2
           delayMicroseconds(100);                // delay time between to pulses - it determinates the rotation velocity
          i;
          }

    //shaker - ON
      delay(50);
      Serial.print("adquirindo passo: ");
      Serial.println(contador);

      //delay time between pulses will determinate the shaking frequency
    for (int i=0; i<= 300; i++){
      digitalWrite(shaker,1); //shaker on
        delay(round(1000/(2*frequencia)));
      digitalWrite(shaker,0); //shaker on
        delay(round(1000/(2*frequencia)));
      }
      
      digitalWrite(acq, 1);
      delay(50);
      digitalWrite(acq,0);       
   
   delay(1000); //delay time between two rotation+acquisition+shaking
    
    // stops the rotation 
    if (++contador == 1){
    inicia_aquisicao2 = false;
    contador = 0;
    Serial.println("fim aquisição");

   }
   
  }while (inicia_aquisicao2);
  digitalWrite(IN4,0); // blue led - OFF
 }*/

}
