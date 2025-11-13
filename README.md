# Smart_Street_Light_using_LDR

1. [Introduction](#introduction)
2. [Working](#working).
     [steps](#steps)
3.[Circuit View](#circuitview)
4.[Schematic view](#schematicview)
5.[Code](#code)
6.[Components list](#componentslist)

## Introduction
The Smart Street Light using LDR project is an automation-based system designed to control street lights intelligently based on ambient light conditions. Traditional street lighting systems operate manually or on fixed timers, leading to unnecessary power consumption when lights remain ON during daylight hours. To overcome this limitation, the proposed system uses an LDR (Light Dependent Resistor) sensor that automatically detects surrounding light intensity and switches the street lights ON or OFF accordingly.

In this system, when the ambient light level decreases (during evening or night), the LDR’s resistance increases, signaling the microcontroller (such as Arduino UNO) to turn ON the street lights. Conversely, when daylight increases, the LDR resistance decreases, and the lights are automatically turned OFF, ensuring efficient energy usage.
## Working
The Smart Street Light using LDR project works on the simple principle of resistance change in the Light Dependent Resistor (LDR) with varying light intensity. An LDR is a sensor whose resistance decreases with increasing light intensity and increases with decreasing light intensity. This behavior is used to detect day and night conditions.

In this system, the LDR is connected to the analog input (A0) of an Arduino UNO (or microcontroller). The microcontroller continuously monitors the voltage level from the LDR sensor.

During daytime or when sufficient ambient light is present, the LDR receives more light, so its resistance becomes low, producing a high voltage at the analog input. The microcontroller interprets this as daylight and turns the LED/street light OFF.

During nighttime or in darkness, the LDR receives little or no light, causing its resistance to increase. This produces a low voltage at the analog input. The microcontroller detects this as darkness and turns the LED/street light ON.
### steps
1.Power ON: The system initializes and sets the LED pin as output.

2.LDR Sensing: The LDR continuously senses ambient light intensity.

3.Analog Reading: The Arduino reads the LDR’s analog voltage (0–1023 range).

4.Decision Making:

  If sensor value < threshold → it’s dark → LED ON

  If sensor value ≥ threshold → it’s bright → LED OFF

5.Output Control: The LED (street light) turns ON/OFF automatically based on these readings.

 Example Threshold

If the LDR value (analogRead) is below 500, it indicates low light → LED turns ON.
If the value is above 500, it indicates bright light → LED turns OFF.
## Circuit View
<img width="983" height="758" alt="image" src="https://github.com/user-attachments/assets/95b80369-d9f4-49b9-8b9f-4bfa2d2e05ab" />
## Schematic view
<img width="1331" height="757" alt="image" src="https://github.com/user-attachments/assets/1b962497-2914-45b6-a3ee-9a41a90cd77e" />
### Code
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

### Components list
<img width="857" height="636" alt="image" src="https://github.com/user-attachments/assets/bb77851c-a07f-44f4-83c5-e5c5c0edae21" />

