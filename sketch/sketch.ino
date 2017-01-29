void setup() {
  // put your setup code here, to run once: 
  pinMode(2, OUTPUT); 

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  digitalWrite(2, 1);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(2, 0);    // turn the LED off by making the voltage LOW
  delay(1000);

  
  
}
