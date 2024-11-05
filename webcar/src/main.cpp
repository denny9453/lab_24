#include <Arduino.h>
#include <WiFi.h>
#include <iostream>
#include <sstream>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

#define RIGHT_MOTOR 0
#define LEFT_MOTOR 1

#define FORWORD 1
#define BACKWORD -1



const int PWMFreq = 1000; // 1kh
const int PWMResolution = 8;
const int PWMSpeedChannel = 4;


const char* ssid = "iot-13";
const char* password = "22453238";

AsyncWebServer = server(80);
AsyncWebSocket wsCarInput("/Carinput");


struct MOTOR_PINS

{
  int pinEn;
  int pinIN1;
  int pinIN2;
};


std::vector<MOTOR_PINS> motorPins =
{

{22,16,17},
{23,18,19},



};

void setUpPinMode()
{
ledcSetup(PWMSpeedChannel,PWMFreq,PWMResolution );
for (int  i = 0; i < motorPins.size(); i++)
{
  pinMode(motorPins[i].pinEn,OUTPUT);
   pinMode(motorPins[i].pinIN1,OUTPUT);
    pinMode(motorPins[i].pinIN2,OUTPUT);
ledcAttachPin(motorPins[i].pinEn,PWMSpeedChanne );




}
void handleNotFound(AsyncWebServerRequest *request)
{
request->send(404, "text/plain","flie not found");



  
}
void handleRoot(AsyncWebServerRequest *request)
{
request->send(200, "text/html",htmlHomePage);



  
}







}

void setup() {
setUpPinModes();
Serial.begin(115200);

WiFi.softAP(ssid ,password );
IPAddress IP =WiFi.softAPIP();
Serial.print("Ap IP address:");
Serial.println(IP);

server.on("/", HTTP_GET, handleRoot);
server.onNotFound(handleNotFound);

wsCarInput.onEvent(onCarInputWebSocketEvent);
server.addHandler(&wsCarInput);
server.begin();
Serial.println("HTTP Server started");








}

void loop() {
  // put your main code here, to run repeatedly:
}

