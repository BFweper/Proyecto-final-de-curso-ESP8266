#include <Wire.h>
#include <FirebaseESP8266.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>




WiFiClient client;
FirebaseData EspFirebase;
String PATH = "Final2";
String URL = "final2-4e876-default-rtdb.firebaseio.com";
String PASS = "mfqmnXHlp6mRAAO4xP6MadgThE4cfIpyc7tBhGSN";
int valor1, valor2;
int valor_int1, valor_int2;
int led1 = 16, led2 = 0;




void setup() {
  Wire.begin();
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  WiFi.mode(WIFI_STA); 
  WiFi.begin("POCO M4 Pro","3xrtp6ikfyymtcc");
  Serial.println("Conectado....");
  while(WiFi.status() !=WL_CONNECTED)
  {
    Serial.print('.');
    delay(200);
  }
  Serial.println();
  Serial.print("Dirección IP:");
  Serial.println(WiFi.localIP());
  Firebase.begin(URL,PASS);
  Firebase.reconnectWiFi(true);

}

void loop() {
 
    Firebase.getInt(EspFirebase, PATH + "/BOTON1");
    delay(500);
    valor1 = EspFirebase.intData();
    Serial.println(valor1);
    Serial.println("_______________________");
    if(valor1 == 1)
    {
      digitalWrite(led1,HIGH);
    }
    else
    {
      digitalWrite(led1,LOW);
    }

    Firebase.getInt(EspFirebase, PATH + "/BOTON2");
    delay(500);
    valor2 = EspFirebase.intData();
    Serial.println(valor2);
    Serial.println("_______________________");
    if(valor2 == 1)
    {
      digitalWrite(led2,HIGH);
    }
    else
    {
      digitalWrite(led2,LOW);
    }

    delay(1000);
}
