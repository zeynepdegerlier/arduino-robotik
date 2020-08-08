byte ledler[8] = {2, 3, 4, 5, 6, 7, 8, 9};


#define pot A10
int bekleme_suresi, pot_deger;

void setup() {
 for (int sayac = 0;sayac <8; sayac++) pinMode(ledler[sayac], OUTPUT);
}

void loop() {
  for (int sayac = 0; sayac <8; sayac++){
    digitalWrite(ledler[sayac], HIGH);
   digitalWrite(ledler[sayac-2], LOW);
    pot_deger = analogRead(pot);
    bekleme_suresi =map(pot_deger, 0, 1023, 50, 500);
    delay(bekleme_suresi);
  }
 digitalWrite(ledler[6], LOW); 
delay(bekleme_suresi);
digitalWrite(ledler[7], LOW);
}
