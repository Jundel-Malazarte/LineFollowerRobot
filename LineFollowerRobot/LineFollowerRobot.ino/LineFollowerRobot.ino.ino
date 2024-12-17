#define enA 10 // Enable1 L298 Pin enA
#define in1 9  // Motor1 L298 Pin in1
#define in2 8  // Motor1 L298 Pin in2
#define in3 7  // Motor2 L298 Pin in3
#define in4 6  // Motor2 L298 Pin in4
#define enB 5  // Enable2 L298 Pin enB

#define R_S A0 // IR sensor Right
#define L_S A1 // IR sensor Left

void setup() { 
  // Initialize pins
  pinMode(R_S, INPUT); // Declare IR sensor as input  
  pinMode(L_S, INPUT); // Declare IR sensor as input

  pinMode(enA, OUTPUT); // Declare as output for L298 Pin enA 
  pinMode(in1, OUTPUT); // Declare as output for L298 Pin in1 
  pinMode(in2, OUTPUT); // Declare as output for L298 Pin in2 
  pinMode(in3, OUTPUT); // Declare as output for L298 Pin in3   
  pinMode(in4, OUTPUT); // Declare as output for L298 Pin in4 
  pinMode(enB, OUTPUT); // Declare as output for L298 Pin enB 

  // Set motor speeds
  analogWrite(enA, 150); // Set speed for Motor1
  analogWrite(enB, 150); // Set speed for Motor2
  delay(1000);           // Short delay before entering main loop
}

void loop() {  
  // Check IR sensor readings and perform corresponding actions
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) {
    forward(); // Both sensors detect white, move forward
  } else if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) {
    turnRight(); // Right sensor detects black, turn right
  } else if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) {
    turnLeft(); // Left sensor detects black, turn left
  } else if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) {
    stopMotors(); // Both sensors detect black, stop
  }
}

void forward() {  
  // Move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() { 
  // Turn right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() { 
  // Turn left
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotors() { 
  // Stop motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
