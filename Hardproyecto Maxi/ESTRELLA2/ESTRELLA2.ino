#include <EasyBuzzer.h>

float AA = 1;

void sonidoTerminado(){
  Serial.println("SonidoTerminado");
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);

  EasyBuzzer.setPin(2);


 DO(500);
  delay(1000);
 DO(500);
  delay(1000);
 SOL(500);
  delay(1000);
 SOL(500);
 delay(1000);
 LA(500);
  delay(1000);
 LA(500);
  delay(1000);
 SOL(1000);
  delay(1500);
 FA(500);
 delay(1000);
 FA(500);
  delay(1000);
 MI(500);
   delay(1000);
 MI(500);
   delay(1000);
 RE(500);
   delay(1000);
 RE(500);
   delay(1000);
 DO(700);

}
void DO(float tiempo){
  EasyBuzzer.singleBeep(523, tiempo);
  
}

void RE(float tiempo){
  EasyBuzzer.singleBeep(587, tiempo);
  
}

void MI(float tiempo){
  EasyBuzzer.singleBeep(659, tiempo);
  
}
void FA(float tiempo){
  EasyBuzzer.singleBeep(698, tiempo);
  
}

void SOL(float tiempo){
  EasyBuzzer.singleBeep(783, tiempo);
  
}
void LA(float tiempo){
  EasyBuzzer.singleBeep(880, tiempo);
  
}
void SI(float tiempo){
  EasyBuzzer.singleBeep(98,  tiempo);
  
}

void loop() {
  EasyBuzzer.update();

}

