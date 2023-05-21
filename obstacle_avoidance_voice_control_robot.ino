#include <AFMotor.h>

#include <NewPing.h>

#include <Servo.h>


#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 300
#define IR1 A5
#define IR2 A4

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;

String voice;
void setup() {
Serial.begin(9600);
myservo.attach(10);
myservo.write(90);
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);

}

void loop() {
    int distance = sonar.ping_cm();
    if (Serial.available() > 0) {
        voice = "";
        delay(2);
        voice = Serial.readString();
        delay(2);
        //dpad: 
        if (voice == "F") {
            fdpad();
        }

        if (voice == "B") {
            bdpad();
        }

        if (voice == "L") {
            ldpad();
        }

        if (voice == "R") {
            rdpad();
        }
        if (voice == "I") {
            topr();
        }

        if (voice == "J") {
            topl();
        }

        if (voice == "K") {
            bottomr();
        }

        if (voice == "M") {
            bottoml();
        }
        if (voice == "T") {
            Stop();
        }
        //voice:
        if (voice == "turn left") {
            left();
        } else if (voice == "left") {
            left();
        }
        if (voice == "turn right") {
            right();
        } else if (voice == "right") {
            right();
        } 
        if (voice == "top right") {
            forwardright();
        }
        if (voice == "top left") {
            forwardleft();
        }
        if (voice == "bottom right") {
            backwardright();
        }
        if (voice == "bottom left") {
            backwardleft();
        }
       
}

while(voice == "move forward") {
  forward();
}
while(voice == "move backward") {
  backward();
 }
}

//methods used for dpad
void fdpad() {
  motor1.setSpeed(200); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200); 
  motor3.run(FORWARD); 
  motor4.setSpeed(200); 
  motor4.run(BACKWARD); 
}

void bdpad(){
  motor1.setSpeed(200); 
  motor1.run(FORWARD); 
  motor2.setSpeed(200); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(200); 
  motor3.run(BACKWARD);
  motor4.setSpeed(200); 
  motor4.run(FORWARD); 
}

void rdpad(){
  motor1.run(BACKWARD);
  motor1.setSpeed(100);
  motor2.run(FORWARD);
  motor2.setSpeed(200);
  motor3.run(BACKWARD);
  motor3.setSpeed(100);
  motor4.run(FORWARD);
  motor4.setSpeed(200);
}

void ldpad() {
  motor1.run(FORWARD);
  motor1.setSpeed(200);
  motor2.run(BACKWARD);
  motor2.setSpeed(100);
  motor3.run(FORWARD);
  motor3.setSpeed(200);
  motor4.run(BACKWARD);
  motor4.setSpeed(100);
}

void topl() {
  motor1.setSpeed(200); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200/3.1); 
  motor3.run(FORWARD); 
  motor4.setSpeed(200/3.1); 
  motor4.run(BACKWARD); 
}

void topr() {
    motor1.setSpeed(200/3.1); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(200/3.1);
  motor2.run(FORWARD);
  motor3.setSpeed(200); 
  motor3.run(FORWARD); 
  motor4.setSpeed(200); 
  motor4.run(BACKWARD); 
}

void bottomr() {
      motor1.setSpeed(200/3.1); 
  motor1.run(FORWARD); 
  motor2.setSpeed(200/3.1); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(200); 
  motor3.run(BACKWARD);
  motor4.setSpeed(200); 
  motor4.run(FORWARD); 
}

void bottoml(){
    motor1.setSpeed(200); 
  motor1.run(FORWARD); 
  motor2.setSpeed(200); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(200/3.1); 
  motor3.run(BACKWARD);
  motor4.setSpeed(200/3.1); 
  motor4.run(FORWARD);
}

//methods used for voice control
void forward() {
  int distance = sonar.ping_cm();
  
   if(distance < 10){
    Stop();
   voice="";
   }else {
  fdpad();
  }
}

void forwardright() {
  int distance = sonar.ping_cm();
  
   if(distance < 10){
    Stop();
   voice="";
   }else {
  topr();
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}
void forwardleft() {
  int distance = sonar.ping_cm();
  
   if(distance < 10){
    Stop();
   voice="";
   }else {
  topl();
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}
void backward() {
  int IR_Sensor1 = digitalRead(IR1);
  int IR_Sensor2 = digitalRead(IR2);
  
  if(IR_Sensor1 == 0 || IR_Sensor2 == 0) {
    Stop();
    voice="";
  }else {
  bdpad();
 
  }
}
void backwardright() {
  bottomr();
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void backwardleft() {
  bottoml();
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void left() {
  myservo.write(180);
  delay(500);
  myservo.write(90);
  delay(500);
  ldpad();
  delay(700);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void right() {
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  rdpad();
  delay(700);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


//stop method
void Stop() {
 motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}
