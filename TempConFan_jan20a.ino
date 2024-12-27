// Thermistor Setup Calculations

const int thermistorPin = A0; // Replace with your actual analog pin
const int fanControlPin = 9; // Replace with your actual fan control pin
const float pad = 10000.0;    // Resistance of your balance/pad resistor (10k in this case)
const float thresholdTemperature = 25.0; // Adjust this threshold temperature as needed

// Define the pin numbers for the three LEDs
#define LD1 LED_BUILTIN
#define LD2 PA5
#define LD3 PB14

float Thermistor(int rawADC) {
  long resistance;
  float temp; // Dual-Purpose variable to save space.

  resistance = pad * ((1024.0 / rawADC) - 1);
  temp = log(resistance);
  temp = 1 / (0.001129148 + (0.000234125 * temp) + (0.0000000876741 * temp * temp * temp));
  temp = temp - 273.15; // Convert Kelvin to Celsius

  return temp; // Return the Temperature
}

void setup() {
  pinMode(fanControlPin, OUTPUT);
  // Initialize the three LED pins as outputs
  pinMode(LD1, OUTPUT);
  pinMode(LD2, OUTPUT);
  pinMode(LD3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float supplyTemperature;

  supplyTemperature = Thermistor(analogRead(thermistorPin));
  delay(10);
  supplyTemperature = Thermistor(analogRead(thermistorPin));
  delay(10);

  Serial.print("Supply Temperature: ");
  Serial.print(supplyTemperature);
  Serial.println(" °C");

  // Fan control logic
  if (supplyTemperature > thresholdTemperature) {
    // LED pattern indicating the fan is ON
    digitalWrite(LD1, HIGH);
    digitalWrite(LD2, HIGH);
    digitalWrite(LD3, LOW);
    delay(500);
    digitalWrite(LD1, LOW);
    digitalWrite(LD2, LOW);
    digitalWrite(LD3, LOW);
    delay(500);

    digitalWrite(fanControlPin, HIGH); // Turn the fan on
  } else if (supplyTemperature >= 20.0 && supplyTemperature <= 25.0) {
    // LED pattern indicating "ready to turn on fan"
    digitalWrite(LD1, HIGH);
    digitalWrite(LD2, LOW);
    digitalWrite(LD3, HIGH);
    delay(1000);
    digitalWrite(LD1, LOW);
    digitalWrite(LD2, HIGH);
    digitalWrite(LD3, LOW);
    delay(1000);

    digitalWrite(fanControlPin, LOW); // Turn the fan off
  } else {
    // LED pattern indicating the fan is OFF
    digitalWrite(LD1, LOW);
    digitalWrite(LD2, HIGH);
    digitalWrite(LD3, LOW);
    delay(500);
    digitalWrite(LD1, LOW);
    digitalWrite(LD2, LOW);
    digitalWrite(LD3, HIGH);
    delay(500);

  digitalWrite(fanControlPin, LOW); // Turn the fan off
  }

  delay(1000); // Adjust the delay based on your desired update rate
}
