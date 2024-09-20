#include <EasyBuzzer.h>

void sonidoTerminado(){
  Serial.println("SonidoTerminado");
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);

  EasyBuzzer.setPin(2);
    EasyBuzzer.singleBeep(
      523,  //Frecuencia
      500,   // Duracion
      A       //funcion
    );
    

}

void A(){
  EasyBuzzer.singleBeep(523,500, B);
  
}

void B(){
  EasyBuzzer.singleBeep(783,500, C);
  
}

void C(){
  EasyBuzzer.singleBeep(783,500, D);
  
}
void D(){
  EasyBuzzer.singleBeep(880,500, E);
  
}

void E(){
  EasyBuzzer.singleBeep(880,500, FA);
  
}
void FA(){
  EasyBuzzer.singleBeep(783,500, G);
  
}
void G(){
  EasyBuzzer.singleBeep(698,500, H);
  
}
void H(){
  EasyBuzzer.singleBeep(698,500,  I);
  
}
void I(){
  EasyBuzzer.singleBeep(659,500, J);
  
}
void J(){
  EasyBuzzer.singleBeep(659,500, K);
  
}
void K(){
  EasyBuzzer.singleBeep(587,500, L);
  
}
void L(){
  EasyBuzzer.singleBeep(587,500, M);
  
}
void M(){
  EasyBuzzer.singleBeep(523,500);
  
}




void loop() {
  EasyBuzzer.update();

}

