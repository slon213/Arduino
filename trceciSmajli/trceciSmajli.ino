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

byte smajli [8] = {
    B00000 ,
    B01010 ,
    B00000 ,
    B00000 ,
    B10001 ,
    B01110 ,
    B00000 ,
};

void setup() {
  lcd.begin(16,2);
}

int sirina=0;
int dole=0;
int sada, pre;

void loop() {
  pre=sada;
  sada=ocitajTaster();
  if (sada==1 && pre==0) {
    lcd.createChar(0,smajli);
    lcd.setCursor(0,0);
    lcd.write(byte(0));
  }

  if (sada==5 && pre==0) {
    sirina++;
    if (sirina>15) sirina=0;
    lcd.clear();
    lcd.setCursor(sirina,dole);
    lcd.write(byte(0));
    delay(50);
  }
  if (sada==2 && pre==0) {
    sirina--;
    if (sirina<0) sirina=15;
    lcd.clear();
    lcd.setCursor(sirina,dole);
    lcd.write(byte(0));
    delay(50);
  }
  if (sada==4 && pre==0) {
    dole--;
    if (dole<0) dole=1;
    lcd.clear();
    lcd.setCursor(sirina,dole);
    lcd.write(byte(0));
    delay(50);
  }
  if (sada==3 && pre==0) {
    dole++;
    if(dole>1) dole=0;
    lcd.clear();
    lcd.setCursor(sirina,dole);
    lcd.write(byte(0));
    delay(50);
  }
}
