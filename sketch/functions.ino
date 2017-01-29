// These functions set the pin settings for each of the four steps per rotation of the motor (keepp in mind that the motor in the kit is geared down,
// i.e. there are many steps necessary per rotation
void Step_A(){
  digitalWrite(stepperPin1, HIGH); // Turn on coil 1 
  digitalWrite(stepperPin2, LOW); 
  digitalWrite(stepperPin3, LOW); 
  digitalWrite(stepperPin4, LOW); 
}
void Step_B(){
  digitalWrite(stepperPin1, LOW); 
  digitalWrite(stepperPin2, HIGH); // Turn on coil 2
  digitalWrite(stepperPin3, LOW); 
  digitalWrite(stepperPin4, LOW); 
}
void Step_C(){
  digitalWrite(stepperPin1, LOW); 
  digitalWrite(stepperPin2, LOW); 
  digitalWrite(stepperPin3, HIGH); // Turn on coil 3
  digitalWrite(stepperPin4, LOW); 
}
void Step_D(){
  digitalWrite(stepperPin1, LOW); 
  digitalWrite(stepperPin2, LOW); 
  digitalWrite(stepperPin3, LOW); 
  digitalWrite(stepperPin4, HIGH); // Turn on coil 4
}
void step_OFF(){
  digitalWrite(stepperPin1, LOW); // Power all coils down
  digitalWrite(stepperPin2, LOW); 
  digitalWrite(stepperPin3, LOW); 
  digitalWrite(stepperPin4, LOW); 
}

// These functions run the above configurations in forward and reverse order
// The direction of a stepper motor depends on the order in which the coils are turned on.
void forward(int delaytime){ // One tooth forward
  Step_A();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_D();
  delay(delaytime);
}
