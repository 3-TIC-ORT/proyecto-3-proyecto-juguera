void setup() {
  Serial.begin(9600);
}

String data ="";  // le decimos que data es un texto


void loop(){
   
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');  // data es lo que sea que lea
    Serial.println(data); // imprimi data en la pantalla
  }

 if (data == "hola") {
   Serial.println("¿Como estas?");  //cuando mandan hola te devuelve un "¿como estas?""
 }

 if (data == "chau") {
   Serial.println("nos vemos"); //cuando mandan chau te devuelve un "nos vemos"
 }
 
 data=""; // vacia data 
  
}

