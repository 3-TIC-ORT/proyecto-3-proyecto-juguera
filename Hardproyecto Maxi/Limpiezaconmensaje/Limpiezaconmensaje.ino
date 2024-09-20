

void setup() {
  Serial.begin(9600);
 pinMode(2,OUTPUT); //Bomba
 pinMode(3,OUTPUT);  // Motor
 pinMode(4,INPUT);  //Boton
 pinMode(5,OUTPUT);  // LED
 pinMode(6,OUTPUT); //Electrovalvula
 pinMode(7,OUTPUT); //Bocina

}
 

void loop() {

  if (Serial.available() > 0){
  String data = Serial.readString();
    Serial.print(data);
   data.trim();
    if (data == "limpieza") {
      Serial.println("Poner Vaso");
      delay(5000);
      Serial.println("Cambiar agua por agua caliente");
      delay(10000);
      Serial.println("Empezando Limpieza");
      delay(2500);
      Serial.println("Limpiando");
      digitalWrite(2, HIGH);
      delay(10000);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      delay(8000);
      digitalWrite(3, LOW);
      digitalWrite(6, HIGH);
      Serial.println("Limpieza Terminada");
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      delay(5000);
      digitalWrite(6, LOW);
      delay(5000);
   
    }
  data= "";
  }
}
