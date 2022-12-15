#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led 5 \\ led pin number according to you

void setup() 
{
  pinMode(LED_BUILTIN , OUTPUT);
  Serial.begin(9600);
  WiFi.begin("777", "password"); \\ your wifi name and password in place of this .
  while(WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_BUILTIN , HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN , LOW);

  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(led, OUTPUT);
}

void loop() 
{
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(led, HIGH);
    }
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(led, LOW);
    }
    if(request == "GET /bledon HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN , HIGH);
    }
    if(request == "GET /bledoff HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN , LOW);
    }
  }
}
