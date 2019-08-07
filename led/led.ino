int BTN1 = 2;
int BTN2 = 3;
int LED1 = 8;
int LED2 = 9;
boolean flag1,flag2;

void setup() {
  pinMode(BTN1,INPUT);
  pinMode(BTN2,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

  led_off(LED1);
  led_off(LED2);

  flag1=false;
  flag2=false;
}

void loop() {
 
  if(push_button1()){
    led_on(LED1);  
  }
  else{
    led_off(LED1);
  }
  if(push_button2()){
    led_on(LED2);  
  }
  else{
    led_off(LED2);
  }
}

void led_on(int pin){
  digitalWrite(pin,HIGH);
 
}
void led_off(int pin){
  digitalWrite(pin,LOW);  
}
boolean push_button1(){
  if(digitalRead(BTN1)==LOW){
    return true; 
  }
  else{
    return false;
  }
}
boolean push_button2(){
  if(digitalRead(BTN2)==HIGH){
    return true; 
  }
  else{
    return false;

  }
}
