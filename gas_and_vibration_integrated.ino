#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);

int gasValue = A0; // smoke / gas sensor connected with analog pin A1 of the arduino.
int data = 0;
int vib_pin = 8;
int flame_pin=13;
int led_pin = 12;
int val = 0;
int flame=1;

void setup()
{
  //randomSeed(analogRead(0));
  mySerial.begin(38400); // Setting the baud rate of GSM Module
  Serial.begin(38400); // Setting the baud rate of Serial Monitor (Arduino)
  lcd.begin(16, 2);
  pinMode(gasValue, INPUT_PULLUP);
  lcd.print (" Gas Leakage ");
  lcd.setCursor(0, 1);
  lcd.print (" Detector Alarm ");
  delay(1000);
  lcd.clear();
  pinMode(vib_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin,LOW);
}

void loop()
{
  
  val = digitalRead(vib_pin);
  flame = digitalRead(flame_pin);
  data = analogRead(gasValue);
    Serial.println("Gas Level: ");
    Serial.print(data);
    delay(2);
    lcd.clear();
    lcd.setCursor(0, 0);
    delay(1000);
    lcd.print("Gas Level: ");
    lcd.print(data);
    delay(1000);
    //lcd.print ("Gas Scan is ON");

  if (data < 300){    
    Serial.println("Gas detect alarm");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Gas Level Exceed");
    lcd.setCursor(0, 1);
    SendMessageGas();
    //lcd.print("SMS Sent");
    delay(1000);
  }
  else
  {
    Serial.println("\rGas Level Low");
    lcd.setCursor(0, 1);
    lcd.print("Gas Level Normal");
    delay(1000);
    lcd.clear();
  }

  //vibration sensor
  if (val == 1)
  {
    //lcd.clear();
    Serial.println("Collision detected");
    lcd.setCursor(0, 2);
    lcd.print("Collision detected");
    digitalWrite(led_pin,HIGH);
    SendMessageCollision();
    //    lcd.setCursor(0, 3);
    //    lcd.print("Vibration detected");
    delay(1000);
  }

  //flame sensor
  if (flame==0)
  {
    //lcd.clear();
    Serial.println("Flame detected");
    lcd.setCursor(0,2);
    lcd.print("  Flame detected    ");
    digitalWrite(led_pin,HIGH); 
    SendMessageFlame();
    //    lcd.setCursor(0, 3);
    //    lcd.print("Fire detected");
    delay(1000);
  }

  //lcd.clear();
}


void SendMessageGas()
{
  Serial.println("Sending...");
  Serial.println("AT\r");        //AT is the abbreviation of Attention. Checking communication.
  delay(1000);
  Serial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
  delay(1000); // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+918903291669\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("Excess Gas Detected");// The SMS text you want to send
  delay(1000);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println();
  Serial.println("Text sent");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("Alert Gas");
  delay(100);
}

void SendMessageCollision()
{
  Serial.println("Sending...");
  Serial.println("AT\r");        //AT is the abbreviation of Attention. Checking communication.
  delay(1000);
  Serial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
  delay(1000); // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+918903291669\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("Collision Detected");// The SMS text you want to send
  delay(1000);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println();
  Serial.println("Text sent");
  delay(100);
  lcd.setCursor(0, 1);  
  lcd.print("Alert Collision");
  delay(100);
}

void SendMessageFlame()
{
  Serial.println("Sending...");
  Serial.println("AT\r");        //AT is the abbreviation of Attention. Checking communication.
  delay(1000);
  Serial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
  delay(1000); // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+918903291669\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("Flame Detected");// The SMS text you want to send
  delay(1000);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println();
  Serial.println("Text sent");
  lcd.setCursor(0, 1);
  lcd.print("Alert Flame");
  delay(100);
}
