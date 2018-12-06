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
  lcd.setCursor(0,0);
  lcd.print(":)");
  Serial.begin(9600);
}
int updown=0;
int duzina=0;

void loop() {
  // put your main code here, to run repeatedly:
  int m=ocitajTaster();
  
  if (duzina>15) duzina=0;
  
  if (m==1) {
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print(":)");
    delay(500);
  }
  if (m==2) {
    duzina--;
    if(duzina<0) duzina=14;
    lcd.clear();
    lcd.setCursor(duzina,updown);
    lcd.print(":)");
    delay(500);
  }
  if (m==3) {
    updown++;
    if (updown>1) updown=0;  
    lcd.clear();
    lcd.setCursor(duzina,updown);
    lcd.print(":)");
    delay(500);
  }
  
  if (m==4) {
    
    updown--;
    if (updown<0) updown=1;
    lcd.clear();
    lcd.setCursor(duzina,updown);
    lcd.print(":)");
    delay(500);
  }
  
  if (m==5) {
    duzina++;
    if (duzina>14) duzina=0;
    lcd.clear();
    lcd.setCursor(duzina,updown);
    lcd.print(":)");
    delay(500);
  }
  
}
