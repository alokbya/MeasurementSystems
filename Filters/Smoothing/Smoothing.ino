//Smoothing
const int numReadings = 10; // changes to 25, 50, 100

int readings[numReadings];
int readIndex = 0; // the index of the current
reading
int total = 0; // the running total
int average = 0; // the average
const int zPin = A2;
int sleep = 13;
int senseSelect = 12;
unsigned long time;
void setup() {
Serial.begin(9600);
// initialize all the readings to 0:
for (int thisReading = 0; thisReading < numReadings;
thisReading++) {
 readings[thisReading] = 0;
}
 digitalWrite(sleep, HIGH);
 digitalWrite(senseSelect, HIGH);
 Serial.print("Time: ");
 Serial.print(", ");
 Serial.print("Voltage: ");
 Serial.print(", ");
 Serial.println("Average: ");
}
void loop() {
time = millis();
Serial.print(time);
Serial.print(", ");
Serial.print(getVoltagez(zPin));
Serial.print(", ");

// subtract the last reading:
total = total - readings[readIndex];
// read from the sensor:
readings[readIndex] = analogRead(getVoltagez(zPin));
// add the reading to the total:
total = total + readings[readIndex];
// advance to the next position in the array:
readIndex = readIndex + 1;
// if we're at the end of the array...
if (readIndex >= numReadings) {
 // ...wrap around to the beginning:
 readIndex = 0;
}
// calculate the average:
average = total / numReadings;
// send it to the computer as ASCII digits
Serial.println(average);
delay(1); // delay in between reads for stability
}
float getVoltagez(int z)
{
return(analogRead(z)* .004882814);
}
//Button Debouncer
long debouncing_time = 15; // 0, 15, 30, 50, 100, 1000
volatile unsigned long last_micros;
int counter = 0;
void setup() {
// put your setup code here, to run once:
attachInterrupt(0, debounceInterrupt, RISING);
}
void loop() {
// put your main code here, to run repeatedly:
}
void debounceInterrupt() {
if((long)(micros() - last_micros) >= debouncinv_time * 1000) {
 Interrupt();
 last_micros = micros();
}
}
void Interrupt() {
counter++; //increment when this function is called
}


