#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

int ocitajTaster() {
  int t = analogRead(0);
  if (t>700 && t<750) return 1;     //SELECT
  if (t>450 && t<500) return 2;     //LEFT
  if (t>275 && t<325) return 3;     //DOWN
  if (t>120 && t<150) return 4;     //UP
  if (t<30) return 5;               //RIGHT
  else return 0;                    //NONE
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(0,0);
}
char c='a';
char start=' ';
int sirina=0;
  
void loop() {
  // put your main code here, to run repeatedly:
  int taster=ocitajTaster();
  lcd.setCursor(sirina,0);
  delay(10);
  lcd.print(c);
  lcd.setCursor(sirina,0);
  delay(100);

  if (taster==3) {
    c++;
    if (c>'z') c='a';
    //lcd.print(c);
    delay(200);
  }
  if (taster==4) {
    c--;
    if (c<'a') c='z';
    lcd.print(c);
    delay(200);
  }
  if (taster==5) {
    sirina++;
    if (sirina>15) sirina=15;
    lcd.setCursor(sirina,0);
    delay(200);
  }
  
  if (taster==2) {
    sirina--;
    if (sirina<0) sirina=0;
    lcd.setCursor(sirina,0);
    delay(200);
  }

  if (taster==1) {
    lcd.noCursor();
    lcd.noBlink();
    lcd.scrollDisplayRight();
    delay(10);
  }
}
