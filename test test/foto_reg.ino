int PhotosensorPin = A0; 
unsigned int sensorValue = 0;
  
void setup() {
  
pinMode(13, OUTPUT);
Serial.begin(9600);
}
  
void loop() {
  sensorValue = analogRead(PhotosensorPin); 
  Serial.print(sensorValue, DEC);
  Serial.println(""); 
  delay(500);  
}
