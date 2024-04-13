void move(int speedL, int speedR, int Timer) {
  motor(speedL, speedR);
  delay(Timer);
}

void l() {
  move(-50, 50, 0);
  ReadLine();
  while (F[0] > 200) {
    ReadLine();
  }
  ReadLine();
  while (F[0] < 400) {
    ReadLine();
  }
}

void r() {
  move(50, -50, 0);
  ReadLine();
  while (F[7] > 200) {
    ReadLine();
  }
  ReadLine();
  while (F[7] < 400) {
    ReadLine();
  }
}