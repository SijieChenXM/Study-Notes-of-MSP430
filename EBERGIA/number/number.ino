int a = P1_0;
int b = P1_1;
int c = P1_2;
int d = P2_0;
int e = P1_4;
int f = P1_5;
int g = P1_6;
int dp = P1_7;
char x=0;
int y=0;
int z=0;
const unsigned char LED8Pin[]={a,b,c,d,e,f,g,dp};
const unsigned char LED8Code[]= { 0xC0, 0xF9, 0xA4, 0xB0,0x99, 0x92,0x82, 0xF8, 0x80, 0x90, 0x88, 0x83,0xC6,0xA1,0x86,0x8E };    
void setup() {
  pinMode(P2_2,INPUT_PULLUP);
  pinMode(P1_3,INPUT_PULLUP);
char i;
for(i=0;i<8;i++)
{
pinMode(LED8Pin[i], OUTPUT);
digitalWrite(LED8Pin[i],HIGH);
}
}
void LED8Display(char data)
{
char m;
char n;
char dis;
if((0<=data)&&(data<16))
{
dis = LED8Code[data];
for(m=0;m<8;m++)
{
n = bitRead(dis,m);
digitalWrite(LED8Pin[m], !n);
}
}
}

void loop() {
  // put your main code here, to run repeatedly: 
if(x==16){
  x=0;
}
if(x==-1){
  x=15;
}
if(digitalRead(P1_3)==LOW)
{
delay(10); 
if(digitalRead(P1_3)==LOW&&z==0)
{
  x--;
  z++;
}
}
else  
{
  delay(10); 
  if(digitalRead(P1_3)==HIGH)
  {
   z=0;
  }
}
if(digitalRead(P2_2)==LOW)
{
delay(10); 
if(digitalRead(P2_2)==LOW&&y==0)
{
  x++;
  y++;
}
}
else
{
  delay(10); 
  if(digitalRead(P2_2)==HIGH)
  {
    y=0;
  }
}
LED8Display(x);
}


