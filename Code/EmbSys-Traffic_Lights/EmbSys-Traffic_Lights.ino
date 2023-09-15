#define GREEN 13
#define YELLOW 12
#define RED 11
#define BUTTON 7
#define pRED 3
#define pGREEN 2
int buttonState = 0;


void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // digitalWrite(GREEN, HIGH);
  // digitalWrite(YELLOW, HIGH);
  // digitalWrite(RED, HIGH);
  // digitalWrite(pRED, HIGH);
  // digitalWrite(pGREEN, HIGH);

  // vehicle traffic lights
  if(buttonState == LOW){
    digitalWrite(pRED, HIGH);
    digitalWrite(GREEN, HIGH);
    for (int i = 0; i< 15; i++) {
      if (buttonState == LOW){
        buttonState = digitalRead(BUTTON);
      }
      delay(1000);
    }
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    delay(5000);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    if(buttonState == LOW){
      delay(20000);
    }
  } else {
    digitalWrite(pRED,LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(pGREEN, HIGH);
    delay(10000);
    digitalWrite(pGREEN, LOW);
    digitalWrite(pRED, HIGH);
    for (int i=0; i <10; i++) {
      delay(1000);
      digitalWrite(pRED, LOW);
      delay(1000);
      digitalWrite(pRED, HIGH);
    }
    buttonState = digitalRead(BUTTON);
  }
    digitalWrite(RED, LOW);
}
