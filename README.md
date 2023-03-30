# arduino-robo-car-with-voice-control
A robo-car that can be controlled with a virtual Dpad and voice commands, with obstacle avoidance.

# Introduction


The scope of this project is to create a Robo-Car that is controlled by voice commands or via a Dpad using third party applications, the Robo-Car will also have an obstacle avoidance function assisted by 2 IR sensors and an ultrasonic distance sensor.
# General Description

We'll stack a Motor Shield on our Arduino Uno and connect it to 4 dc motors, it'll also be connected with a bluetooth module that will be used to control the car with a Dpad or voice commands using third party applications, We'll also connect 2 IR sensors & an Ultrasonic distance sensor rotated by a Servo motor for obstacle avoidance.
 

# Hardware Design

**List of components:**
  * Arduino Uno
  * Motor Shield Driver L293D 
  * Wheels 4x
  * TT DC Gear Motor 4x
  * HC-05 Bluetooth Module
  * Servo Motor
  * Ultrasonic Sensor
  * IR Sensor 2x
  * 18650 Li-on Battery 2x
  * Battery Holder

# Software Design

I used Arduino IDE to write and upload the code.

**Libraries:** 
  * <AFMotor.h>: instructs the Arduino on how to talk to the Adafruit Motor shield
  * <NewPing.h>: to work with our HC-SR04 Ultrasonic Sensor 
  * <Servo.h>: to work with our Servo motor
 
**3rd party apps:**
  * BT Car (android): for bluetooth Dpad control 
  * '' https://drive.google.com/file/d/1DXr-QmpZ3TaMstY1qKcxu4LLNM26HiUW/view ''
  * Arduino Bluetooth controller (android): for bluetooth voice control 
  * '' https://drive.google.com/file/d/1xkiM3GqHRDYxyqz5ztFWlB-ux6jLU944/view ''

**Functions implemented:** 
- fdpad(), bdpad(), rdpad(), ldpad(), topl(), topr(), bottomr(), bottoml()**
All of these functions are quite similar in logic, one method for each direction in the Dpad control


- void fdpad():
This is the first function for the voice control and obstacle avoidance, it calculates the distance using the HC-SR04 sensor, the method
calls the fdpad() method unless the distance is less than 10cm, then it'll call the stop() method.

- void forward(), forwardright(), forwardleft():  
These are of similar logic to forward() only that after calling the topr() or topl() method there will be a delay of 0.5s till the motors stop   (''motor1.run(RELEASE);''), used for voice control.

- backward():
This method calls the bdpad() method unless one of our IR sensors senses an object, then we call the stop() method.


- backwardright(), backwardleft():
Call the bottomr() or bottoml method, stops the motors after 0.5s (''motor1.run(RELEASE);'').

- right(), left():
Having our ultrasonic sensor mounted on a servo motor, these functions move the servo motor either to the right or left, then it goes back to the middle adding animation, then either the rdpad() or ldpad() method will be called, and the motors will stop after 0.7s.

- Stop():
Stops the motors.
 
- loop():
Mostly if statements, when our input matches with 'F' or 'B' or 'L' or 'R' or.... then the corresponding dpad direction function will be called, when it matches "turn left" or "left" or "turn right" or "right or "top right" or..... then the corresponding voice functions will be called. 
when the input is "move forward" or "move backward", the forward() or backward() methods will keep running in a while loop until one of the sensors senses a nearby object.

# Results
**Demo:** https://youtube.com/watch?v=kqReeGgIopE



Third party apps used: 
 BT Car (android): https://drive.google.com/file/d/1DXr-QmpZ3TaMstY1qKcxu4LLNM26HiUW/view
 
 Arduino Bluetooth controller (android): https://drive.google.com/file/d/1xkiM3GqHRDYxyqz5ztFWlB-ux6jLU944/view

