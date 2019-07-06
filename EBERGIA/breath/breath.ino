int brightness = 0;
//此变量用来表示 LED 的亮度。 
int baseTime=1000;//定义运行周期
//定义布尔值 0-1，用以控制亮或灭，以及占空比 
boolean LED_on=HIGH,count_up=false,time_add=false; 
void Duty_Cycle(boolean up); 

void setup() {
  // put your setup code here, to run once:
  pinMode(P1_0,OUTPUT);
  pinMode(P1_6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(brightness== 0||brightness==baseTime) 
  {
    LED_on=!LED_on; // 工作反向 ：亮或灭 
    count_up=!count_up; // 计数增还是减
    time_add=!time_add; // 占空比增大还是减少
  }
  digitalWrite(P1_0,!LED_on); 
  digitalWrite(P1_6,LED_on); 
  Duty_Cycle(time_add);//占空比控制 
  digitalWrite(P1_0,LED_on);//占空比控制 
  digitalWrite(P1_6,!LED_on);
  Duty_Cycle(!time_add); 
  //计数判断 
  if(count_up) brightness++; 
  else brightness--;
}
// 占空比增大还是减少判断 
void Duty_Cycle(boolean up) 
{
  if(up) 
  // 占空比增大还是减少
  delayMicroseconds(baseTime-brightness+1); 
  else
  delayMicroseconds(brightness+1);// 占空比增大
}

