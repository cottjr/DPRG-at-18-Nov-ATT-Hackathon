/******************************************************************
 *       Define standard Romeo motor PWM DC control pins.         *
 ******************************************************************/
//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

/******************************************************************
 *         Define standard Romeo motor control routines.           *
 ******************************************************************/
void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void setup(void) 
{
  /******************************************************************
   *    The following sets up the Romeo motor pins for output.      *
   ******************************************************************/
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);
  /******************************************************************
   *    The following script makes the Romeo to move forward,       *
   *    turn left 90deg, turn right 90deg three times, and stops.   *
   ******************************************************************/
  int forward = 12000; 
  int turn90deg = 5000;
  int waitTime = 10000;
  // wait 1 sec after reset
  delay(1000);
  // move forward 2 ft (est 4 sec) and stop
  advance(255,255);
  delay(forward);
  stop();
//  // wait 1 sec
//  delay(1000);
//  // rotate left 90deg and stop
//  turn_L(100,100);
//  delay(turn90deg);
//  stop();
  // wait
  delay(waitTime);
  // rotate right 90deg and stop
  turn_R(100,100);
  delay(turn90deg);
  stop();
  // wait
  delay(waitTime);
   // rotate right 90deg and stop
  turn_R(100,100);
  delay(turn90deg);
  stop();
} 
void loop(void) 
{
}
