#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

int trigPin = 11;   
int echoPin = 12;   
float duration, cm, inches;
 
void setup() {
  
  Serial.begin (9600);
  lcd.begin(16,2);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  lcd.print(inches);
  lcd.print("in, ");
  lcd.print(cm);
  lcd.print("cm");
  lcd.println();
  
  delay(1000);
}
