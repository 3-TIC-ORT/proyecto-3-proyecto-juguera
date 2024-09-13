//Constants
#define NUM_DO 4 //8
//Parameters
const int digPin[NUM_DO] = {2, 3, 4, 5}; 


void setup() {
  // put your setup code here, to run once:
  	Serial.begin(9600);
 	Serial.println(F(" Initialize System "));
 
  for (int i = 0; i < NUM_DO; i++) pinMode(digPin[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 digitalWrite(digPin[0], HIGH);
 digitalWrite(digPin[1], HIGH);
 digitalWrite(digPin[2], HIGH);
 digitalWrite(digPin[3], LOW);

}
