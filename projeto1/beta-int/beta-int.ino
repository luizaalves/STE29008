int led = 13;
int sensorPin = A0;
long int sensorValue, beta, temperatura;
long int r0,t0;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led,LOW);
  sensorValue = 0;
  temperatura = 0;

  r0 = (10e3)*100;
  t0 = 29815;
  beta = 3950;
}

void loop() {
  led_on(led);
  le_temp(sensorPin);
  delay(1000);
  led_off(led);
  imprime_res();
  delay(1000);
}

void led_on(int pin){
  digitalWrite(led,HIGH);
}

void led_off(int pin){
  digitalWrite(led,LOW);
}

void le_temp(int pin){
  sensorValue = analogRead(pin);
  calculo_temp();
}

void imprime_res(){
  Serial.println("temperatura: ");
  Serial.println(temperatura);
}

void calculo_temp(){
  int vout = sensorValue;
  long int r = 10e3*(((1023/vout)*100)-1*100);
  long int temp_kelvin = (t0*beta)/(100*beta+(t0*log(r/r0)));
  temperatura = temp_kelvin - 273.15;
}
