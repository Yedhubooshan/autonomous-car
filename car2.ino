// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 3;
const int echoPin = 2;
int count;
// Variables for the duration and the distance
long duration;
int distance,distanceR,distanceL;
Servo myServo; // Creates a servo object for controlling the servo motor
char command;  // to store input character received via BT.
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(5, OUTPUT); // motor 1 terminal 1
  pinMode(6, OUTPUT); // motor 1 terminal 2
  pinMode(9, OUTPUT); // motor 2 terminal 1
  pinMode(10, OUTPUT); // motor 2 terminal 2
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
  while (!Serial) 
  {
     // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  
  if(Serial.available() > 0){ 
    command = Serial.read();
    Serial.println(command);
    if(command == 'V')
    {
      servocheck();    
      count++;
      while(command!='F' and count!=0)
      {
      command = Serial.read();     
      ultrasonic();
      }
    }
    else{
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'G':
      fleft();
      break;
    case 'I':
      fright();
      break;
    case 'H':
      bleft();
      break;
    case 'J':
      bright();
      break;
      //new
    //case 'V':
     //servocheck();
     //ultrasonic();
     // break;
    }
    count=0;
   }
  }
}

void forward()
{
  Serial.println("Forward");
  analogWrite(5 ,255);
  analogWrite(6 ,0);
  analogWrite(9 ,0);
  analogWrite(10 ,255);
}
void back()
{
  Serial.println("back");
  analogWrite(5 ,0);
  analogWrite(6 ,255);
  analogWrite(9 ,255);
  analogWrite(10 ,0);
}
void left()
{
  Serial.println("left");
  analogWrite(5 ,255);
  analogWrite(6 ,0);
  analogWrite(9 ,0);
  analogWrite(10 ,0);
}
void right()
{
  Serial.println("right");
  analogWrite(5 ,0);
  analogWrite(6 ,0);
  analogWrite(9 ,0);
  analogWrite(10 ,255);
}
void Stop()
{
  Serial.println("stop");
  analogWrite(5 ,0);
  analogWrite(6 ,0);
  analogWrite(9 ,0);
  analogWrite(10 ,0);
}
void fleft()
{
  Serial.println("f_left");
  analogWrite(5 ,255);
  analogWrite(6 ,0);
  analogWrite(9 ,0);
  analogWrite(10 ,210);
}
void fright()
{
  Serial.println("f_right");
  analogWrite(5 ,210);
  analogWrite(6 ,0);
  analogWrite(9 ,0);
  analogWrite(10 ,255);
}
void bright()
{
  Serial.println("b_right");
  analogWrite(5 ,0);
  analogWrite(6 ,210);
  analogWrite(9 ,255);
  analogWrite(10 ,0);
}
void bleft()
{
  Serial.println("b_left");
  analogWrite(5 ,0);
  analogWrite(6 ,255);
  analogWrite(9 ,210);
  analogWrite(10 ,0);
}
//new
void ultrasonic() //moves front, then checks for distance and goes to turning, or continue
{                 // moving forward
    int distanceS= calculateDistance();
    Serial.println(distanceS);
    //Serial.println(command);
    if(distanceS <=30)
    {
      turning();
    }
    else
    {
      forward(); // goes forward
    }
}
void turning()
{
   back();
   delay(500);
   Stop(); // stops the vehicle
   // checks for direction
   for(int i=0;i<=180;i++){  
   myServo.write(i);
   delay(2);
   }
   distanceL = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
   Serial.print(" distanceL= ");
   Serial.print(distanceL); // Sends the distance value into the Serial Port
   delay(10);
   // Repeats the previous lines from 165 to 15 degrees
   for(int i=180;i>0;i--){  
   myServo.write(i);
   delay(2);
   }
   distanceR = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
   Serial.print(" distanceR= ");
   Serial.print(distanceR); // Sends the distance value into the Serial Port
   delay(10);
   myServo.write(90);
   //command = Serial.read();
   //Serial.println(command);
   if (distanceL>=distanceR)
   {
     Serial.println(" Left turn");
     left();
     delay(500);
   }
   else
   {
     Serial.println(" Right turn");
     right();
     delay(500);
   }
  }

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
void servocheck() // checking working of the servo motor
{
  Serial.println("checking");
  for(int i=0;i<180;i++){  
  myServo.write(i);
  delay(2);
  }
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(2);
  }
  myServo.write(90);
  }
