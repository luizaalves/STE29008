int led = 13;
int sensorPin = A0;
float sensorValue;
long int temperatura;
long int beta;
float r0,t0;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led,LOW);
  sensorValue = 0;
  temperatura = 0;

  r0 = 10e5;
  t0 = 298.15;
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
  int temp1 = micros();
  sensorValue = analogRead(pin);
  calculo_temp();
  int temp2 = micros();
  Serial.print("tempo(ms): ");
  Serial.println(temp2-temp1);
}

void imprime_res(){
  Serial.print("temperatura(°C): ");
  Serial.println(temperatura);
}

void calculo_temp(){
  long int vout = sensorValue;
  long int r = (10e3)*(((1023e2)/vout)-1e2);
  long int temp_kelvin = (t0*beta)/(beta+(t0*log(r/r0)));
  temperatura = temp_kelvin - 273.15;
}
