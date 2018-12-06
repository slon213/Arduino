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

int des_posto=25;
int pre, sad;
int dim=255;
int proc;
void loop() {
  pre=sad;
  proc=dim/des_posto;
  sad=ocitajTaster();
  lcd.print(10*proc);
  lcd.setCursor(0,0);
  if (pre==0 && sad==4) {
    dim=dim+des_posto;
    if (dim>249) dim=255;
    analogWrite(10,dim);
    lcd.clear();
  }
  if (pre==0 && sad==3) {
    dim=dim-des_posto;
    if (dim<6) dim=0;
    analogWrite(10,dim);
    lcd.clear();
  }
}
