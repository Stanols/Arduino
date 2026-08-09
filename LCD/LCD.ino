#include <LiquidCrystal.h>;

const int rs = 12;
const int en = 11;

const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pinX = A0;
const int pinY = A1;
const int pinSW = 6;


void setup() {
  lcd.begin(16, 2); //number of columns and rows

  Serial.begin(9600);
  pinMode(pinSW, INPUT_PULLUP);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);

  int x = analogRead(pinX);      // 0..1023
  int y = analogRead(pinY);      // 0..1023
  bool pressed = digitalRead(pinSW) == LOW;

  lcd.setCursor(0, 0); // set the cursor to column 0, line 1, line 1 is the second row
  String line = "X: " + String(x) + "  Y: " + String(y);
  lcd.print(line);

  lcd.setCursor(0, 1);
  lcd.print(pressed ? "on" : "off");

  delay(200);
}

