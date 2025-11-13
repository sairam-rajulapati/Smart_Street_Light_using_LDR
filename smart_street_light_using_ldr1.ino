// Pin Definitions
const int ldrPin = A0; // LDR connected to analog pin A0
const int ledPins[] = {2, 6, 8, 10, 11, 12, 13}; // LEDs connected to digital pins

// Threshold value to detect darkness
const int threshold = 500; // Adjust based on your LDR and lighting conditions

void setup() {
  // Initialize serial communication (optional for debugging)
  Serial.begin(9600);

  // Set LED pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read the LDR value
  int ldrValue = analogRead(ldrPin);

  // Print the LDR value to the serial monitor (optional for debugging)
  Serial.println(ldrValue);

  // Check if it's dark (LDR value below the threshold)
  if (ldrValue < threshold)

  {
     Serial.println("weather is dark so lets turn LED light on");
    // Turn on all LEDs
    for (int i = 0; i < 7; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  } else {
    // Turn off all LEDs
    for (int i = 0; i < 7; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Small delay for stability
  delay(100);
}
