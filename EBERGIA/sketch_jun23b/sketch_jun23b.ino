int incomingByte = 0;  // for incoming serial data
int n=0;//输入n位数
int brightness=0;
int basetime=256;
int x;
int y;
int m;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    for(m=n,x=1;m>0;m--){
      //pow函数x=pow(10,n)
      x=x*10;
    }
    brightness=brightness+(incomingByte-48)*x;
    n++;
    // say what you got:
    Serial.print("I received: ");
    Serial.println(brightness, DEC);
  }
  else{
    if(n=3)
    {
      brightness=brightness/100+(brightness/10)%10*10+brightness%10*100;
      Serial.println(brightness, DEC);
      }
      n=0;
      brightness=0;
    }
  
}
