intbrightness= 0;//此变量用来表示 LED 的亮度。 intbaseTime=2000;//定义运行周期 //定义布尔值 0-1，用以控制亮或灭，以及占空比 booleanLED_on=HIGH,count_up=false,time_add=false; voiddelay_count_fun(boolean);
voidsetup() { // 定义 P1.4 引脚为输出 pinMode(P1_4,OUTPUT); }
voidloop() { /*brightness 等于 0 或是等于定义的周期时就程序反向运行， *意思是原先亮的变成灭，原先占空比增大就变为减小*/
if(brightness== 0||brightness==baseTime) { LED_on=!LED_on; // 工作反向 ：亮或灭 count_up=!count_up; // 计数增还是减 time_add=!time_add; // 占空比增大还是减少 }
digitalWrite(P1_4,!LED_on); Duty_Cycle(time_add);//占空比控制 digitalWrite(P1_4,LED_on);//占空比控制 Duty_Cycle(!time_add); //计数判断 if(count_up) brightness++; else brightness--;
}
// 占空比增大还是减少判断 voidDuty_Cycle(booleanup) { if(up) // 占空比增大还是减少 delayMicroseconds(baseTime-brightness+1); else delayMicroseconds(brightness+1);// 占空比增大 } 

