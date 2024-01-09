#include <WiFi.h>
#include <math.h>
String apiKey = "PE4WDGH05P54JXL2"; // Enter your Write API key from ThingSpeak
const char *ssid = "Bhaviks"; // replace with your wifi ssid and wpa2 key
const char *pass = "123456789";
const char* server = "api.thingspeak.com";
WiFiClient client;
void setup()
{
Serial.begin(115200);
delay(10);
Serial.println("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
}
int count =0;
int flag =0;
void loop()
{
float h = analogRead(33);
float t = analogRead(32);
if (isnan(h))
{
Serial.println("Failed");
return;
}
 
if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
{
  float d = -0.00193180668 * pow(h,1) + 0.000000912519626 * pow(h,2) - 0.0000000000844837376 *pow(h,3) - 0.0000000000000282655843 * pow(h,4)+4.25;
  if (d>4){
    d=4;
  }
  else if (d<0){
    d=0;
  }
  if (d>1.5){
    flag =1;
  }
  if(flag==1 && d<1.5){
    count++;
    flag =0;
  }
  float f = 3.525681333215756 - 0.00110585966 * pow(t,1) - 0.00000112998850 * pow(t,2) + 0.000000000691007421 * pow(t,3) - 0.000000000000102535385 * pow(t,4);
  if (f<0){
    f=0;
  }

String postStr1 = apiKey;
postStr1 += "&field1=";
postStr1 += String(d);
postStr1 += "&field2=";
postStr1 += String(f);
postStr1 += "&field3=";
postStr1 += String(count);
postStr1 += "\r\n\r\n\r\n";
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr1.length());
client.print("\n\n");
client.print(postStr1);
// Serial.print("Force: ");
// float d = 0.000533989980 * pow(h,1) - 0.000000373574567 * pow(h,2);
// Serial.println(f);
// Serial.print(" ");
Serial.println(count);
// Serial.print(" Force: ");
// Serial.print(t);
// Serial.print('\n');
// Serial.println("Data Send to Thingspeak");
}
delay(10);
// client.stop();
// Serial.println("Waiting...");
 
// thingspeak needs minimum 15 sec delay between updates.
// delay(1);
}
