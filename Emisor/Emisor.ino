#include <FirebaseESP32.h>
#include <WiFi.h>
#include<WiFiClient.h>
#include <Wire.h>
#include <AHT10.h>
AHT10 myAHT10(0x38);

WiFiClient client;
FirebaseData EspFirebase;
String PATH = "Final2";
String URL = "final2-4e876-default-rtdb.firebaseio.com";
String PASS = "mfqmnXHlp6mRAAO4xP6MadgThE4cfIpyc7tBhGSN";
String valor;
int valor_int;
int X, Y, SW, PULSADORJ = 10, BOTON1, BOTON2;


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); //station el ESP como estación
  WiFi.begin("MOVISTAR_19AB","443031394142Nq5WhOg7");
  Serial.println("Conectado....");
  while(WiFi.status() !=WL_CONNECTED)
  {
    Serial.print('.');
    delay(200);
  }
  Serial.println();
  Serial.print("Dirección IP:");
  Serial.println(WiFi.localIP());
  if (!myAHT10.begin()) {
    Serial.println("No hay sensor!");
    while (1);
  }

  Firebase.begin(URL,PASS);
  Firebase.reconnectWiFi(true);


}

void loop() {
  float temp = myAHT10.readTemperature();
  Serial.print("Temp: "); Serial.print(temp); Serial.println(" C");
  Firebase.setInt(EspFirebase, PATH + "/Sensortemp", temp);
  delay(200);
  X = analogRead(32);
  Y = analogRead(33);    
  SW = digitalRead(PULSADORJ);  
  BOTON1 = digitalRead(18);
  BOTON2 = digitalRead(19);
  Serial.println(X); Serial.println("__________________________"); Serial.println(Y);
  Firebase.setInt(EspFirebase, PATH + "/JoystickX", X);
  delay(200);
  Firebase.setInt(EspFirebase, PATH + "/JoystickY", Y);
  delay(200);
  Firebase.setInt(EspFirebase, PATH + "/BOTON1", BOTON1);
  delay(200);
  Firebase.setInt(EspFirebase, PATH + "/BOTON2", BOTON2);
  delay(200);
  Serial.println("_______________________");
  delay(1000);
}
