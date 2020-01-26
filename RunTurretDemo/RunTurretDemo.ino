#include <Servo.h>

Servo base0;
Servo top0;
Servo base1;
Servo top1;
byte input[1];

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  base0.attach(10);
  top0.attach(11);
  base1.attach(5);
  top1.attach(6);

 
}

void loop() {
   
  /*if(Serial.available() > 0) {
    digitalWrite(13, HIGH);
    
    //digitalWrite(13, HIGH);
    if(input[0] == 0x00) {
      digitalWrite(13, HIGH);
           
    }
    //delay(300);
    //digitalWrite(13, LOW);
  }*/
}

void serialEvent() {
  Serial.readBytes(input, 1);
  if(input[0] == 0x01) {
    danceDemo();
    digitalWrite(13, HIGH);
  } else if(input[0] == 0x02) {
    duel();
    digitalWrite(13, LOW);    
  } else if(input[0] == 0x03) {
    bow();
  } else if(input[0] > 0x4B) {
    base0.write(((int)input[0])-75);
    base1.write(((int)input[0])-75);
  }
  
}

void bow() {
  idleTop(0);
  idleTop(1);

  delay(1000);
  base0.write(90);
  base1.write(90);

  delay(1000);
  for(int x = 180; x > 0; x--) {
    top0.write(x);
    top1.write(x);
    delay(30);
  }
  
}

void danceDemo() {
  idleTop(0);
  idleTop(1);

  delay(1000);
  turnRight(0);
  turnRight(1);

  delay(1000);
  turnLeft(0);
  turnLeft(1);

  delay(1000);
  performFlick(0, 5);
  performFlick(1, 5);

  delay(1000);
  performFlick(2, 5);
}

void idleTop(int machine) {
  if(machine == 0) {
    top0.write(0);
  } else {
    top1.write(0);
  }
  
}

void turnLeft(int machine) {
  if(machine == 0) {
    base0.write(180);
  } else {
    base1.write(180);
  }
}

void turnRight(int machine) {
  if(machine == 0) {
    base0.write(0);
  } else {
    base1.write(0);
  }
  
}

void duel() {
  idleTop(0);
  idleTop(1);
  
  delay(1000);
  turnLeft(1);
  turnRight(0);

  performFlick(2, 10);
  
}

void performFlick(int machine, int flicks) {
  for(int i = 0; i < flicks; i++) {
    if(machine == 0) {
      for(int x = 0; x < 90; x++) {
        top0.write(x);
        delay(3);
      }
      top0.write(0);
      delay(300);
    } else if(machine == 1) {
      for(int x = 0; x < 90; x++) {
        top1.write(x);
        delay(3);
      }
      top1.write(0);
      delay(300);
    } else {
      for(int x = 0; x < 90; x++) {
        top0.write(x);
        top1.write(x);
        delay(3); 
      }
      top0.write(0);
      top1.write(0);
      delay(300);
    }
  }
}
