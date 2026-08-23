#include <LiquidCrystal.h>;
#include <SPI.h>;
#include <MFRC522.h>

//LCD
const int rs = 12;
const int en = 11;
const int d5 = 5;
const int d4 = 4;
const int d3 = 3;
const int d2 = 2;
LiquidCrystal lcd(rs, en, d5, d4, d3, d2);

//traffic lights
const int greenD31 = 31;
const int yellowD33 = 33;
const int redD35 = 35;

//joistic input
const int pinX = A0;
const int pinY = A1;
const int pinSW = 6;

//RFID
const int d7 = 7;
const int d8 = 8;
const int d9 = 9;
const int d10 = 10;

#define SS_PIN  53
#define RST_PIN 49

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);

  //LCD number of columns and rows
  lcd.begin(16, 2);
  pinMode(pinSW, INPUT_PULLUP);

  //trafic lights
  pinMode(greenD31, OUTPUT);
  pinMode(yellowD33, OUTPUT);
  pinMode(redD35, OUTPUT);

  //RFID
  Serial.begin(9600);
  while (!Serial);      // wait for Serial Monitor to open
  SPI.begin();
  rfid.PCD_Init();
  rfid.PCD_DumpVersionToSerial();
  Serial.println("Scan a card/tag...");
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

  delay(100);

  digitalWrite(redD35, HIGH);
  delay(100);
  digitalWrite(redD35, LOW);
  delay(100);
  digitalWrite(yellowD33, HIGH);
  delay(100);

  digitalWrite(yellowD33, LOW);
  delay(100);
  digitalWrite(greenD31, HIGH);
  delay(100);
  digitalWrite(greenD31, LOW);

  //RFID
  if (!rfid.PICC_IsNewCardPresent()) return;
  // Select the card
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  rfid.PICC_HaltA();
}

