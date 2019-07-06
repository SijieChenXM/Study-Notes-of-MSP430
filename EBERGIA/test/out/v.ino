int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly: 
  sensorValue = analogRead(A1); 
  float vol = sensorValue * (3.3 / 1024.0); 
  Serial.print("Voltage:");
  Serial.print(vol );
  Serial.print(" ");
  delay(100);
}
