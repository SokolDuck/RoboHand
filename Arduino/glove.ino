#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
String send; 
//string to send
void setup()  
{
  // set digital pin to control as an output
  pinMode(13, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(38400);
  // Send test message to other device
  BT.println("Hello from Arduino");
  send = String();
}
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {   
      int sensorValue0 = analogRead(A0);
      int sensorValue1 = analogRead(A1);
      int sensorValue2 = analogRead(A2);
      int sensorValue3 = analogRead(A3);
      int sensorValue4 = analogRead(A4);
      send = send + '~' + sensorValue0 + '.' + sensorValue1 + '.'+ sensorValue2 + '.' + sensorValue3 + '.' +sensorValue4 + '#';
      BT.println(send);
      send = String();
    // you can add more "if" statements with other characters to add more commands
  }
}
