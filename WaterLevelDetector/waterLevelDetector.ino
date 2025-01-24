long distance;  // Variable to store the distance in cm
long duration;  // Variable to store the time for the echo to return

void setup() {
  pinMode(8, OUTPUT);  // Trigger pin for ultrasonic sensor
  pinMode(9, INPUT);   // Echo pin for ultrasonic sensor
  pinMode(10, OUTPUT); // Unused pin (you can remove or use for another purpose)
  pinMode(7, OUTPUT);  // Red LED
  pinMode(6, OUTPUT);  // Yellow LED
  pinMode(5, OUTPUT);  // Blue LED
  pinMode(4, OUTPUT);  // Buzzer
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  // Send the trigger pulse to the ultrasonic sensor
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);

  // Read the time it takes for the echo to return
  duration = pulseIn(9, HIGH);
  
  // Calculate the distance in cm
  distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Check distance and activate corresponding outputs
  if (distance <= 3) {
    // If the distance is 3 cm or less
    digitalWrite(7, LOW);   // Red LED off
    digitalWrite(6, LOW);   // Yellow LED off
    digitalWrite(5, HIGH);  // Blue LED on
    digitalWrite(4, HIGH);  // Buzzer on
  } 
  else if (distance > 3 && distance <= 8) {
    // If the distance is between 4 and 8 cm
    digitalWrite(7, LOW);   // Red LED off
    digitalWrite(6, HIGH);  // Yellow LED on
    digitalWrite(5, LOW);   // Blue LED off
    digitalWrite(4, LOW);   // Buzzer off
  } 
  else if (distance > 8 && distance <= 18) {
    // If the distance is between 9 and 18 cm
    digitalWrite(7, HIGH);  // Red LED on
    digitalWrite(6, LOW);   // Yellow LED off
    digitalWrite(5, LOW);   // Blue LED off
    digitalWrite(4, LOW);   // Buzzer off
  } 
  else {
    // If the distance is greater than 18 cm
    digitalWrite(7, LOW);   // Red LED off
    digitalWrite(6, LOW);   // Yellow LED off
    digitalWrite(5, LOW);   // Blue LED off
    digitalWrite(4, LOW);   // Buzzer off
  }
  
  // Wait for 100 milliseconds before taking the next reading
  delay(100);
}
