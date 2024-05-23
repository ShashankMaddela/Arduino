int enable1 = 5;
int enable2 = 3;
int inp1 = 6;
int inp2 = 7;
int inp3 = 8;
int inp4 = 9;
int potv = A1;
int potd = A0;
int vel;
int speed;
int dir;
int d;
int encoder1PinA = 10;
int encoder1PinB = 11;
int encoder2PinA = 12;
int encoder2PinB = 13;
volatile int encoder1Pos = 0;
volatile int encoder2Pos = 0;

void setup()
{
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(inp3, OUTPUT);
  pinMode(inp4, OUTPUT);
  pinMode(potv, INPUT);
  pinMode(potd, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
  pinMode(encoder2PinA, INPUT);
  pinMode(encoder2PinB, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(encoder1PinA), updateEncoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder2PinA), updateEncoder2, CHANGE);

  Serial.begin(9600);
}

void loop()
{
  d = analogRead(potd);
  vel = analogRead(potv);
  speed = map(vel, 0, 1023, 0, 255);
  dir = map(d, 0, 1023, 0, 255);
  
  analogWrite(enable1, speed);
  analogWrite(enable2, speed);

  if (125 <= dir && dir <= 135)
  {
    digitalWrite(inp1, HIGH);
    digitalWrite(inp2, LOW);
    digitalWrite(inp3, HIGH);
    digitalWrite(inp4, LOW);
  }
  if (dir < 125)
  {
    digitalWrite(inp1, HIGH);
    digitalWrite(inp2, LOW);
    digitalWrite(inp3, LOW);
    digitalWrite(inp4, HIGH);
  }
  if (dir > 135)
  {
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, HIGH);
    digitalWrite(inp3, HIGH);
    digitalWrite(inp4, LOW);
  }

  Serial.println("vel = " + String(vel) + ", Speed = " + String(speed) + " direction = " + String(dir) +
                 ", Encoder1 = " + String(encoder1Pos) + ", Encoder2 = " + String(encoder2Pos));
  
  delay(1000);
}

void updateEncoder1()
{
  if (digitalRead(encoder1PinB) == HIGH)
    encoder1Pos++;
  else
    encoder1Pos--;
}

void updateEncoder2()
{
  if (digitalRead(encoder2PinB) == HIGH)
    encoder2Pos++;
  else
    encoder2Pos--;
}
