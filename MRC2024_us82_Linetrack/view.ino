void view() {
  Serial.begin(9600);
  while (is_D8 == 0) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(nashi(i));
      Serial.print(",\t");
    }
    Serial.println("");
  }
  Serial.end();
}

void viewReadLine() {
  Serial.begin(9600);
  while (is_D8 == 0) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println(ReadLine());
  }
  Serial.end();
}