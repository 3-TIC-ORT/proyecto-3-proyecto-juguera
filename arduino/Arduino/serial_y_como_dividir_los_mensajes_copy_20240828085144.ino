String palabra1;
String palabra2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); //lee hasta el salto linea y lo almacena como input
    
    int index1 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index1
    if (index1 != -1) { //verifica que haya un espacio
      palabra1 = input.substring(0, index1); //en palabra1 guardas desde el principio (indice 0) hasta el espacio

    } else {
      palabra1 = input; //si no hay dos palabras lo almacena como una sola
      input = "";
    }

    int index2 = input.indexOf(' '); //guarda el valor de donde haya un espacio en index2
    if (index2 != -1) { //verifica que haya un espacio
      palabra2 = input.substring(index2 + 1); //almacena en palabra2 deesde el espacio hasta el final
    } else {
      palabra2 = input; //si no hay dos palabras la palabra2 esta vacia
    }

    // Imprime las palabras para verificar
    Serial.print ("palabra1:");
    Serial.println(palabra1);
    Serial.print ("palabra2:");
    Serial.println(palabra2);
  }
}
