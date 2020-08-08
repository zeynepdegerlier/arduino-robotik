


#include <IRremote.h>











#define INA1 38
#define INA2 36
#define INB1 42
#define INB2 40
#define PWMA 44
#define PWMB 46

#define on_far 51
#define arka_far 48
#define sol_sinyal 53
#define sag_sinyal 49

#define ileri_tus 0xFF18E7
#define geri_tus 0xFF4AB5
#define sag_tus 0xFF5AA5
#define sol_tus 0xFF10EF
#define ok_tus 0xFF38C7
#define bir 0xFFA25D

#define RECV_PIN 12

IRrecv irrecv(RECV_PIN);
decode_results results;

bool far_durum = 0;

void ileri(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}

void geri(int hiz) {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 1);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 1);
  analogWrite (PWMB, hiz);
}

void sag1(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 1);
  analogWrite (PWMB, hiz);
}
void sol1(int hiz) {
  digitalWrite (INA1, 0);
  digitalWrite (INA2, 1);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 1);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}

void sag2(int hiz) {
  digitalWrite (INA1, 1);
  digitalWrite (INA2, 0);
  analogWrite (PWMA, hiz);

  digitalWrite (INB1, 0);
  digitalWrite (INB2, 0);
  analogWrite (PWMB, hiz);
}

void sol2(int hiz) {
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


void setup() {
  Serial.begin(9600);
  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(INB2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(on_far, OUTPUT);
  pinMode(arka_far, OUTPUT);
  pinMode(sag_sinyal, OUTPUT);
  pinMode(sol_sinyal, OUTPUT);

  irrecv.enableIRIn();

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  if (results.value == ileri_tus) {
    ileri(255);
    digitalWrite(arka_far, LOW);
    digitalWrite(sag_sinyal, LOW);
    digitalWrite(sol_sinyal, LOW);
    delay(100);
  }
  else if (results.value == geri_tus) {
    geri(255);
    digitalWrite(arka_far, HIGH);
    digitalWrite(sag_sinyal, LOW);
    digitalWrite(sol_sinyal, LOW);
    delay(100);
  }
  else if (results.value == sag_tus) {
    sag2(255);
    digitalWrite(arka_far, LOW);
    digitalWrite(sag_sinyal, HIGH);
    digitalWrite(sol_sinyal, LOW);
    delay(100);
  }
  else if (results.value == sol_tus) {
    sol2(255);
    digitalWrite(arka_far, LOW);
    digitalWrite(sol_sinyal, HIGH);
    digitalWrite(sag_sinyal, LOW);
    delay(100);
  }
  else if (results.value == ok_tus) {
    dur();
    digitalWrite(arka_far, LOW);
    digitalWrite(sag_sinyal, LOW);
    digitalWrite(sol_sinyal, LOW);
    delay(100);
  }
  else if (results.value == bir) {
    far_durum = !far_durum;
    Serial.println(far_durum);
    results.value = 0;
  }
  digitalWrite(on_far, far_durum);

}
