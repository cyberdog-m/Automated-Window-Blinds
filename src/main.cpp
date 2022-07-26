#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>

#include <HallEffect.h>
#include <MotorDriver.h>
#include <Webpage.h>

// I/O Pin Defnitions
// Motor Pins
int motor_in_1 = 27;
int motor_in_2 = 26;
int motor_pwm = 25;

// Hall Effect sensor Pins
int sensor_1 = 36;
int sensor_2 = 34;

// Rocker Switch Pin
int switch_1 = 16;
int switch_2 = 17;

// Blinds global flag value for execution
bool moveBlindsUp_flag = false;
bool moveBlindsDown_flag = false;

// Initializing Motor and Hall Effect Sensor
MotorDriver motor(motor_in_1, motor_in_2, motor_pwm);
HallEffect hallEffect(sensor_1, sensor_2);

// Webserver hosted at Port 80
AsyncWebServer server(80);

void moveUp(){
  // Rotate the motor if the curtain is not at TOP 
  while (hallEffect.checkPosition() != "top"){
    motor.rotateCW(255);
    Serial.println("Moving Blind Up");
    delay(100);
  }
  motor.brake();
}

void moveDown(){
  // Rotate the motor if the curtain is not at BOTTOM 
  while (hallEffect.checkPosition() != "bottom"){
    motor.rotateCCW(255);
    Serial.println("Moving Blind Down");
    delay(100);
  }
  motor.brake();
}

void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "Page Not found");
}

void setup() {
  // Initializing Serial Monitor
  Serial.begin(115200);
  pinMode(switch_1, INPUT_PULLDOWN);
  pinMode(switch_2, INPUT_PULLDOWN);

  // Wifi Access Point Credetials
  WiFi.softAP("Automated Blinds", "");
  Serial.print("AP IP Addr : ");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) {
    Serial.println("MDNS responder started");
  }

  // Send webpage on request
  server.on("/", [](AsyncWebServerRequest * request){  
    request->send_P(200, "text/html", webpage);
  });

  server.on("/blind/up", HTTP_GET, [](AsyncWebServerRequest * request){ 
    request->send_P(200, "text/html", webpage);
    moveBlindsUp_flag = true;
  });

  server.on("/blind/down", HTTP_GET, [](AsyncWebServerRequest * request){ 
    request->send_P(200, "text/html", webpage);
    moveBlindsDown_flag = true;
  });

  server.onNotFound(notFound);

  server.begin();
}

void loop() {
  // Move Up if Switch 1 is HIGH
  if (digitalRead(switch_1)==HIGH){
    moveUp();
    delay(200);
  }

  // Move Down if Switch 2 is HIGH
   if (digitalRead(switch_2)==HIGH){
    moveDown();
    delay(200);
  }

  // Using flags to trigger events because otherwise causes watchdog errors
  // Move blinds up if the flag is triggered
  if (moveBlindsUp_flag){
    moveBlindsUp_flag = false;
    moveUp();
  }

  // Move blinds down if the flag is triggered
  if (moveBlindsDown_flag){
    moveBlindsDown_flag = false;
    moveDown();
  }
}