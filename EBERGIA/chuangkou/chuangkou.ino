void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.print("Hello MSP430 LaunchPad!");
  delay(500);
  Serial.println("Hello EEWorld!");
  delay(500);
}
