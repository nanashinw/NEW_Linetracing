void tn(float Speed, float Kp, float Kd) {
  position = ReadLine();
  error = position - 3500;
  powermotor = (Kp * error) + (Kd * (error - lasterror));
  lasterror = error;
  leftmotor = Speed + powermotor;
  rightmotor = Speed - powermotor;
  if (leftmotor > 100) leftmotor = 100;
  if (leftmotor < -100) leftmotor = -100;
  if (rightmotor > 100) rightmotor = 100;
  if (rightmotor < -100) rightmotor = -100;
  motor(leftmotor, rightmotor);
}

void ttime(float speed, float kp, float kd, long timer) {
  unsigned long last_time = millis();
  while (millis() - last_time <= timer) {
    tn(speed, kp, kd);
  }
}

//line 45 degree celles
void trr(float speed, float kp, float kd) {
  ReadLine();
  while (F[7] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[4] < 400 or F[7] < 400) {
    tn(speed, kp, kd);
  }
}

void tll(float speed, float kp, float kd) {
  ReadLine();
  while (F[0] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[0] < 400 or F[3] < 400) {
    tn(speed, kp, kd);
  }
}

//half line --+
void tr(float speed, float kp, float kd) {
  ReadLine();
  while (F[7] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[7] < 400) {
    tn(speed, kp, kd);
  }
}

void tl(float speed, float kp, float kd) {
  ReadLine();
  while (F[0] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[0] < 400) {
    tn(speed, kp, kd);
  }
}

//cross line
void t(float speed, float kp, float kd) {
  ReadLine();
  while (F[0] > 200 or F[7] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[0] < 400 or F[7] < 400) {
    tn(speed, kp, kd);
  }
}


