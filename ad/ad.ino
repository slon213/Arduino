#include<LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int ocitajTaster() {
  int t = analogRead(0);
  if (t > 700 && t < 750) return 1; //SELECT
  if (t > 450 && t < 500) return 2; //LEFT
  if (t > 275 && t < 325) return 3; //DOWN
  if (t > 120 && t < 150) return 4; //UP
  if (t < 30) return 5;             //RIGHT
  else return 0;                    //NONE
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.cursor();
  lcd.blink();
}

char string[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?";
int index = 0;
int sirina = 0;
int pre, sad;
int maxi = sizeof(string) - 2;
void loop() {
  // put your main code here, to run repeatedly:
  pre = sad;
  sad = ocitajTaster();
  lcd.setCursor(sirina, 0);
  delay(10);
  lcd.print(string[index]);
  lcd.setCursor(sirina, 0);
  delay(10);
  if (pre == 0 && sad == 3) {
    index++;
    if (index > maxi) index = 0;
    lcd.print(string[index]);
  }
  if (pre == 0 && sad == 4) {
    index--;
    if (index < 0) index = maxi;
    lcd.print(string[index]);
  }
  if (pre == 0 && sad == 5) {
    sirina++;
    if (sirina > 15) sirina = 15;
    lcd.setCursor(sirina, 0);
    index = 0;
  }
  if (pre == 0 && sad == 2) {
    sirina--;
    if (sirina < 0) sirina = 0;
    lcd.setCursor(sirina, 0);
    index = 0;
  }
  if (sad == 1) {
    lcd.noCursor();
    lcd.noBlink();
    lcd.scrollDisplayRight();
    delay(100);
  }
}
