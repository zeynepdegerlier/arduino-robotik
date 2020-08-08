#define SensorSol A6
#define SensorOrta A7
#define SensorSag A8

void setup() {

pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT); 
  pinMode(SensorSag, INPUT);

}

void loop() {
Serial.begin(9600);
Serial.println("sensor1-sensor2-sensor3");
Serial.print(digitalRead(SensorSol));
Serial.print("       ");
Serial.print(digitalRead(SensorOrta));
Serial.print("       ");
Serial.println(digitalRead(SensorSag));
delay(1000);
}
