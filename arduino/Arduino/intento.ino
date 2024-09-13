String sabor;
String tamano;


void setup() {
  Serial.begin(9600);

  pinMode(2,OUTPUT); //Bomba Naranja
  pinMode(3,OUTPUT); //Bomba Normal
  pinMode(4,OUTPUT); //Motor revolver
  pinMode(5,OUTPUT); //Electrovalvula
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); //lee hasta el salto linea y lo almacena como input
   
    int index1 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index1
    if (index1 != -1) { //verifica que haya un espacio
      sabor = input.substring(0, index1); //en sabor  guardas desde el principio (indice 0) hasta el espacio


    } else {
      sabor = input; //si no hay dos palabras lo almacena como una sola
      input = "";
    }


    int index2 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index2
    if (index2 != -1) { //verifica que haya un espacio
      tamano = input.substring(index2 + 1); //almacena en tamano deesde el espacio hasta el final
    } else {
      tamano = input; //si no hay dos palabras la palabra dos es toda la oración
    }


    // Imprime las palabras para verificar
    Serial.println(sabor);
    Serial.println(tamano);
  }
}





if (sabor == naranja) {
  digitalWrite(2,HIGH);



}
