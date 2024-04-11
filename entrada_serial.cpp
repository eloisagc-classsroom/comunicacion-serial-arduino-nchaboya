 // Leyendo una entrada del usuario para indicar el numero de veces que parpadea el led
int ledPin = 10; //
int numBlinks; // variable cuyo valor indicara el usuario
String LedOnMessage = "LED is turned on"; // variable de tipo string
String LedOffMessage = "Red LEd is turned off"; // variable de tipo string

void setup(){
	pinMode(ledPin , OUTPUT); // define ledPin como salida
	digitalWrite(ledPin , LOW); // inicializa ledPin en 0
	Serial .begin(9600);
}
 
void loop(){
 	Serial .println("Veces que quieres que se encienda y se apague el led"); // Pide info al usuario
	while (Serial . available() == 0){}
	// Espera hasta recibir la entrada del usuario en la consola
 
 	numBlinks = Serial .parseInt () ; //Lee el dato de la consola y lo almacena en la variable
 	Serial.print ("El usuario indica que el led va a encenderse y apagarse:");
 	Serial .print (numBlinks);
 	Serial .println('veces.');
 	for ( int counter = 1; counter <= numBlinks; counter++){
       Serial .println(LedOnMessage);
       digitalWrite(ledPin , HIGH);
       delay(1000);
       Serial .println(LedOffMessage);
       digitalWrite(ledPin , LOW);
       delay(1000);
  	}
}