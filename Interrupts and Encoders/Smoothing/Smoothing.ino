//Staging
int yellow = 2;
int white = 4;
int int_flag = 1;
unsigned long time2;
float circumference = 10*3.142;
long int forward = 0;
long int reverse = 0;
float distance = 0;
long int velocity = 0;
unsigned long newtime = 0;
unsigned long oldtime = 0;
long int d1 = 0;
long int d2 = 0;
int current = 0; // current sensing variable
volatile int encoder0Pos = 0; // changed from unsigned
int to int so we can use negative directionally
////////////////////////////////////globalSmooth
const int numReadings = 10;
int readings[numReadings]; // the readings from the analog input
int readIndex = 0; // the index of the current reading
int total = 0; // the running total
int average = 0; // the average
int inputPin = A0;
///////////////////////////////////endGlobalSmooth
void setup() {
Serial.begin(230400);
pinMode(yellow,INPUT);
pinMode(white,INPUT);
//motor code
//setup channel A
pinMode(12, OUTPUT); //initiates motor channel
pinMode(9, OUTPUT); //initiates brake channel
////////////////////////////////////////////////smoothSetup
// initialize serial communication with computer:
Serial.begin(9600);
// initialize all the readings to 0:
for (int thisReading = 0; thisReading < numReadings; thisReading++)
{
readings[thisReading] = 0;
}
/////////////////////////////////////endSmoothSetup
//interrupt code
attachInterrupt(digitalPinToInterrupt(yellow),direction,CHANGE);
}
void loop() {
for(encoder0Pos = encoder0Pos; encoder0Pos < 5000;){
digitalWrite(12, LOW);
digitalWrite(9, LOW);
analogWrite(3, 37);
/////////////////////////////////smoothing
// subtract the last reading:
total = total - readings[readIndex];
// read from the sensor:
readings[readIndex] = analogRead(inputPin);
// add the reading to the total:
total = total + readings[readIndex];
// advance to the next position in the array:
readIndex = readIndex + 1;
// if we're at the end of the array...
if (readIndex >= numReadings) {
// ...wrap around to the beginning:
readIndex = 0;
////////////////////////////////////////endSmooth
}
digitalWrite(9, HIGH);
delay(1000);
for(encoder0Pos = encoder0Pos; encoder0Pos > 0;){
digitalWrite(12, HIGH);
digitalWrite(9,LOW);
analogWrite(3,37);
/////////////////////////////////smoothing
// subtract the last reading:
total = total - readings[readIndex];
// read from the sensor:
readings[readIndex] = analogRead(inputPin);
// add the reading to the total:
total = total + readings[readIndex];
// advance to the next position in the array:
readIndex = readIndex + 1;
// if we're at the end of the array...
if (readIndex >= numReadings) {
// ...wrap around to the beginning:
readIndex = 0;
////////////////////////////////////////endSmooth
}
digitalWrite(9, HIGH);
delay(1000);
}
void trigger(){
Serial.print("Interrupt triggered: ");
Serial.print(int_flag);
Serial.println(" times");
int_flag = int_flag + 1;
}
float displacement(){ //needs to be
int for division in velocity
float x = encoder0Pos*((circumference)/(960));
return abs(x);
}
float motor_speed(){
int v = 0;
float dist_1 = encoder0Pos*((circumference)/(960));
float dist_2 = (abs(encoder0Pos)-1)*((circumference)/(960));
//vel = (dist_1 - dist_2)/
return v;
}
void direction(){
if (digitalRead(yellow)==HIGH){
if (digitalRead(white)==LOW){
// newtime = millis();
// d1 = encoder0Pos;
// d2 = encoder0Pos - 1;
encoder0Pos = encoder0Pos - 1; //CCW
distance = (abs(encoder0Pos*((circumference)/(960))));
// velocity = (d1 - d2)/((newtime-oldtime)*100000);
// oldtime = newtime;
}
else {
// newtime = millis();
// d1 = encoder0Pos;
// d2 = encoder0Pos + 1;
encoder0Pos = encoder0Pos + 1; // CW
distance = (abs(encoder0Pos*((circumference)/(960))));
// velocity = (d1 - d2)/((newtime-oldtime)*100000);
// oldtime = newtime;
}
}
else
{
if (digitalRead(white)==LOW){
// newtime = millis();
// d1 = encoder0Pos;
// d2 = encoder0Pos + 1;
encoder0Pos = encoder0Pos + 1; //CCW
distance = (abs(encoder0Pos*((circumference)/(960))));
// velocity = (d1 - d2)/((newtime-oldtime)*100000);
// oldtime = newtime;
}
else {
// newtime = millis();
// d1 = encoder0Pos;
// d2 = encoder0Pos - 1;
encoder0Pos = encoder0Pos - 1; // CW
distance = (abs(encoder0Pos*((circumference)/(960))));
// velocity = (d1 - d2)/((newtime-oldtime)*100000);
// oldtime = newtime;
}
}
Serial.print(encoder0Pos);
Serial.print(" : ");
Serial.print(distance);
Serial.print(" : ");
Serial.print(velocity);
Serial.print(" : ");
Serial.print(newtime);
Serial.print(" : ");
Serial.println(oldtime);
}
