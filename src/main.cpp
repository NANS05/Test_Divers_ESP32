
//****************************************************************************************************//
//********** WIFI MANAGER ****************************************************************************//

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>

const char* ssid = "Wi-Fi ESP32";
const char* password  = "devkit12345";

WiFiManager wm;

void setup() {

  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");

  if(!wm.autoConnect(ssid, password)) {
    Serial.println("Erreur de connexion");
  } else {
    Serial.println("Connexion réussie!");
  }
}

void loop() {
  if(touchRead(T0) < 50) {
    Serial.println("Suppression des réglages et redémarrage...");
    wm.resetSettings();
    ESP.restart();
  }
}

//****************************************************************************************************//


//****************************************************************************************************//
//********** POINT D'ACCES ***************************************************************************//
/*
#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Wi-Fi ESP32";
const char* password  = "devkit12345";

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");

  Serial.println("Création du point d'accès...");
  WiFi.softAP(ssid, password);

  Serial.println("Adress IP : ");
  Serial.println(WiFi.softAPIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
*/
//****************************************************************************************************//


//****************************************************************************************************//
//********** CONEXION WIFI ***************************************************************************//
/*
#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Wi-Fi Maurel";
const char* password  = "LaPrairie05";

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");

  WiFi.begin(ssid, password);
  Serial.print("Connexion au réseau '" + (String)ssid + "'...");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println(" Connexion réussie!");
  Serial.println("\n");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
*/
//****************************************************************************************************//