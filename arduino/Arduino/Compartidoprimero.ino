#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

//defines de los pinouts
#define bomba 6
#define motor 7
#define led 24
#define electro 26
#define bocina 28
#define NARANJA 2
#define MANZANA 3


//defino el tiempo que va a tener el vaso y la jarra (en el normal y en el concentrado)
#define TIEMPO_JARRA_NORMAL 5
#define TIEMPO_VASO_NORMAL 3
#define TIEMPO_JARRA_CONCENTRADO 2
#define TIEMPO_VASO_CONCENTRADO 1


//variables de sabor y tamaño 
String sabor;
String tamano;
String data;

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
  pinMode(MANZANA,OUTPUT); //bomba del concentrado de manzana
  pinMode(NARANJA,OUTPUT); //bomba del concentrado de naranja

}
 

void loop() {

 if (Serial.available() > 0) {
   String input = Serial.readStringUntil('\n'); //lee hasta el salto de linea y lo almacena en input

   int index1 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index1
   if (index1 != -1) { //verifica que haya un espacio
     sabor = input.substring(0,(index1 + 1)); //en sabor guarda desde el principio (index 0) hasta el espacio
     tamano = input.substring((index1 + 1)); //almacena desde el espacio hasta el final
    } else {
      String data = input;
      data.trim();
    }
  }
  
   
 if (data == "limpieza") {
    data= "";

      
    lcd.setCursor(0,0); //posicion
    lcd.print("Poner");
    lcd.setCursor(1,1); //posicion
    lcd.print("Recipiente");
       
    delay(10000);
        
    lcd.clear();
    lcd.setCursor(0,0); //posicion
    lcd.print("Poner");
    lcd.setCursor(1,1); //posicion
    lcd.print("Agua caliente");
    data= "";
      
    delay(5000);
        
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

        
        
     
  }else if(data == "recargar") {
        
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
    delay(10000);
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

  } else{

   data= "";
  }
     data= "";
  

  if(sabor == "Naranja") {
    funcion(NARANJA,tamano,"Concentrado");
    lcd.print("Sabor Naranja");
    delay(250);
    funcion(bomba,tamano,"Normal");
    delay(250);
    funcion(motor,tamano,"Normal");
    delay(250);
    lcd.clear();
    lcd.print("Colocar vaso en la ranura");
    funcion(electro,tamano,"Normal");
    delay(250);
    sabor="";
    lcd.clear();
    lcd.print("Terminado");
  }


  
  if(sabor == "Manzana") {
    funcion(MANZANA,tamano,"Concentrado");
    lcd.print("Sabor Manzana");
    delay(250);
    funcion(bomba,tamano,"Normal");
    delay(250);
    funcion(motor,tamano,"Normal");
    delay(250);
    lcd.clear();
    lcd.print("Colocar vaso en la ranura");
    funcion(electro,tamano,"Normal");
    delay(250);
    sabor="";
    lcd.clear();
    lcd.print("Terminado");
  }



}


//A

//FUNCION
//le entrego el pin que tiene que prender, el tiempo y si es concentrado o normal
//y la funcion le asigna un numero al tiempo y dsp combina el pin (lo prende y lo apaga) durante ese tiempo
// como el tiempo es diferente para la bomba normal o la concentrada crea diferentes tiempos para cada una
void funcion (int pin, String tamano, String tipo) {
  int tiempoConcentrado = 0;
  int tiempoNormal = 0;

  if (tamano == "Jarra") {
    tiempoNormal = TIEMPO_JARRA_NORMAL;
    tiempoConcentrado = TIEMPO_JARRA_CONCENTRADO;
  }

 if (tamano == "Vaso") {
    tiempoNormal = TIEMPO_VASO_NORMAL;
    tiempoConcentrado = TIEMPO_VASO_CONCENTRADO;
  }

  if (tipo == "Concentrado") {
    digitalWrite(pin,HIGH);
    delay(tiempoConcentrado*1000);
    digitalWrite(pin,LOW);
  }

 if (tipo == "Concentrado") {
    digitalWrite(pin,HIGH);
    delay(tiempoNormal*1000);
    digitalWrite(pin,LOW);
  }

}
