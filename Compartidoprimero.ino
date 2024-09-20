#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(12,11,5,4,3,2);

#define bomba 6
#define motor 7
#define led 24
#define electro 26
#define bocina 28

void setup() { 
 Serial.begin(9600);
   
  
  lcd.begin(16, 2);
  pinMode(bomba,OUTPUT); //Bomba
  pinMode(motor,OUTPUT);  // Motor
  pinMode(led,OUTPUT);  // LED
  pinMode(electro,OUTPUT); //Electrovalvula
  pinMode(bocina,OUTPUT); //Bocina

}
 

void loop() {

  lcd.setBacklight(HIGH);

  if (Serial.available() > 0){
   String data = Serial.readString();
    Serial.print(data);
   data.trim();
   
    if (data == "limpieza") {
      data= "";
      String data = Serial.readString();
      Serial.print(data);
      data.trim();

      while(data != "continuar"){
        String data = Serial.readString();
        Serial.print(data);
        lcd.setCursor(0,0); //posicion
        lcd.print("Poner");
        lcd.setCursor(1,1); //posicion
        lcd.print("Recipiente");
        data= "";
      }
        
        lcd.clear();
        lcd.setCursor(0,0); //posicion
        lcd.print("Poner");
        lcd.setCursor(1,1); //posicion
        lcd.print("Agua caliente");
        data= "";
      

        
        lcd.clear();
        lcd.setCursor(0,0); //posicion
        lcd.print("Empezando");
        lcd.setCursor(1,1); //posicion
        lcd.print("Limpieza");
        data = "";
        lcd.clear();
      lcd.setCursor(0,0); //posicion
        lcd.print("Limpiando");
        digitalWrite(bomba, HIGH);
        delay(10000);
        digitalWrite(bomba, LOW);
        digitalWrite(motor, HIGH);
        delay(8000);
        digitalWrite(motor, LOW);
        digitalWrite(electro, HIGH);
      lcd.clear();
      lcd.setCursor(0,0); //posicion
        lcd.print("Limpieza");
        lcd.setCursor(1,1); //posicion
        lcd.print("Terminada");
        digitalWrite(led, HIGH);
        digitalWrite(bocina, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        digitalWrite(bocina, LOW);
        delay(5000);
        digitalWrite(electro, LOW);
        delay(5000);
        lcd.clear();
      lcd.print(millis()/1000);

        
        
     
      }else if(data == "recargar"){
        
      lcd.setCursor(0,0); //posicion
      lcd.print("Poner");
     lcd.setCursor(1,1); //posicion
     lcd.print("Vaso");
      delay(5000);
      digitalWrite(bomba, HIGH);
      digitalWrite(electro,HIGH);
      delay(2200);
      digitalWrite(bomba,LOW);
     delay(2000);
      digitalWrite(electro, LOW);
      lcd.clear();
      lcd.setCursor(0,0); //posicion
      lcd.print("Poner");
      lcd.setCursor(1,1); //posicion
      lcd.print("Polvo");
      delay(10000);
      lcd.clear();
      lcd.setCursor(0,0); //posicion
      lcd.print("Revolver");
      lcd.setCursor(1,1); //posicion
      lcd.print("");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0); //posicion
      lcd.print("Poner concentrado");
      lcd.setCursor(1,1); //posicion
      lcd.print("en el compartimento");
      delay(7000);
     digitalWrite(led, HIGH);
      digitalWrite(bocina, HIGH);
     lcd.clear();
      lcd.setCursor(0,0); //posicion
      lcd.print("Listo");
      lcd.setCursor(1,1); //posicion
      lcd.print("");
      delay(1500);
      digitalWrite(led, LOW);
      digitalWrite(bocina, LOW);
      lcd.clear();
      lcd.print(millis()/1000);

      }else{

        data= "";
      }
    data= "";
    } 
  }
