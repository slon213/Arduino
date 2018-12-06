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
  Serial.begin(9600);  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  
  lcd.print("Unesite CAPTCHA:");
}

  char randgen[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  char captcha[8];   //nasa capcha  
  int cap[8];      //indeksi elemenata iz randgen
  char uneti[8];

void loop() {
  int tast=0;
  tast=ocitajTaster();
  while (tast==1) {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Unesite CAPTCHA:");
  lcd.setCursor(0,1);
  // put your main code here, to run repeatedly:
  int duzina_cap = random(5,8);
  int sviel = sizeof(randgen)-1;
  int cap_indeks[duzina_cap];
  for (int i=0; i<duzina_cap; i++) {
    cap_indeks[i]=random(0, sviel);
    captcha[i]=randgen[cap_indeks[i]];
  }
  captcha[duzina_cap]='\0';
  lcd.print(captcha);
    Serial.println(captcha);
  while(!Serial.available()) {
    delay(100);
  }
  int x=Serial.available();
  char uneti[x];
  Serial.readBytes(uneti, x);
  uneti[x]='\0';
  lcd.setCursor(0,1);
  String prvi=captcha;
  String drugi=uneti;    


  
  if (prvi.equals(drugi)) {
        tast=0;
        lcd.print("ECCE HOMO!");
        while(tast==1){      
        delay(100);
        }
        lcd.setCursor(0,1);
      
  }
  if (!prvi.equals(drugi)) {
      tast=0;
      lcd.print("SENDVICAR");
      while(tast==1) {
         delay(100);  
      }
      lcd.setCursor(0,1);
  }
}  
  
  }

