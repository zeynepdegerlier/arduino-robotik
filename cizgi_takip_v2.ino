#define sag_sensor A8
#define orta_sensor A7
#define sol_sensor A6

#define INA1 38
#define INA2 36
#define INB1 42
#define INB2 40
#define PWMA 44
#define PWMB 46

bool sol_deger, orta_deger, sag_deger;
byte son_durum;

void ileri(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}


void tank_sag(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 1);
  analogWrite (PWMB, hiz);
}

void tank_sol(int hiz) {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 1);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}
void sag(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}

void sol(int hiz) {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}
void dur() {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, 0);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, 0);
}
void geri(int hiz) {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 1);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 1);
  analogWrite (PWMB, hiz);
}

void setup() {
  Serial.begin(9600);

  pinMode(INA1, OUTPUT); // Sensör ve Motorların Giriş-Çıkış bilgilerini belirtiyoruz.
  pinMode(INA2, OUTPUT);

  pinMode(INB1, OUTPUT);
  pinMode(INB2, OUTPUT);
}

void loop() {
  sol_deger = analogRead(sol_sensor) > 500 ? 1 : 0;
  orta_deger = analogRead(orta_sensor) > 500 ? 1 : 0;
  sag_deger = analogRead(sag_sensor) > 500 ?  : 0;
  Serial.print(sol_deger);
  Serial.print('-');
  Serial.print(orta_deger);
  Serial.print('-');
  Serial.println(sag_deger);
  if (sol_deger && orta_deger && sag_deger) {
    if (son_durum != 2) {
      geri(175);
      delay(200);
    }
    while ((sol_deger && orta_deger && sag_deger) || (!sol_deger && !orta_deger && !sag_deger)) {
      sol_deger = analogRead(sol_sensor) > 500 ? 1 : 0;
      orta_deger = analogRead(orta_sensor) > 500 ? 1 : 0;
      sag_deger = analogRead(sag_sensor) > 500 ?  : 0;
      if (son_durum == 0) tank_sag(150);
      else if (son_durum == 1) tank_sol(150);
      else if (son_durum == 2) ileri(255);
    }
  }
  else if ((sol_deger && !orta_deger && !sag_deger) || (sol_deger && orta_deger && !sag_deger)) {
    son_durum = 0;
    sag(170);
  }
  else if ((!sol_deger && orta_deger && sag_deger) || (!sol_deger && !orta_deger && sag_deger)) {
    son_durum = 1;
    sol(170);
  }
  else if (sol_deger && !orta_deger && sag_deger) {
    son_durum = 2;
    ileri(255);
  }
}
