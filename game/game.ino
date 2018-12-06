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

byte cikica[8] = {
  B00100,
  B01110,
  B00100,
  B11111,
  B00100,
  B00100,
  B01010,
  B01010
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0, cikica);
}

int lifes = 0;
int pre, sad, xkoor, ykoor;
char mapa[16][2];

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.write(byte(0));

  lifes=1;
  for (int i=0; i<4; i++) {
    
  }
  
  while (lifes==1) {
    
    pre=sad;
    sad=ocitajTaster();
        
  }
}
