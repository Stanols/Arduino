const int RED    = 9;
const int YELLOW = 10;
const int GREEN  = 11;

void setup() {
  pinMode(RED,    OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN,  OUTPUT);
}

void allOff() {
  digitalWrite(RED,    LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN,  LOW);
}

void loop() {
  allOff();
  digitalWrite(RED, HIGH);    // красный
  delay(5000);

  allOff();
  digitalWrite(YELLOW, HIGH); // жёлтый
  delay(2000);

  allOff();
  digitalWrite(GREEN, HIGH);  // зелёный
  delay(4000);

  allOff();
  digitalWrite(YELLOW, HIGH); // жёлтый перед красным
  delay(2000);
}