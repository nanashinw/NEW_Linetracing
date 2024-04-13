
//define pin motorA
#define dir1A 2
#define dir2A 3
#define pwmA 5

//define pin motorB
#define dir1B 4
#define dir2B 7
#define pwmB 6

void motor(int speedL, int speedR) {
  speedL = (speedL * 255) / 100;
  speedR = (speedR * 255) / 100;

  //motor Left speed
  if (speedL == 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, 0);
  } else if (speedL > 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, speedL);  //50 = 50
  } else {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, -speedL);  //-(-50) = 50
  }

  //motor Right speed
  if (speedR == 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, 0);
  } else if (speedR > 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, speedR);  //50 = 50
  } else {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, -speedR);  //-(-50) = 50
  }
}

void Setup_Motor(){
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(pwmB, OUTPUT);
}
