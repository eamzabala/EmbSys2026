#define rLight 11
#define gLight 12
#define bLight 13
#define Switch 8
#define xAxis A0
#define yAxis A1

volatile byte state = 0;                                             // default is no editing
unsigned long timePressed = 0;
int color = 0;

int r = 0;
int g = 0;
int b = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Switch, INPUT);
  pinMode(rLight, OUTPUT);
  pinMode(gLight, OUTPUT);
  pinMode(bLight, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Switch), toggleState, FALLING);
}

void loop() {
  // setColor(255,255,255);
  if (state == 1) {                                                   // if stick was clicked, lets you edit color
    int xReading = analogRead(A0);                                    // reads x axis
    int yReading = analogRead(A1);                                    // reads y axis

    // cycle through colors thru x axis
    Serial.print("yTest: ");
    Serial.println(yReading);
    delay(1000);
    if (yReading > 600) {
      if (color == 2) {
        color = 0;
      } else {
        color += 1;
      }
    } else if (yReading < 500) {
      if (color == 0) {
        color = 2;
      } else {
        color -= 1;
      }
    } else {}
    switch (color){
      case 0:
        r = 255; 
        g = 0; 
        b = 0; 
        setColor(r, g, b);
        break;
      case 1:
        r = 0;
        g = 255; 
        b = 0; 
        setColor(r, g, b);
        break;
      case 2:
        r = 0; 
        g = 0; 
        b = 255; 
        setColor(r, g, b);
        break;
    }
    //Serial.println(color);
    //delay(1000);

    Serial.print("xTest: ");
    Serial.println(xReading);
    Serial.print("r: ");
    Serial.println(r);
    // inc or dec color value through y axis
    if (xReading > 600) {
      switch (color) {
        case 0:
          if (r < 255) {
            r++;
          } 
          break;
        case 1:
          if (g < 255) {
            g++;
          } 
          break;
        case 2:
          if (b < 255) {
            b++;
          } 
          break;
      }
    } else if (xReading < 500) {
      switch (color) {
        case 0:
          if (r > 0) {
            r -= 1;
          } 
          break;
        case 1:
          if (g > 0) {
            g--;
          } 
          break;
        case 2:
          if (b > 0) {
            b--;
          } 
          break;
      }
    }
  }

}


// void toggleState() {
//   Serial.println("PRESSED");

//   if(millis() - timePressed < 100) {
//     Serial.println("Cancelled Press!");
//     return;
//   }

//   timePressed = millis();

//   if (state == 0) {
//     state = 1;                                                        // stick pressed, edit color
//   } else {
//     state = 0;                                                        // stick pressed, stop edit
//   }
// }

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(rLight, redValue);
  analogWrite(gLight, greenValue);
  analogWrite(bLight, blueValue);
}