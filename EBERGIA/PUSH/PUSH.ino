volatile int state = HIGH;
volatile int flag = HIGH;
int x = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, state);

  /* Enable internal pullup. 
   * Without the pin will float and the example will not work */
  pinMode(P1_3, INPUT_PULLUP);
  attachInterrupt(P1_3, blink, FALLING); // Interrupt is fired whenever button is pressed
}

void loop()
{
  digitalWrite(GREEN_LED, state); //LED starts ON
  if(flag) {
    x++;
    Serial.println(x);
    flag = LOW;
  }
}

void blink()
{
  state = !state;
  flag = HIGH;
}
