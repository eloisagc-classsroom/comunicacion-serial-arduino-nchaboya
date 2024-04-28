int size = 4; // definimos el número de bits
int pin[4] = {4,5,6,7}; // Arreglo para acceder a los pines
int b[4] = {1,2,4,8};
// Inicializamos cada uno de los pines a utilizar
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < size ; i++){
    pinMode(pin[i], OUTPUT);
  }
}
// incializamos el contador con el número máximo
int c = -1;
int op = 0;
void loop()
{
  if (op != 0){
    String s = "";
    int n = 0;
	
    if(op == 1){
      if(c == 16){
        c = 0;
        op = 0;
      }
    }
    
    float aux = c;
    for (int i = size-1; i >= 0 ; i--){
      if ((aux/b[i]) >= 1){
          digitalWrite(pin[i], HIGH);
          aux = aux - b[i];
          n += b[i];
          s += "1";
      }
      else{
          digitalWrite(pin[i], LOW);
          s += "0";
          n += 0;
      }
    }

    delay(500); // Esperamos 500 milisegundos
    Serial.print("Decimal: "); Serial.print(n); 
    Serial.print(", Binario: "); Serial.println(s);
    
    if(op == 1)
      c ++; 
    else if (op ==2 ){
      if(c == 0){
  		  c = 16;
      	  op = 0;
      }
  	  c --;
    }
  }
  else{
    
      Serial .println("Opciones"); 
      Serial.println("1. Ascendente");
      Serial.println("2. Descendente");
      Serial.println("Elija una opcion");
      while (Serial . available() == 0){}
      op = Serial .parseInt () ;
      if (op == 1)
        c = 0;
      else if (op == 2)
      	c = 16;
      else
        op = 0;
  }
}