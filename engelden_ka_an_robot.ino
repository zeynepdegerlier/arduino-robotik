#define echoPin 15
#define trigPin 14
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


long sure, uzaklik; //süre ve uzaklık diye iki değişken tanımlıyoruz.

void setup() {


  // ultrasonik sensör Trig pininden ses dalgaları gönderdiği için OUTPUT (Çıkış),
  // bu dalgaları Echo pini ile geri aldığı için INPUT (Giriş) olarak tanımlanır.
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

pinMode(INA1, OUTPUT); // Sensör ve Motorların Giriş-Çıkış bilgilerini belirtiyoruz.
  pinMode(INA2, OUTPUT);

  pinMode(INB1, OUTPUT);
  pinMode(INB2, OUTPUT);

  Serial.begin(9600);

}

void loop() {


  digitalWrite(trigPin, LOW); //sensör pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi

  sure = pulseIn(echoPin, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  uzaklik = sure / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor

  Serial.println(uzaklik);

  if (uzaklik < 15) // Uzaklık 15'den küçük ise,
  {
    geri(200);  // 150 ms geri git
    delay(150);
    sag(200);  // 250 ms sağa dön
    delay(250);
  }
  else {  // değil ise,
    ileri(200); // ileri git
  }

}



void ileri(int hiz){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

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


void sag(int hiz){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

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


void geri(int hiz){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.

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
