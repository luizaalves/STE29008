int sent,received;
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // slave
  if (Serial2.available() > 0) {
    received = Serial2.read();
  }
    digitalWrite(13, received);
}
