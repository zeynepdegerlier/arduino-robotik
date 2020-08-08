#define SensorSol A6
#define SensorOrta A7
#define SensorSag A8

#define pot A10
int hiz, pot_deger, led_deger;
#define INA1 38
#define INA2 36
#define INB1 42
#define INB2 40
#define PWMA 44
#define PWMB 46

#define red 11
#define green 12

#define on_far 51
#define arka_far 48
#define sol_sinyal 53
#define sag_sinyal 49

void ileri(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);

  digitalWrite(on_far, HIGH);
  digitalWrite(arka_far, LOW);
  digitalWrite(sol_sinyal, LOW);
  digitalWrite(sag_sinyal, LOW);
}


void sag1(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 1);
  analogWrite (PWMB, hiz);

  digitalWrite(on_far, LOW);
  digitalWrite(arka_far, LOW);
  digitalWrite(sol_sinyal, LOW);
  digitalWrite(sag_sinyal, HIGH);
}


void sol1(int hiz) {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 1);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);

  digitalWrite(on_far, LOW);
  digitalWrite(arka_far, LOW);
  digitalWrite(sol_sinyal, HIGH);
  digitalWrite(sag_sinyal, LOW);
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

  digitalWrite(on_far, LOW);
  digitalWrite(arka_far, HIGH);
  digitalWrite(sol_sinyal, LOW);
  digitalWrite(sag_sinyal, LOW);
}

void setup() {

  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(INA1, OUTPUT); // Sensör ve Motorların Giriş-Çıkış bilgilerini belirtiyoruz.
  pinMode(INA2, OUTPUT);

  pinMode(INB1, OUTPUT);
  pinMode(INB2, OUTPUT);

  pinMode(on_far, OUTPUT);
  pinMode(arka_far, OUTPUT);
  pinMode(sag_sinyal, OUTPUT);
  pinMode(sol_sinyal, OUTPUT);

}

void loop() {

  pot_deger = analogRead(pot);
  hiz = map(pot_deger, 0, 1023, 125, 255);
  led_deger = map(pot_deger, 0, 1023, 0, 255);

  analogWrite(red, 255-led_deger);
  analogWrite(green, led_deger);

  if (pot_deger == 0) {
    dur();
  }

  else if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0) { // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
    ileri(hiz);
  }

  else if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1) { // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
    sag1(hiz);
  }

  else if (digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0) { // Sol sensör çizgiyi gördüğünde robot sola dönsün.
    sol1(hiz);
  }

  else if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0) {
    geri(hiz);
  }
  else if (digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1) {
    sag1(hiz);
  }
  else if (digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1) {
    dur();
  }
  else if (digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0) {
    sol1(hiz);
  }


}
