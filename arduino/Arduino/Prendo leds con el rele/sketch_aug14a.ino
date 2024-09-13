//Constants

#define NUM_DO 4 //8
//Parameters
const int digPin[NUM_DO] = {2, 3, 4, 5}; 

void setup() {
 	//Init Serial USB
 	Serial.begin(9600);
 	Serial.println(F(" Initialize System "));
 
  for (int i = 0; i < NUM_DO; i++) pinMode(digPin[i], OUTPUT);
 	//Le digo a cada pin que es un OUTPUT, es una foma avanzadad de hacer con una sola linea de codigo que todos los cosos sean OUTPUTS
  // Osea, este for es lo mismo que decir
  // pinMode(digPin[0], OUTPUT)
  // pinMode(digPin[1], OUTPUT)
  // pinMode(digPin[2], OUTPUT)
  // pinMode(digPin[3], OUTPUT)
  
  pinMode(13, INPUT); 
 	
}
void loop() {
  int EstadoBoton = digitalRead(13);
  
  if (EstadoBoton == HIGH) {
   digitalWrite(digPin[1], LOW);

   digitalWrite(digPin[0], HIGH);
   digitalWrite(digPin[2], HIGH);
   digitalWrite(digPin[3], HIGH);
   //si aprieto el botón prendo el 3 y apago el resto

  } 
  else{
    digitalWrite(digPin[1], HIGH);
    digitalWrite(digPin[0], LOW);
    digitalWrite(digPin[2], LOW);
    digitalWrite(digPin[3], LOW);
    //si el boton no esta apretado el 3 esta apagado y el resto prendido
  }
  

}
