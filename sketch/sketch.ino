#define stepperPin1 10
#define stepperPin2 11
#define stepperPin3 12
#define stepperPin4 13

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
  Serial.begin(9600);

  pinMode(stepperPin1, OUTPUT);
  pinMode(stepperPin2, OUTPUT);
  pinMode(stepperPin3, OUTPUT);
  pinMode(stepperPin4, OUTPUT);
}

void loop() {
  int currentTemp = analogRead(A0);

  float R = 1023.0/((float)currentTemp)-1.0;
  R = 100000.0*R;

  float temperature=1.0/(log(R/100000.0)/4275+1/298.15)-273.15;//convert to temperature via datasheet ;

  Serial.println(temperature);
  if(temperature > 30){
    digitalWrite(7,1);
    digitalWrite(8, !digitalRead(8));
    digitalWrite(9, !digitalRead(9));
    delay(1000); 
  }
  else{
    digitalWrite(7,0);
    digitalWrite(8, 0);
    digitalWrite(9,0);
    delay(1000);
  }

  //add logic to push notification
  
//  digitalWrite(7, 1);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(7, 0);    // turn the LED off by making the voltage LOW
//  delay(1000);

//  int val = analogRead(A0);
//  //Serial.println(val);
//
//  if (val < 250) {
//    digitalWrite(7, 1);
//    delay(1000);
//  }
//  else {
//    digitalWrite(7, 0);
//    delay(1000);
//  }
//
//  //  int val1 = analogRead(A1);
//  //  Serial.println(val1);
//
//
//
//  //  digitalWrite(8, HIGH);
//  //  delay(1000);
//  //  digitalWrite(8, LOW);
//
//  int rotateInput = analogRead(A1);
//  int i = 100;
//  while (i--) {
//    forward(10);
//  }
//
//  int temp = analogRead(A2);
//  //Serial.println(temp);
//
//  float R = 1023.0 / ((float)temp) - 1.0;
//  R = 100000.0 * R;
//
//  float temperature = 1.0 / (log(R / 100000.0) / 4275 + 1 / 298.15) - 273.15;
//
//  Serial.println(temperature);



}
