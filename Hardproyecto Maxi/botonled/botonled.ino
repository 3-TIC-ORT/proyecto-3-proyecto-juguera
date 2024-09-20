void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4,INPUT);

}

void loop() {
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
 if(digitalRead(4) == 0){
    digitalWrite(2, LOW);
    digitalWrite(3,HIGH);
  }

}