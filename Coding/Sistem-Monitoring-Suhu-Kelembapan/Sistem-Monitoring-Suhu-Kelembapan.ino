//Library lcd i2c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>
// Set DHT pin:
#define DHTPIN 7
// Set DHT type, uncomment whatever type you're using! 
#define DHTTYPE DHT22
// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  // Setup sensor:
  dht.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Suhu : "); // 7

  lcd.setCursor(0,1);
  lcd.print("Kelemb : "); //13
}

void loop() {
  // Wait a few seconds between measurements:
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Read the humidity in %:
  float kelembapan = dht.readHumidity();
  // Read the temperature as Celsius:
  float suhu = dht.readTemperature();

  lcd.setCursor(7,0);
  lcd.print(suhu);
  lcd.setCursor(12,0);
  lcd.print((char)223);
  lcd.setCursor(13,0);
  lcd.print("C");

  lcd.setCursor(9,1);
  lcd.print(kelembapan);
  lcd.setCursor(14,1);
  lcd.print("%");

  Serial.print("Temperature: ");
  Serial.print(suhu);
  Serial.print(" \xC2\xB0");
  Serial.print("C | ");

  Serial.print("Humidity: ");
  Serial.print(kelembapan);
  Serial.println(" % ");
  
}
