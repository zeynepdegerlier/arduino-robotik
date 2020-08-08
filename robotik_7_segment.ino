#define a 22
#define b 18
#define c 20
#define d 28
#define e 26
#define f 24
#define g 19
#define D1 11
#define D2 10
#define buton1 58
#define buton2 56
int sayac = 0;
unsigned long sure;
bool buton1_durum, buton2_durum, butonlar_durum;

void d1AktifEt() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
}
void d2AktifEt() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
}
void sifir () {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
void bir () {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void iki () {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void uc () {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void dort () {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void bes () {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void alti () {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void yedi () {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void sekiz () {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void dokuz () {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void sayiYazdir(int sayi, int bekleme_suresi) {
  byte onlar_basamak = (sayi % 100) / 10;
  byte birler_basamak = sayi % 10;

  d1AktifEt();
  switch (onlar_basamak) {
    case 0: sifir(); break;
    case 1: bir(); break;
    case 2: iki(); break;
    case 3: uc(); break;
    case 4: dort(); break;
    case 5: bes(); break;
    case 6: alti(); break;
    case 7: yedi(); break;
    case 8: sekiz(); break;
    case 9: dokuz(); break;
  }
  delayMicroseconds(bekleme_suresi);
  d2AktifEt();
  switch (birler_basamak) {
    case 0: sifir(); break;
    case 1: bir(); break;
    case 2: iki(); break;
    case 3: uc(); break;
    case 4: dort(); break;
    case 5: bes(); break;
    case 6: alti(); break;
    case 7: yedi(); break;
    case 8: sekiz(); break;
    case 9: dokuz(); break;
  }
  delayMicroseconds(bekleme_suresi);
}
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(buton1, INPUT_PULLUP);
  pinMode(buton2, INPUT_PULLUP);
   pinMode(buton1 and buton2, INPUT_PULLUP);
  Serial.begin(9600);
  sure = millis();
}

void loop() {
  buton1_durum = digitalRead(buton1);
  buton2_durum = digitalRead(buton2);
  butonlar_durum = digitalRead(buton1_durum and buton2_durum);
  if (buton1_durum == 0 and sayac < 99 and sure + 150 < millis()){
    Serial.println("buton1");
    sure = millis();
    sayac++;
  }
  if (buton2_durum == 0 and sayac > 0 and sure + 150 < millis()){
    Serial.println("buton2");
    sure = millis();
    sayac--;
  }


  sayiYazdir(sayac, 5000);
  
}
