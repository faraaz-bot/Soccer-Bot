char command;

void setup() {
  pinMode(4, OUTPUT);   // Left motor forward direction
  pinMode(5, OUTPUT);   // Left motor reverse direction
  pinMode(6, OUTPUT);   // Right motor forward direction
  pinMode(7, OUTPUT);   // Right motor reverse direction
  Serial.begin(38400);  // Initialize serial communication
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.println(command);
  }
 
  switch (command) {
    case 'B':  // Move forward (all motors rotate forward)
      digitalWrite(4, LOW);  // Left motor forward
      digitalWrite(5, HIGH); // Left motor reverse
      digitalWrite(6, LOW);  // Right motor forward
      digitalWrite(7, HIGH); // Right motor reverse
      break;

    case 'F':  // Move backward (all motors rotate backward)
      digitalWrite(4, HIGH); // Left motor forward
      digitalWrite(5, LOW);  // Left motor reverse
      digitalWrite(6, HIGH); // Right motor forward
      digitalWrite(7, LOW);  // Right motor reverse
      break;

    case 'R':  // Turn left (left motors forward, right motors reverse)
      digitalWrite(4, HIGH); // Left motor forward
      digitalWrite(5, LOW);  // Left motor reverse
      digitalWrite(6, LOW);  // Right motor forward
      digitalWrite(7, HIGH); // Right motor reverse
      break;

    case 'L':  // Turn right (right motors forward, left motors reverse)
      digitalWrite(4, LOW);  // Left motor forward
      digitalWrite(5, HIGH); // Left motor reverse
      digitalWrite(6, HIGH); // Right motor forward
      digitalWrite(7, LOW);  // Right motor reverse
      break;

    case 'S':  // Stop (all motors off)
      digitalWrite(4, LOW);  // Left motor forward
      digitalWrite(5, LOW);  // Left motor reverse
      digitalWrite(6, LOW);  // Right motor forward
      digitalWrite(7, LOW);  // Right motor reverse
      break;

    default:
      // Do nothing if the command is not recognized
      break;
  }
}
