void setup() {
  // put your setup code here, to run once:
 pinMode(2,INPUT_PULLUP);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
}
 
int x = 0;
int boton = digitalRead(2);

void loop() {
 if(boton == 1){
 x= x+1;
 if(x == 1){
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10, LOW);
  delay (500);
 }else if(x==2){
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10, LOW);
  delay (500);
 }else if(x == 3){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10, HIGH);
  delay (500);
  x= x-3;
 }
 }
}
