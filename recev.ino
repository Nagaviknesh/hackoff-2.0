#include <RH_ASK.h> 
#include <SPI.h> // Not actualy used but needed to compile
#include <LiquidCrystal.h>
#include<String.h>
RH_ASK driver;
const int rs = 12, en = 10, d4 =5,d5 =4,d6 = 3,d7 =2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
static char message[100];
int i=0;
uint8_t buf[15];
    uint8_t buflen = sizeof(buf);
 
void setup()
{
   
    Serial.begin(9600);	// Debugging only
    if (!driver.init())
         Serial.println("init failed");
      lcd.begin(16,2);
}

void loop(){

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
     // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);
      lcd.setCursor(0,0); 
      lcd.println((char*)buf);     
      SendMessage((char*)buf);
     
    }
   
}
void SendMessage(char *NIRP)
{

  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGS=\"+919080752236\"\r");   
  delay(1000);
   if(strcmp(NIRP ,"Critical")==0)
   {
  Serial.println("Emergency:");
  Serial.println("The Person needs your Help!!!");
  Serial.println((char)26);
  }
 // Serial.println((char)26);
  delay(5000);
}

