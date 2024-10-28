//librerias de lcd
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

//defines de los pinouts
#define bomba 7
#define motor 2
#define led 24
#define electro 8
#define bocina 28
#define NARANJA 5
#define MANZANA 4
#define LIMON 9
#define FRUTILLA 10

//defino el tiempo que va a tener el vaso y la jarra (en el normal y en el concentrado)
#define TIEMPO_JARRA_NORMAL 5
#define TIEMPO_VASO_NORMAL 3
#define TIEMPO_JARRA_CONCENTRADO 2
#define TIEMPO_VASO_CONCENTRADO 1

#define DELAY 250


//otras variables
String sabor;
String tamano;
String confirmado;
int contador = 0;
String data = "";

// variables para la division de palabras
int index1; //el lugar de los espacios
String input = ""; //la palabra completa


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

  if (tipo == "Normal") {
    digitalWrite(pin,HIGH);
    delay(tiempoNormal*1000);
    digitalWrite(pin,LOW);
  }
}


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
  pinMode (LIMON, OUTPUT);
  pinMode(FRUTILLA, OUTPUT);
}


void loop() {

  if (Serial.available() > 0 && contador == 0) { //si hay algo en el serial y contador es 0
    input = Serial.readStringUntil('\n'); //lee hasta el salto de linea y lo almacena en input

    index1 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index1
    if (index1 != -1) { //verifica que haya un espacio
      sabor = input.substring(0,(index1 + 1)); //en sabor guarda desde el principio (index 0) hasta el espacio
      tamano = input.substring((index1 + 1)); //almacena desde el espacio hasta el final
      Serial.println(sabor);
      Serial.println(tamano);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(sabor);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Colocar vaso");
      lcd.setCursor(1,1);
      lcd.print("en la ranura");

      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
      contador = 15; //cambia contador a 15 (no vuelve a entrar al serial de arriba)

    } else if (index1 = -1) {
      data = input; 
      data.trim();
      Serial.println(data);
      Serial.println("sin espacios");
      contador = 4;
    }

  }

  if (contador == 15 && Serial.available() > 0) { //si contador es 15 y hay algo en el serial
    delay(250);
    confirmado = Serial.readStringUntil('\n');
    Serial.println(confirmado);
    contador = 0; //lo cambia a 0 para que vuelva a entrar en el de arriba despues 
  } 

  
  if(confirmado == "confirmado") { //si confirmado esta confrimado que siga con el proceso 
    confirmado = "";
    Serial.println("Seguir adelante");

    if(sabor == "Naranja ") {
      funcion(NARANJA,tamano,"Concentrado");
      Serial.println("Naranja");
    } else if (sabor == "Manzana ") {
      funcion(MANZANA,tamano,"Concentrado");
      Serial.println("Manzana");
    } else if (sabor == "Limon") {
      funcion(LIMON,tamano,"Concentrado");
      Serial.println("Limon");
    } else if (sabor == "Frutilla") {
      funcion(FRUTILLA,tamano,"Concentrado");
      Serial.println("Limon");
    }
    
    
    

    funcion(bomba,tamano,"Normal");
    delay(DELAY);
    funcion(motor,tamano,"Normal");
    delay(DELAY);
    funcion(electro,tamano,"Normal");
    delay(DELAY);
    digitalWrite(led,HIGH); //prende el led para avisar que termino
    lcd.clear();
    lcd.print("Terminado");
    Serial.println("temrinado");
    sabor = "";
  }

  if (contador == 4){

    if (data == "limpieza") {
      data= "";
      Serial.println("epezando limpieza");
      data = Serial.readString();
      data.trim();
      lcd.setCursor(0,0); //posicion
      lcd.print("Poner");
      lcd.setCursor(1,1); //posicion
      lcd.print("Recipiente");

      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
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
      
      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
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
      delay(4000);
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
      Serial.println("limpieza terminada"); //le pregunto a timo si esta confirmado que el vaso esta ahí
      contador = 0;
      
    }


    if(data == "recargar"){
      Serial.println("empezando recargado");
      
      lcd.setCursor(0,0); //posicion
      lcd.print("Poner");
      lcd.setCursor(1,1); //posicion
      lcd.print("Vaso");
      
      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
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

      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
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
      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
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
      
      Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí
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
      Serial.println("recarga terminada"); //le pregunto a timo si esta confirmado que el vaso esta ahí
      contador = 0;

      }else{

        data= "";
        contador = 0;
      }
      data= "";
  } 
 }
  
      

