byte ledler[8] = {2, 3, 4, 5, 6, 7, 8, 9};


#define pot A10
int bekleme_suresi, pot_deger;

void setup() {
  for (int sayac = 0; sayac < 8; sayac++) pinMode(ledler[sayac], OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledler[i], HIGH);
    digitalWrite(ledler[7 - i], HIGH);
    delay(1000);
    digitalWrite(ledler[i], LOW);
    digitalWrite(ledler[7 - i], LOW);
  }
}
