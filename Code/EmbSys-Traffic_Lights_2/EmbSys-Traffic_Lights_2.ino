// Specs:
// State  Vehicles Pedestrian             Time
//  0       Green     Red                 15s
//  1       Yellow    Red                 5s
//  2       Red       Green               10s
//  3       Red       Flashing Red On  |  10s
//  4       Red       Flashing Red Off |

// Change circuit or values to match pins below
const byte VGREEN = 13;
const byte VYELLOW = 12;
const byte VRED = 11;
const byte PGREEN = 7;
const byte PRED = 6;
const byte PEDSW = 2;

volatile byte state = 0;
byte i = 0;

void setup() {
  pinMode(VGREEN, OUTPUT);
  pinMode(VYELLOW, OUTPUT);
  pinMode(VRED, OUTPUT);
  pinMode(PGREEN, OUTPUT);
  pinMode(PRED, OUTPUT);
  pinMode(PEDSW, INPUT);

  i = 50; // Set delay counter for state 0

  attachInterrupt(digitalPinToInterrupt(PEDSW), blink, FALLING);
}

void loop() {
  // Set LEDs by state
  switch (state) {
    case 0:
      // Clear all LEDs except for vehicle green and pedestrian red
      digitalWrite(VGREEN, HIGH);
      digitalWrite(VYELLOW, LOW);
      digitalWrite(VRED, LOW);

      digitalWrite(PGREEN, LOW);
      digitalWrite(PRED, HIGH);

      // // 15s = 50 x 300ms
      // if (!digitalRead(PEDSW)) {
      //   state = 1;
      //   break;
      // }
      delay(300);

      // Counter has reached 0: go to next state
      if (!--i)
        state = 1;

      break;
    
    case 1:
      // Transition to vehicle yellow
      digitalWrite(VGREEN, LOW);
      digitalWrite(VYELLOW, HIGH);

      // 5s, no interruptions
      delay(5000);
      state = 2;
      break;
    
    case 2:
      // Transition to vehicle red and pedestrian green
      digitalWrite(VYELLOW, LOW);
      digitalWrite(VRED, HIGH);

      digitalWrite(PGREEN, HIGH);
      digitalWrite(PRED, LOW);

      delay(10000);
      state = 3;

      // Prepare counter for flashing pedestrian red light
      i = 10;
      break;
    
    case 3:
      // Transition to blinking red (states 3 and 4)
      digitalWrite(PGREEN, LOW);
      digitalWrite(PRED, HIGH);

      delay(500);
      state = 4;
      break;
    
    case 4:
      digitalWrite(PGREEN, LOW);
      digitalWrite(PRED, LOW);
      
      delay(500);
      state = 3;

      // Counter has reached 0: go to next state
      if (!--i) {
        state = 0;
        i = 50;  // Prepare for state 0
      }
  }
}

void blink() {
  state = 1;
}