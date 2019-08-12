int led = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,output);
  digitalWrite(led,high);
}

void loop() {
  // put your main code here, to run repeatedly:
  led_on(led)
  le_temp()
  delay(1000);
  
  led_off(led)
  imprime_res()
  delay(1000);
}

void led_on(int pin){
  digitalWrite(led,high);
}

void led_off(int pin){
  digitalWrite(led,low);
}

void le_temp(){
  
}

void imprime_res(){
  
}

