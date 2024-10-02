#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);


#define bomba 24
#define motor 51
#define led 6
#define electro 
#define bocina 28

String data = "";

void setup() { 
 Serial.begin(9600);
  Wire.begin();
  lcd.setBacklight(HIGH);
  lcd.init();

  pinMode(bomba,OUTPUT); //Bomba
  pinMode(motor,OUTPUT);  // Motor
  pinMode(led,OUTPUT);  // LED
  pinMode(electro,OUTPUT); //Electrovalvula
  pinMode(bocina,OUTPUT); //Bocina

}
 

void loop() {

 

  if (Serial.available() > 0){
   data = Serial.readString();
    Serial.print(data);
   data.trim();
   
    if (data == "limpieza") {
      data= "";
      data = Serial.readString();
      Serial.print(data);
      data.trim();
      lcd.setCursor(0,0); //posicion
        lcd.print("Poner");
        lcd.setCursor(1,1); //posicion
        lcd.print("Recipiente");
      while(true){
        data= "";
       data = Serial.readString();
        Serial.print(data);
        data.trim();
        if(data=="confirmado"){
          break;
        }
        
      }
        
        lcd.clear();
        lcd.setCursor(0,0); //posicion
        lcd.print("Poner");
        lcd.setCursor(1,1); //posicion
        lcd.print("Agua caliente");
        data= "";
      
       while(true){
        data= "";
       data = Serial.readString();
        Serial.print(data);
        data.trim();
        if(data=="confirmado"){
          break;
        }
      }
        
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
      
      while(true){
        data= "";
       data = Serial.readString();
        Serial.print(data);
        data.trim();
        if(data=="confirmado"){
          break;
        }
        
      }
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
      while(true){
        data= "";
       data = Serial.readString();
        Serial.print(data);
        data.trim();
        if(data=="confirmado"){
          break;
        }
        
      }
      lcd.clear();
      lcd.setCursor(0,0); //posicion
      lcd.print("Revolver");
      lcd.setCursor(1,1); //posicion
      lcd.print("");
      while(true){
        data= "";
       data = Serial.readString();
        Serial.print(data);
        data.trim();
        if(data=="confirmado"){
          break;
        }
        
      }
      lcd.clear();
      lcd.setCursor(0,0); //posicion
      lcd.print("Poner concentrado");
      lcd.setCursor(1,1); //posicion
      lcd.print("en el compartimento");
      while(true){
        data= "";
       data = Serial.readString();
        Serial.print(data);
        data.trim();
        if(data=="confirmado"){
          break;
        }
        
      }
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

