/*
* Danial Saeedi
* 2016
* It's a simple robot. I use two Servos.
* Servo pin9 : This servo will hit the switch
* Servo pin10 : This servo will open the door
* Switch pin2 : You know what it does
*/
#include <Servo.h>

// Switch keyword is reserved
int switch2 = 2;

//Create the Servos object
Servo hand;
Servo door;

//Get all data from switch
int switchState = digitalRead(switch2);

boolean done = false;
int countMoves = 0;

void setup() {
  //Decalre pin 2 to be an INPUT
  pinMode(switch2,INPUT);
  digitalWrite(switch2,HIGH);
  Serial.begin(9600);

  //Attaching the Servos object
  hand.attach(9);
  door.attach(10);

  //
  hand.write(70);
  door.write(80);

  randomSeed(analogRead(0));
}

void loop() {
  

  //Now I have to store the switch state every mili-second
  switchState = digitalRead(switch2);

  simpleMove();
}

void simpleMove(){
  //if the switchState equals to 1, then move the Servos!
  if(switchState == 1){

     /*
    * I don't wanna just turn the switch off , I want to give it a personality.
    */
    // In this variable , I store a random number to run random moves!
    int randNumber = random(0,4);
    if(randNumber == 1){
      door.write(0);
    }else if(randNumber == 2){
      int pos = 70;

      for (pos = pos; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
        countMoves +=1;
        if(countMoves >= 500){done = true; door.write(0);}

        if(done == false){
          // in steps of 1 degree
          door.write(pos);              // tell servo to go to position in variable 'pos'
          delay(2);
        }
        
      }
    }else if(randNumber == 3){
      int pos = 70;

      for (pos = pos; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
        countMoves +=1;
        if(countMoves >= 70){done = true; door.write(0);}

        if(done == false){
          // in steps of 1 degree
          door.write(pos);              // tell servo to go to position in variable 'pos'
          delay(100);
        }
        
      }
    }

    

    if(done){
      int pos = 80;
      for (pos = 80; pos <= 360; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        hand.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2);
      }
      for (pos = 260; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
        hand.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2);
      }
    }
    

  }else{
    door.write(70);
    delay(500);
    hand.write(70);
    done = false;
    countMoves = 0;
  }
}