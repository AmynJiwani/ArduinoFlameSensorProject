/*
    Flame Sensor Assignment 
    December 3rd, 2019
    Amyn J. & Eric P.
    
    This program determines how close/hot a flame is to the sensor relative to a certain value. As the flame sensor senses hotter or colder substances it prints the 
    subsequent value and additionally says if its getting hotter or colder.
    
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
String hot = "It is really hot  ";    //String"""   makes it so when the sensor value is equal to the string commands it prints the specific serial
String warmer = "Getting hotter  ";
String warm = "Warm  ";
String cold = "Cool  ";
int highestValue = 0;
int lowestValue = 1023;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);   // read the value from the sensor
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
    delay(sensorValue);      // stop the program for <sensorValue> milliseconds:
  digitalWrite(ledPin, LOW);  // turn the ledPin off:
  // stop the program for for <sensorValue> milliseconds:
  delay(1500);      // delay the program for for milliseconds
  
  
  if(sensorValue > 600) {
     Serial.print(hot);            //If sensor senses a lot of heat print the above values
  }
  if(sensorValue > 100 && sensorValue < 600){
     Serial.print(warmer);        //If sensor sinces it getting warmer print "getting hotter"
  }
  if(sensorValue > 10 && sensorValue < 100){
     Serial.print(warm);      //If sensor is warm print "warm"
  }
  if(sensorValue < 10){
     Serial.print(cold);    //If sensor senses no heat print "cool"
  }
  
    Serial.println(sensorValue);      //Prints value sensed by sensor 
    
    if(sensorValue > highestValue){    //Sets what is lowest value
       highestValue = sensorValue;     
  }
  
    if(sensorValue < lowestValue){    //Sets what is the highest value
       lowestValue = sensorValue;
    }
    
   Serial.print(" Highest Value  ");       // Prints highest value
          Serial.print(highestValue  ); 
   Serial.print(" Lowest Value  ");        // Prints lowest value
         Serial.println(lowestValue  );
         Serial.println("");              //Leaves blank line for next loop
          
}
