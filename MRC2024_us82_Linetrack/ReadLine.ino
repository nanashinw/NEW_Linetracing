int ReadLine() {
  unsigned long avg = 0, sum = 0;
  int online = 0;
  Read();
  for (int i = 0; i < numsensor; i++) {
    if (F[i] > 200) {
      online = 1;
    }
    if (F[i] > 50) {
      avg = avg + (F[i] * (i * 1000));
      sum = sum + F[i];
    }
  }
  if (online == 0) {
    if (last_value > (numsensor - 1) * 1000 / 2) {
      return (numsensor - 1) * 1000;
    } else {
      return 0;
    }
  } else {
    last_value = avg / sum;
  }
  return last_value;
}