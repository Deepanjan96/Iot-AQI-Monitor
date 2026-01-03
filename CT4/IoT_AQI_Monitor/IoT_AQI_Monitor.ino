#define PM25_PIN 34
#define CO2_PIN  35

void setup() {
  Serial.begin(115200);
}

void loop() {

  // Read potentiometers
  int pmRaw  = analogRead(PM25_PIN);
  int co2Raw = analogRead(CO2_PIN);

  // Convert to real values
  int pm25 = map(pmRaw, 0, 4095, 0, 200);
  int co2  = map(co2Raw, 0, 4095, 400, 2000);

  // Air quality logic
  String status;
  if (pm25 <= 50 && co2 < 800)
    status = "GOOD";
  else if (pm25 <= 100 && co2 < 1200)
    status = "MODERATE";
  else
    status = "POOR";

  // Output
  Serial.print("PM2.5: ");
  Serial.print(pm25);
  Serial.print(" ug/m3 | CO2: ");
  Serial.print(co2);
  Serial.print(" ppm | Status: ");
  Serial.println(status);

  delay(2000);
}
