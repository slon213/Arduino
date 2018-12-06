#include<LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int ocitajTaster() {

  int t = analogRead(0);
  if (t > 700 && t < 750) return 1; //SELECT
  if (t > 450 && t < 500) return 2; //LEFT
  if (t > 275 && t < 325) return 3; //DOWN
  if (t > 120 && t < 150) return 4; //UP
  if (t < 15) return 5;             //RIGHT
  else return 0;                    //NONE
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  //lcd.cursor();
  //lcd.blink();
}

int dicesn = 0;
int diceso = 0;
int pre, sad;
int sirina = 0;
int kockan[3] = {0, 0, 0};
int kockao[3] = {0, 0, 0};
int temp = 0;
int operacija = 0;

void loop() {

  pre = sad;
  sad = ocitajTaster();
  delay(10);
  if (pre == 0 && sad == 1) {
    operacija++;

  }
  /// pre nego sto je pritisnut taster Select:
  while (operacija == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Napad   ");
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 4) {
      dicesn++;
      if (dicesn > 3) dicesn = 1;
    }
    if (pre == 0 && sad == 3) {
      dicesn--;
      if (dicesn < 1) dicesn = 3;
    }
    lcd.setCursor(8, 0);
    lcd.print(dicesn);
    //provera da li je pritisnut taster select, ako jeste, onda nasilno izadji iz petlje
    if (pre == 0 && sad == 1) {
      operacija++;
    }
  }
  //nakon izlaska iz petlje, ispisuje dalje sta treba
  int temp = 1;
  lcd.setCursor(9, 0);
  lcd.print("> ");
  while (operacija <= dicesn) {
    if (operacija == 1) {
      while (operacija == 1) {
        lcd.setCursor(11, 0);
        temp++;
        if (temp > 6) temp = 1;
        lcd.print(temp);
        delay(100);
        kockan[0] = temp;
        pre = sad;
        sad = ocitajTaster();
        if (pre == 0 && sad == 1) {
          operacija++;
        }
      }
    }
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 1) {
      operacija++;
    }
    if (operacija > dicesn) break;
    if (operacija == 2) {
      while (operacija == 2) {
        lcd.setCursor(13, 0);
        temp++;
        if (temp > 6) temp = 1;
        lcd.print(temp);
        delay(100);
        kockan[1] = temp;
        pre = sad;
        sad = ocitajTaster();
        if (pre == 0 && sad == 1) {
          operacija++;
        }
      }
    }
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 1) {
      operacija++;
    }
    if (operacija > dicesn) break;
    if (operacija == 3) {
      while (operacija == 3) {
        lcd.setCursor(15, 0);
        temp++;
        if (temp > 6) temp = 1;
        lcd.print(temp);
        delay(100);
        kockan[2] = temp;
        pre = sad;
        sad = ocitajTaster();
        if (pre == 0 && sad == 1) {
          operacija++;
        }
      }
    }
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 1) {
      operacija++;
    }
    if (operacija > dicesn) break;
  }
  //odbrana
  operacija = 0;
  if (pre == 0 && sad == 1) {
    operacija++;
  }
  while (operacija == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Odbrana ");
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 4) {
      diceso++;
      if (diceso > 3) diceso = 1;
    }
    if (pre == 0 && sad == 3) {
      diceso--;
      if (diceso < 1) diceso = 3;
    }
    lcd.setCursor(8, 1);
    lcd.print(diceso);
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 1) {
      operacija++;
    }
    if (operacija > dicesn + 1) break;
  }
  temp = 1;
  lcd.setCursor(9, 1);
  lcd.print("> ");

  while (operacija <= 3) {
    if (operacija == 1) {
      while (operacija == 1) {
        lcd.setCursor(11, 1);
        temp++;
        if (temp > 6) temp = 1;
        lcd.print(temp);
        delay(100);
        kockao[0] = temp;
        pre = sad;
        sad = ocitajTaster();
        if (pre == 0 && sad == 1) {
          operacija++;
        }
      }
    }
    pre = sad;
    sad = ocitajTaster();

    if (pre == 0 && sad == 1) {
      operacija++;
    }

    if (operacija > 3) break;

    if (operacija == 2) {
      while (operacija == 2) {
        lcd.setCursor(13, 1);
        temp++;
        if (temp > 6) temp = 1;
        lcd.print(temp);
        delay(100);
        kockao[1] = temp;
        pre = sad;
        sad = ocitajTaster();
        if (pre == 0 && sad == 1) {
          operacija++;
        }
      }
    }
    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 1) {
      operacija++;
    }

    if (operacija > 3) break;

    if (operacija == 3) {
      while (operacija == 3) {
        lcd.setCursor(15, 1);
        temp++;
        if (temp > 6) temp = 1;
        lcd.print(temp);
        delay(100);
        kockao[2] = temp;
        pre = sad;
        sad = ocitajTaster();
        if (pre == 0 && sad == 1) {
          operacija++;
        }
      }
    }

    pre = sad;
    sad = ocitajTaster();
    if (pre == 0 && sad == 1) {
      operacija++;
    }
    if (operacija > 3) break;
  }
}

