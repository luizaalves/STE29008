int sent;
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // master
  if (Serial1.available()) {
    sent = 0;
    Serial1.write(sent);
    delay(2000);
    sent = 1;
    Serial1.write(sent);
    delay(2000);
  }
}
