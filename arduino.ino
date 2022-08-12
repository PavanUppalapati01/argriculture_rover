#include <SoftwareSerial.h>

SoftwareSerial BT(A0, A1);
int in1 = 6;
int in2 = 7;
int in3 = 5;
int in4 = 8;
int in5 = 9;
int in6 = 10;
int in7 = 11;
int in8 = 12;
char state;
void setup(){
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
BT.begin(9600); // Setting the baud rate of Software Serial Library 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
   pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
 delay(1000);
 }

void loop(){
//if some date is sent, reads it and saves in state
if(BT.available() > 0){     
state = BT.read(); 
Serial.println(state);     
}
     if (state == '1'){forword();Serial.println("Forward!");}
else if (state == '4'){backword();Serial.println("Backword!");}
else if (state == '2'){turnLeft();Serial.println("Turn LEFT");}
else if (state == '3'){turnRight();Serial.println("Turn RIGHT");}
else if (state == '9'){
  stop();Serial.println("STOP!");
}  
 if(state == '5') {Serial.println("weeder on");  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
 } 
else if (state == '6') {Serial.println("weeder off");
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
 } 
else if (state == '7') {Serial.println("seeder on");  

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);}  
else if (state == '8') {Serial.println("seeder off");

  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);} 
 

delay(30);
}


void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forword(){
     digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
    }

void backword(){
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}



void turnRight(){
   digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);

  }
void turnLeft(){ 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
