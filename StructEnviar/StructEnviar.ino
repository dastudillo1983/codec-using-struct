/*
  StructEnviar

  created 26 Jun 2020
  by Fabian Astudillo-Salinas 
     <fabian.astudillos@ucuenca.edu.ec>
*/


#define SIZE_SENSOR 3

// Se envian 3 bytes
typedef struct {
  uint8_t id:8;
  uint16_t temperatura:9;
  uint8_t humedad:7;
  uint16_t radiacion:10;
} sensor;

sensor data;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial3.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  data.id = 1;
  data.temperatura = 30;
  data.humedad = 30;

  uint8_t* dataS = (uint8_t *)&data;
  
  Serial3.write(dataS, SIZE_SENSOR);
  Serial.write(0);
  Serial.write(1);
  Serial.println("Transmitting");
  Serial.print(String(dataS[0]));
  Serial.print("-");
  Serial.print(String(dataS[1]));
  Serial.print("-");
  Serial.println(String(dataS[2]));
  
  delay(1000);
}
