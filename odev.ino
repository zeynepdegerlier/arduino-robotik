byte ledler[8] = {2, 3, 4, 5, 6, 7, 8, 9};


#define pot A10
int bekleme_suresi, pot_deger;

void setup() {
 for (int sayac = 0;sayac <8; sayac++) pinMode(ledler[sayac], OUTPUT);
}

void loop() {
  digitalWrite(ledler[0], HIGH);
digitalWrite(ledler[7], HIGH);
delay(1000);
digitalWrite(ledler[0], LOW);
digitalWrite(ledler[7], LOW);
digitalWrite(ledler[1], HIGH);
digitalWrite(ledler[6], HIGH);
delay(1000);
digitalWrite(ledler[1], LOW);
digitalWrite(ledler[6], LOW);
  digitalWrite(ledler[2], HIGH);
digitalWrite(ledler[5], HIGH);
delay(1000);
digitalWrite(ledler[2], LOW);
digitalWrite(ledler[5], LOW);
digitalWrite(ledler[3], HIGH);
digitalWrite(ledler[4], HIGH);
delay(1000);
digitalWrite(ledler[3], LOW);
digitalWrite(ledler[4], LOW);

}

  
