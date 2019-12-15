
const int flexPin1 = A0; 
const int flexPin2 = A1;
const int ledPin = 13; 
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    pinMode(ledPin,OUTPUT);
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  int flexValue1,flexValue2;
  int flexval1,flexval2;
  const char *msg;
  flexValue1 = analogRead(flexPin1);
  flexValue2 = analogRead(flexPin2);
  flexval1=flexValue1/7;
  flexval2=flexValue2/7;
  Serial.print("sensor 1: ");
  Serial.println(flexval1);
  Serial.print("sensor 2: ");
  Serial.println(flexval2);
  if(flexval1<115
 
  && flexval2<120)
  {
    msg = "Normal!!";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(5000);
  }
  else if(flexval1>120 && flexval1<130 && flexval2<120)
  {
    msg = "!!Food!!";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(5000);
  }
  else if(flexval1<120 && flexval2>120 && flexval2<130)
  {
    msg = "water!!!";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(5000);
  }
  else if(flexval1>120 && flexval1<135 && flexval2>120 && flexval2<135)
  {
    msg = "Medicine";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(5000);
  }
  else if(flexval1>135 && flexval2>135)
  {
    msg = "Critical";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
  }
  else 
  {
  }
}

