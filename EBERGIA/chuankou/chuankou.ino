void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.print("Hello MSP430 LaunchPad!");
  delay(500);
  Serial.println("Hello EEWorld!");
  delay(500);
}
