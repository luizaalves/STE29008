#define led 13
#define sensorPin A0

#define beta 3950.0
//#define r0 10000.0
//#define t0 298.15
//#define vout_d 753.0
#define vin 1023.0
#define rinf 0.01763

float temperatura;
float temp_kelvin;
float r;
int sensorValue;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led,LOW);

}

void loop() {
  led_on(led);
  calculo_temp();
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
void calculo_temp(){
  sensorValue = analogRead(sensorPin);
  r = 10e3*((vin/sensorValue)-1);
  temp_kelvin = beta/log(r/rinf);
  temperatura = temp_kelvin - 273.15;
}
void imprime_res(){
  Serial.print("temperatura(°C): ");
  Serial.println(temperatura);
}
