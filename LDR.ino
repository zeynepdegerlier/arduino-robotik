byte ledler[8] = {2, 3, 4, 5, 6, 7, 8, 9};


#define ldr A9
int ldr_deger, led_sayisi;

void setup() {
  for (int sayac = 0; sayac < 8; sayac++) pinMode(ledler[sayac], OUTPUT);
}

void loop() {
  ldr_deger = analogRead(ldr);
  led_sayisi = map(ldr_deger, 0, 900, 0, 8);
  for (int sayac = 0; sayac < led_sayisi; sayac++) digitalWrite (ledler[sayac], HIGH);
  for (int sayac = led_sayisi; sayac < 8; sayac++) digitalWrite(ledler[sayac], LOW);

}
