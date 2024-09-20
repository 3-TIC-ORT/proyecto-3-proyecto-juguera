void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4,INPUT);

}

void loop() {
 if(digitalRead(4) == 1){
    digitalWrite(7, HIGH);
    digitalWrite(3,LOW);
  }else{
    digitalWrite(3, HIGH);
    digitalWrite(7, LOW);
  }
}