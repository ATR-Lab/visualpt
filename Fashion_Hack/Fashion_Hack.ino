#define GREENPIN1 9
#define REDPIN1 8
#define BLUEPIN1 10
#define GREENPIN2 12
#define BLUEPIN2 13
#define REDPIN2 11
#define GREENPIN3 3
#define BLUEPIN3 4
#define REDPIN3 2
//#define GREENPIN4
//#define BLUEPIN4
//#define REDPIN4
//#define GREENPIN5
//#define BLUEPIN5
//#define REDPIN5
//#define GREENPIN6
//#define BLUEPIN6
//#define REDPIN6
void setup()
{
  Serial.begin(9600);

  pinMode(BLUEPIN1, OUTPUT);
  pinMode(BLUEPIN2, OUTPUT);
  pinMode(BLUEPIN3, OUTPUT);
  //    pinMode(BLUEPIN4, OUTPUT);
  //    pinMode(BLUEPIN5, OUTPUT);
  //    pinMode(BLUEPIN6, OUTPUT);
  //
}
void loop()
{

  ///run first set of lights
  if (Serial.available() > 0) {
    String arry ;
    arry = Serial.readString();
    char a = arry[0];
    if (a == 'a') {
      runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 1);
    }
    if (a == 'b') {
      runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 2);
    }
    if (a == 'c') {
      runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 3);
    }
    if (a == 'd') {
      runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 1);
    }
    if (a == 'e') {
      runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 2);
    }
    if (a == 'f') {
      runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 3);
    }
    if (a == 'g') {
      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 1);
    }
    if (a == 'h') {
      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 2);
    }
    if (a == 'i') {
      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 3);
    }
    char b = arry[1];
    if (b == 'a') {
      runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 1);
    }
    if (b == 'b') {
      runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 2);
    }
    if (b == 'c') {
      runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 3);
    }
    if (b == 'd') {
      runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 1);
    }
    if (b == 'e') {
      runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 2);
    }
    if (b == 'f') {
      runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 3);
    }
    if (b == 'g') {
      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 1);
    }
    if (b == 'h') {
      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 2);
    }
    if (b == 'i') {
      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 3);
    }





    char c = arry[2];
    if (c == 'a') {
      runBlue(BLUEPIN3, GREENPIN3, REDPIN3, 1);
    }
    if (c == 'b') {
      runBlue(BLUEPIN3, GREENPIN3, REDPIN3, 2);
    }
    if (c == 'c') {
      runBlue(BLUEPIN3, GREENPIN3, REDPIN3, 3);
    }
    if (c == 'd') {
      runGreen(GREENPIN3, BLUEPIN3, REDPIN3, 1);
    }
    if (c == 'e') {
      runGreen(GREENPIN3, BLUEPIN3, REDPIN3, 2);
    }
    if (c == 'f') {
      runGreen(GREENPIN3, BLUEPIN3, REDPIN3, 3);
    }
    if (c == 'g') {
      runRed(REDPIN3, GREENPIN3, BLUEPIN3, 1);
    }
    if (c == 'h') {
      runRed(REDPIN3, GREENPIN3, BLUEPIN3, 2);
    }
    if (c == 'i') {
      runRed(REDPIN3, GREENPIN3, BLUEPIN1, 3);
    }


    //  ///controls the fourth set of lights
    //    char d = arry[3];
    //    if (d == 'a') {
    //      runBlue(BLUEPIN4, GREENPIN4, REDPIN4, 1);
    //    }
    //    if (d == 'b') {
    //      runBlue(BLUEPIN4, GREENPIN4, REDPIN4, 2);
    //    }
    //    if (d == 'c') {
    //      runBlue(BLUEPIN4, GREENPIN4, REDPIN4, 3);
    //    }
    //    if (d == 'd') {
    //      runGreen(GREENPIN4, BLUEPIN4, REDPIN4, 1);
    //    }
    //    if (d == 'e') {
    //      runGreen(GREENPIN4, BLUEPIN4, REDPIN4, 2);
    //    }
    //    if (d == 'f') {
    //      runGreen(GREENPIN4, BLUEPIN4, REDPIN4, 3);
    //    }
    //    if (d == 'g') {
    //      runRed(REDPIN4, GREENPIN4, BLUEPIN4, 1);
    //    }
    //    if (d == 'h') {
    //      runRed(REDPIN4, GREENPIN4, BLUEPIN4, 2);
    //    }
    //    if (d == 'i') {
    //      runRed(REDPIN1, GREENPIN1, BLUEPIN1, 3);
    //    }
    //
    //
    //  /////controls the fifth set of lights
    //    char e = arry[4];
    //    if (e == 'a') {
    //      runBlue(BLUEPIN5, GREENPIN5, REDPIN1, 5);
    //    }
    //    if (e == 'b') {
    //      runBlue(BLUEPIN5, GREENPIN5, REDPIN5, 2);
    //    }
    //    if (e == 'c') {
    //      runBlue(BLUEPIN5, GREENPIN5, REDPIN5, 3);
    //    }
    //    if (e == 'd') {
    //      runGreen(GREENPIN5, BLUEPIN5, REDPIN5, 1);
    //    }
    //    if (e == 'e') {
    //      runGreen(GREENPIN5, BLUEPIN5, REDPIN5, 2);
    //    }
    //    if (e == 'f') {
    //      runGreen(GREENPIN5, BLUEPIN5, REDPIN5, 3);
    //    }
    //    if (e == 'g') {
    //      runRed(REDPIN5, GREENPIN5, BLUEPIN5, 1);
    //    }
    //    if (e == 'h') {
    //      runRed(REDPIN5, GREENPIN5, BLUEPIN5, 2);
    //    }
    //    if (e == 'i') {
    //      runRed(REDPIN5, GREENPIN5, BLUEPIN5, 3);
    //    }
    //
    //
    //  ///controls the sixth set of lights
    //    char f = arry[5];
    //    if (f == 'a') {
    //      runBlue(BlUEPIN6, GREENPIN6, REDPIN6, 1);
    //    }
    //    if (f == 'b') {
    //      runBlue(BlUEPIN6, GREENPIN6, REDPIN6, 2);
    //    }
    //    if (f == 'c') {
    //      runBlue(BlUEPIN6, GREENPIN6, REDPIN6, 3);
    //    }
    //    if (f == 'd') {
    //      runGreen(GREENPIN6, BLUEPIN6, REDPIN6, 1);
    //    }
    //    if (f == 'e') {
    //      runGreen(GREENPIN6, BLUEPIN6, REDPIN6, 2);
    //    }
    //    if (f == 'f') {
    //      runGreen(GREENPIN6, BLUEPIN6, REDPIN6, 3);
    //    }
    //    if (f == 'g') {
    //      runRed(REDPIN6, GREENPIN6, BLUEPIN6, 1);
    //    }
    //    if (f == 'h') {
    //      runRed(REDPIN6, GREENPIN6, BLUEPIN6, 2);
    //    }
    //    if (f == 'i') {
    //      runRed(REDPIN6, GREENPIN6, BLUEPIN6, 3);
    //    }
    //  }
    //
    //    digitalWrite(REDPIN1, LOW);
    //    digitalWrite(BLUEPIN1, LOW);
    //    digitalWrite(GREENPIN1, LOW);
    //    delay(1000);
    //  }
    //
    //
    //
    ////  digitalWrite(REDPIN1,LOW);
    ////  digitalWrite(GREENPIN1, LOW);
    //  runBlue(BLUEPIN1,GREENPIN1, REDPIN1, 0);
    //  ///delay(10000);
    //  runBlue(BLUEPIN1, GREENPIN1, REDPIN1, 10);
    //  ///delay(1000);
    //  runBlue(BLUEPIN1, GREENPIN1, REDPIN1,10);
    //  ///delay(1000);
    //  runBlue(BLUEPIN1, GREENPIN1, REDPIN1,21);
    //  ///delay(500);
    //  runBlue(BLUEPIN1,GREENPIN1, REDPIN1, 21);
    //  ///delay(500);
    //  runBlue(BLUEPIN1,GREENPIN1, REDPIN1, 21);
    //  ///delay(500);
    //
    //
    //  runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 30);
    //  ///delay(10000);
    //  runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 40);
    //  ///delay(1000);
    //  runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 40);
    //  ///delay(1000);
    //  runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 51);
    //  ///delay(500);
    //  runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 51);
    //  ///delay(500);
    //  runGreen(GREENPIN1, BLUEPIN1, REDPIN1, 51);
    //
    //
    //  runRed(REDPIN1, GREENPIN1, BLUEPIN1, 60);
    //  ///delay(10000);
    //  runRed(REDPIN1, GREENPIN1, BLUEPIN1, 70);
    //  ///delay(1000);
    //  runRed(REDPIN1, GREENPIN1, BLUEPIN1, 70);
    //  ///delay(1000);
    //  runRed(REDPIN1, GREENPIN1, BLUEPIN1, 81);
    //  ///delay(500);
    //  runRed(REDPIN1, GREENPIN1, BLUEPIN1, 81);
    //  ///delay(500);
    //  runRed(REDPIN1, GREENPIN1, BLUEPIN1, 81);

    //      int a=1000;///////////any thing between 0-255
    //      digitalWrite(GREENPIN1,HIGH);
    //      delay(a);
    //      digitalWrite(GREENPIN1,LOW);
    //      delay(a);
    //      digitalWrite(REDPIN1,LOW);
    //      delay(a);
    //      digitalWrite(REDPIN1,HIGH);
    //      delay(a);
    //      digitalWrite(BLUEPIN1,HIGH);
    //      delay(a);
    //      digitalWrite(BLUEPIN1,LOW);
    //      delay(a);
  }
}


