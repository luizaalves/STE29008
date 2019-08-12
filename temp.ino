int led = 13;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  le_temp(sensorValue);
  delay(2000);
  imprime_res();
}

void led_on(int pin){
  digitalWrite(led,HIGH);
}

void led_off(int pin){
  digitalWrite(led,LOW);
}

void le_temp(int pin){
  sensorValue = analogRead(pin);
  led_on(led);
}

void imprime_res(){
  Serial.println(sensorValue);
  led_off(led);
}

