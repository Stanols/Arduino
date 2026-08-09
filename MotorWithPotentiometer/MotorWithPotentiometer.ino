#include <LiquidCrystal.h>;

const int rs = 4;
const int en = 5;

const int d4 = 6;
const int d5 = 7;
const int d6 = 8;
const int d7 = 9;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); //number of columns and rows
}

void loop() {
  lcd.setCursor(0, 0); // set the cursor to column 0, line 1, line 1 is the second row
  lcd.print("Hello!");
  lcd.setCursor(0, 1);
  lcd.print("I love Natashka!");
}
