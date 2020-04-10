#define trig D2          //trigger pin of ultrasonic sensor
#define echo D3            //Echo pin of ultrasonic sensor
#define ir D1          // Output pin of IR sensor
#define buz D0        // For Buzzer
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Stepper.h>
int status = WL_IDLE_STATUS; //not required.

const char* ssid = "shubhamj";
const char* password = "jain5013than";
int in1Pin = D5;
int in2Pin = D6;          // for stepper motor
int in3Pin = D7;
int in4Pin = D8;
 
// change this to the number of steps on your motor
#define STEPS 512
 
Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin);
int count1 =0;   // counting number of persons by ultrasonic sensor
int count2=0;   // counting number of persons by IR sensor sensor
void setup()
{
  Serial.begin(9600);
    setupWifi();
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
delayMicroseconds(2);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(ir,INPUT);

  while (!Serial);
  motor.setSpeed(50);
}

void setupWifi()
{
     // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
   WiFi.mode(WIFI_STA);
   status = WiFi.begin(ssid, password);    

   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);  

   // Wait for connection
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
   }
   Serial.println("Connected to wifi");
}


void loop()
{
   if (WiFi.status() != WL_CONNECTED)
   {
     setupWifi();
   }
  digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

int t = pulseIn(echo,HIGH);

int d = (0.000001)*(34300*t)/2;       // d is the distance calculated by ultrasonic sensor
delay(500);

if(d<=10 && d>=0)
{

  motor.step(-100);
  count1 = count1 +1;
motor.step(100);
  }
  Serial.println("US");
Serial.println(count1);  
if(digitalRead(ir) == LOW)
{
  count2=count2+1;
  }
  Serial.println("IR");
  Serial.println(count2);
if(count2 > count1)
{
   while (get_http(String("")) != 0);
  digitalWrite(buz,HIGH);
 delay(5000);
  digitalWrite(buz,LOW);
  count1=0;
  count2=0;
}

  }


  int get_http(String state)
{
   HTTPClient http;
   int ret = 0;
   Serial.print("[HTTP] begin...\n");
   // configure ifttt server and url  should be HTTP only..not https!!!  (http://)   
    http.begin("http://maker.ifttt.com/trigger/COVID-19/with/key/eTQwViOq-2nL_ovu-7KJwMPcAavP1ibK_gWUJLnLV_0");

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();
    // httpCode will be negative on error
    if(httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET code: %d\n", httpCode);

      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
        ret = -1;
        Serial.printf("[HTTP] GET failed, error: %s\n", http.errorToString(httpCode).c_str());
        delay(500); // wait for half sec before retry again
    }

    http.end();
    return ret;
}  
