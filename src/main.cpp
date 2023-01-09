//****************************************************************************************************//
//********** SPIFFS **********************************************************************************//

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

#define LEDPIN 2
#define BRITHNESSPIN 34

const char* ssid = "Wi-Fi Maurel";
const char* password  = "LaPrairie05";

AsyncWebServer server(80);

void setup() {

  //---------- Serial ----------//
  Serial.begin(115200);
  while (!Serial){} //delay(1000);
  Serial.println("\nDémarrage de l'ESP32\n");

  //---------- GPIO ----------//  
  pinMode(LEDPIN, OUTPUT);
  pinMode(BRITHNESSPIN, INPUT);

  digitalWrite(LEDPIN, LOW);

  //---------- SPIFFS ----------//
  if(!SPIFFS.begin()) {
    Serial.println("Erreur SPIFFS...");
    return;
  }

  File root = SPIFFS.open("/");
  File file = root.openNextFile();

  while(file) {
    Serial.print("File : ");
    Serial.println(file.name());
    file.close();
    file = root.openNextFile();
  }
  Serial.println();

  //---------- WiFi ----------//
  WiFi.begin(ssid, password);
  Serial.print("Connexion au réseau '" + (String)ssid + "'...");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println(" Connexion réussie!\n");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
  Serial.println();

  //---------- Server ----------//
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/w3.css", "text/css");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server.on("/lireLuminosite", HTTP_GET, [](AsyncWebServerRequest *request) {
    int val = analogRead(BRITHNESSPIN);
    String luminosite = String(val);
    request->send(200, "text/plain", luminosite);
  });

  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(LEDPIN, HIGH);
    request->send(200);
  });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(LEDPIN, LOW);
    request->send(200);
  });

  server.begin();
  Serial.println("Serveur actif !\n");
}

void loop() {

}

//****************************************************************************************************//


//****************************************************************************************************//
//********** WIFI MANAGER ****************************************************************************//
/*
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
*/
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

}
*/
//****************************************************************************************************//