// Open Source
#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int led = 8; // define the LED pin
int digitalPin = 2; // KY-026 digital interface
int analogPin = A0; // KY-026 analog interface
int digitalVal; // digital readings
int analogVal; //analog readings

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
  //pinMode(analogPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(2, OUTPUT); 
}

void loop()
{
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("MONITORANDO >>>");
  Serial.println("MONITORANDO >>>");
  // Read the digital interface
  digitalVal = digitalRead(digitalPin);

if (analogVal > 1000)
  {
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("SEM CHAMA            ");
    digitalWrite (led, LOW);
  }
 
  if (analogVal < 500)
  {
    Serial.println(" Status: NIVEL ALTO");
    // Print a message to the LCD.
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("CHAMA DETECTADA     ");
    digitalWrite (led, HIGH);
  }
  delay(100);
 

  // Read the analog interface
  analogVal = analogRead(analogPin); 
  Serial.println(analogVal); // print analog value to serial

  delay(100);
}
