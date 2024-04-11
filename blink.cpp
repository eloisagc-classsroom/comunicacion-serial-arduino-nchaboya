 // Blinking LED and serial communication
int pinLed = 10; // pin donde se conecta el led
void setup (){
	pinMode(pinLed , OUTPUT) ; // declara el pin como salida
	digitalWrite (pinLed , LOW) ; // inicializa el pin en estado BAJO (0)
	Serial.begin (9600) ; // abre consola serial
}
void loop (){
	Serial.println("LED is turned on"); // mensaje para la consola
	digitalWrite (pinLed , HIGH) ; // prende el led
	delay (1000) ; // espera 1 seg
	Serial.println ("LED is turned off") ; // mensaje a la consola
	digitalWrite(pinLed, LOW); // apaga el led
	delay(1000); // espera un segundo
}

