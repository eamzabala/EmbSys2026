const byte GREEN = 13;
#define YELLOW 12
#define RED 11

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN, HIGH);
  delay(50);
  digitalWrite(YELLOW, HIGH);
  delay(50);
  digitalWrite(RED, HIGH);
  delay(50);
  digitalWrite(GREEN, LOW);
  delay(50);
  digitalWrite(YELLOW, LOW);
  delay(50);
  digitalWrite(RED, LOW);
  delay(50);
}