///turns on blue to proper blink and turns red and green off
void runBlue(int bluePin, int greenPin, int redPin, int select) {

  if (select == 1) {
    pinMode(bluePin, OUTPUT);
  }
  if (select == 2) {
    digitalWrite(bluePin, HIGH);
    delay(500);
    digitalWrite(bluePin, LOW);
    delay(500);
    digitalWrite(bluePin, HIGH);
    delay(500);
    digitalWrite(bluePin, LOW);
    delay(500);
  }
  if (select == 3) {
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
    delay(100);
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
    delay(100);
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
    delay(100);
  }
}
///turns on green to proper blink, turns red and blue off
void runGreen(int greenPin, int bluePin, int redPin, int select) {
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, LOW);
  pinMode(redPin, LOW);
  if (select == 1) {
    pinMode(greenPin, OUTPUT);
  }
  if (select == 2) {
    digitalWrite(greenPin, HIGH);
    delay(500);
    digitalWrite(greenPin, LOW);
    delay(500);
    digitalWrite(greenPin, HIGH);
    delay(500);
    digitalWrite(greenPin, LOW);
    delay(500);
  }
  if (select == 3) {
    digitalWrite(greenPin, HIGH);
    delay(100);
    digitalWrite(greenPin, LOW);
    delay(100);
    digitalWrite(greenPin, HIGH);
    delay(100);
    digitalWrite(greenPin, LOW);
    delay(100);
    digitalWrite(greenPin, HIGH);
    delay(100);
    digitalWrite(greenPin, LOW);
    delay(100);
  }
}
////turns on the red to proper blink and shuts off blue and green
void runRed(int redPin, int greenPin, int bluePin, int select) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, INPUT);
  pinMode(bluePin, INPUT);
  if (select == 1) {
    pinMode(redPin, OUTPUT);
  }
  if (select == 2) {
    digitalWrite(redPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    delay(500);
    digitalWrite(redPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    delay(500);
  }
  if (select == 3) {
    digitalWrite(redPin, HIGH);
    delay(100);
    digitalWrite(redPin, LOW);
    delay(100);
    digitalWrite(redPin, HIGH);
    delay(100);
    digitalWrite(redPin, LOW);
    delay(100);
    digitalWrite(redPin, HIGH);
    delay(100);
    digitalWrite(redPin, LOW);
    delay(100);
  }
}

//void turnOffAll() {
//  digitalWrite(REDPIN1, LOW);
//  pinMode(REDPIN1, INPUT);
//  digitalWrite(BLUEPIN1, LOW);
//  pinMode(BLUEPIN1, INPUT);
//  digitalWrite(GREENPIN1, LOW);
//  pinMode(GREENPIN1, INPUT);
//  Serial.println("off");
//}
