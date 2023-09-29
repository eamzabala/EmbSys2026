int x;
const byte r1 = 7;
const byte r2 = 6;
const byte y1 = 11;
const byte g1 = 12;
const byte g2 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
}

void loop() { 
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(y1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(g2, LOW);

  x = analogRead(A0);           
  Serial.println(x);            
  if (x >= 700 && x < 799){           // NORMAL
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(y1, HIGH);
    digitalWrite(g1, LOW);
   digitalWrite(g2, LOW);
  } else if (x > 399 && x < 700) {    // DARK
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(y1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, LOW);
  } else if (x >= 0 && x < 400) {     // DARKEST
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, LOW);
  } else if (x >= 800 && x < 900){    // BRIGHT
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(y1, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, LOW);
  } else {                            // BRIGHTEST
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(y1, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
  }
  delay(1000);
}