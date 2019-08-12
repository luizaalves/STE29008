int sensorPin = A0;    // select the input pin for the potentiometer
int led = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue == 1023){
    led_on(led);
  }
  //delay(1000);
}

void led_on(int pin){
  digitalWrite(led,HIGH);
}
