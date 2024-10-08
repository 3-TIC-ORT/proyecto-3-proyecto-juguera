//librerias de lcd
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

//defines de los pinouts
#define bomba 6
#define motor 51
#define led 24
#define electro 5
#define bocina 28
#define NARANJA 2
#define MANZANA 3

//defino el tiempo que va a tener el vaso y la jarra (en el normal y en el concentrado)
#define TIEMPO_JARRA_NORMAL 5
#define TIEMPO_VASO_NORMAL 3
#define TIEMPO_JARRA_CONCENTRADO 2
#define TIEMPO_VASO_CONCENTRADO 1


//otras variables
String sabor;
String tamano;
String data;
String confirmado;
int x = 0;
bool flag = false;


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
}


void loop() {

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); //lee hasta el salto de linea y lo almacena en input

    int index1 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index1
    if (index1 != -1) { //verifica que haya un espacio
      sabor = input.substring(0,(index1 + 1)); //en sabor guarda desde el principio (index 0) hasta el espacio
      tamano = input.substring((index1 + 1)); //almacena desde el espacio hasta el final
      Serial.println(sabor);
      Serial.println(tamano);
    } 


    lcd.setCursor(0,0);
    lcd.print(sabor);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Colocar vaso");
    lcd.setCursor(1,1);
    lcd.print("en la ranura");

    Serial.println("vasoconfirmado"); //le pregunto a timo si esta confirmado que el vaso esta ahí

    delay(5000);  
    if(Serial.available() > 0) {
      confirmado = Serial.readStringUntil('\n'); //si hay algo en el serial que lo almacene en confrimado
      Serial.println(confirmado);
    }
  }



 if (sabor=="Naranja ") {
   x= 1;
 }

 if (sabor =="Manzana ") {
   x = 2;
 }

  switch (x) {
    
    case 1:
      
      if(confirmado == "confirmado") { //si confirmado esta confrimado que siga con el proceso 
        Serial.println("Seguir adelante");
        sabor = "";
        x = 0;
        funcion(NARANJA,tamano,"Concentrado");
        funcion(bomba,tamano,"Normal");
        delay(250);
        funcion(motor,tamano,"Normal");
        delay(250);
        funcion(electro,tamano,"Normal");
        delay(250);
        lcd.clear();
        lcd.print("Terminado");
        Serial.println("temrinado");
      }
      
    break; 

    case 2: 
      if(confirmado == "confirmado") { //si confirmado esta confrimado que siga con el proceso 
        sabor = "";
        x= 0;
        Serial.println("seguir adelante");
        funcion(MANZANA,tamano,"Concentrado");
        funcion(bomba,tamano,"Normal");
        delay(250);
        funcion(motor,tamano,"Normal");
        delay(250);
        funcion(electro,tamano,"Normal");
        delay(250);
        lcd.clear();
        lcd.print("Terminado");
        Serial.println("temrinado");
      }
      
    break;

    
  }

}
