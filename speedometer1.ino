int enable = 5;
int inp1 = 6;
int inp2 = 7;
int pot = A0;
int state;
int speed;
int Led[5]={8,9,10,11,12};

void setup()
{
  pinMode(enable, OUTPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  state = analogRead(pot);
  speed = map(state,0,1023,0,255);
  analogWrite(enable,speed);
  digitalWrite(inp1, HIGH);  
  digitalWrite(inp2, LOW);
  int numLeds = map(speed, 0, 255, 0, 5);
  int i;
  for (i = 0; i < numLeds; i++) 
  {
    digitalWrite(Led[i], HIGH);
  }
  //delay(50);
  for (i = numLeds; i < 5; i++) 
  {
    digitalWrite(Led[i], LOW);
  }
  Serial.println("State = " + String(state) + ", Speed = " + String(speed));
  delay(1000);
}