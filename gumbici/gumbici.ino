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
  lcd.begin(16,2);
}

int sada;
int pre;
int inc=0;

void loop() {
  pre=sada;
  sada=ocitajTaster();
  if (sada==3 && pre==0) {
    inc--;
    lcd.clear();
  }
  if (sada==4 && pre==0) {
    inc++;
    lcd.clear();
  }
  if (sada==1 && pre==0) {
    inc=0;
    lcd.clear();
  }
  lcd.setCursor(0,0);
  lcd.print(inc);
}
