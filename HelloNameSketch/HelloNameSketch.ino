#include <LiquidCrystal.h>;

char *names[] = {"Katya", "Artsiom", "Natallia", "Dymusia"};
int index = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 1);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  for (int index = 0; index < 4; index++)
  {
    lcd.setCursor(0, 1);
    lcd.print("Hello, ");
    lcd.print(names[index]);

    delay(1000);
    lcd.clear();
    delay(1000);
  }

  index = 0;
}

