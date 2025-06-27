#include <Servo.h>
#include <string.h>
Servo myservo;
char hamud = 'M';
int MahmudMotor1 = 8;
int MahmudMotor2 = 9;
int MahmudMotor3 = 10;
int MahmudMotor4 = 12;
int MahmudDevirR = 11;
int MahmudDevirL = 6;
int x = 1;

int numericValue = 0; // Sayısal değeri tutacak değişken
int numericR = 0;
int numericL = 0;
float factorR = 1;
float factorL = 1;
bool factor = true;
String receivedString = ""; // Gelen veriyi tutacak string

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(MahmudMotor1, OUTPUT);
  pinMode(MahmudMotor2, OUTPUT);
  pinMode(MahmudMotor3, OUTPUT);
  pinMode(MahmudMotor4, OUTPUT);
  myservo.attach(3);

}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available()) {

    delay(10);
    hamud = Serial.read();

    if (hamud == 'J') {
      delay(10);
      // String değişkenine devamını ekle
      while (Serial.available() > 0) {
        char c = Serial.read(); // Bir karakter daha oku
        delay(10);
        if (isdigit(c)) { // Eğer bu karakter bir rakamsa
          receivedString += c; // Stringe ekle
        } else {
          break; // Rakam değilse döngüden çık
        }
      }
      delay(10);
      numericValue = receivedString.toInt();
      numericValue = 255 * numericValue / 8;
      numericR = numericValue * factorR;
      numericL = numericValue * factorL;

      analogWrite(MahmudDevirR, numericR); // sag motor devri
      analogWrite(MahmudDevirL, numericL); // sol motor devri
      receivedString = "";
    }

    if (hamud == 'M') {
      digitalWrite(MahmudMotor1 , LOW);
      digitalWrite(MahmudMotor2 , HIGH);
      digitalWrite(MahmudMotor3 , LOW);
      digitalWrite(MahmudMotor4 , HIGH);
    }

    if (hamud == 'm') {
      digitalWrite(MahmudMotor1 , HIGH);
      digitalWrite(MahmudMotor2 , LOW);
      digitalWrite(MahmudMotor3 , HIGH);
      digitalWrite(MahmudMotor4 , LOW);
    }

    if (hamud == 'R') {
      myservo.write(45);
      if (255 >= (numericL + 60)) {   //dönüs destegi zit motora güc takviyesi
        analogWrite(MahmudDevirL, numericL + 60);
      }
    }

    if (hamud == 'S') {
      myservo.write(90);
      analogWrite(MahmudDevirR, numericR); // sag motor devri dengelendi
      analogWrite(MahmudDevirL, numericL); // sol motor devri dengelendi
    }

    if (hamud == 'L') {
      myservo.write(135);
      if (255 >= (numericR + 60)) {   //dönüs destegi zit motora güc takviyesi
        analogWrite(MahmudDevirR, numericR + 60);
      }
    }

    if (hamud == 'Y' && factor == true) {   //motor dengesi sol motoru zayiflatma (sağa yöneltme)
      factor == false;
      factorR = 0.9 * factorR;
      numericR *= factorR;
      analogWrite(MahmudDevirR, numericR);
    }

    if (hamud == 'X' && factor == true) {   //motor dengesi sağ motoru zayiflatma (sola yöneltme)
      factor == false;
      factorL = 0.9 * factorL;
      numericL *= factorL;
      analogWrite(MahmudDevirL, numericL);
    }

    if (hamud == 'x' || hamud == 'y') {
      factor == true;
    }

    if (hamud == 'N' || hamud == 'n') {
      factorR = 1; factorL =1;
      numericR = numericValue;
      numericL = numericValue;
      analogWrite(MahmudDevirR, numericR);
      analogWrite(MahmudDevirL, numericL);
    }
  }
}
