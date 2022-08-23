
#include <SoftwareSerial.h> 
#include <Servo.h>  

Servo myservo1, myservo2, myservo3, myservo4; 
int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup()
{
  myservo1.attach(3); // attach servo signal wire to pin 3
  myservo2.attach(5); // attach servo signal wire to pin 5
  myservo3.attach(6); // attach servo signal wire to pin 6
  myservo4.attach(9); // attach servo signal wire to pin 9
  
//Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}
void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    
    Serial.println(realservo);
    
    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
    
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
     
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
     
      delay(10);
    }  

    // voice commands
    if (realservo == 14000) {
      
      myservo1.write(180);
     
      delay(10);
    }
    
    if (realservo == 15000) {
      
      myservo1.write(0);
     
      delay(10);
    }
    
    if (realservo == 10000) {
      
      myservo3.write(180);
     
      delay(10);
    }
    
    if (realservo == 11000) {
      
      myservo3.write(0);
      
      delay(10);
    }
    
    if (realservo == 12000) {
      
      myservo2.write(180);
     
      delay(10);
    }
    
    if (realservo == 13000) {
      
      myservo2.write(0);
     
      delay(10);
    }
    if (realservo == 17000) {
      
      myservo4.write(0);
     
      delay(10);
    }
    if (realservo == 18000) {
      
      myservo4.write(180);
     
      delay(10);
    }

 if (realservo == 16000) {
      
      myservo1.write(0);
      myservo2.write(90);
      myservo3.write(90);
      myservo4.write(90);
      delay(10);
    }
    
    }}
  
