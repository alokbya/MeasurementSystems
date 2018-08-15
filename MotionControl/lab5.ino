//Staging
int yellow = 2;
int white = 4;
int int_flag = 1;
volatile signed int encoder0Pos = 0;
#include <PID_v1.h>
unsigned long time;
double Setpoint, Input, Output;
double Kp=.5, Ki=0, Kd=.05;
//vary Kp and Kd as needed
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
void setup() {
myPID.SetOutputLimits(-255, 255);
Serial.begin(9600);
pinMode(yellow,INPUT);
pinMode(white,INPUT);
pinMode(12, OUTPUT);
pinMode(9, OUTPUT);
attachInterrupt(digitalPinToInterrupt(yellow),direction,CHANGE)
;
Input = encoder0Pos;
//Setpoint = 1500;
//Use for parts 1-4
myPID.SetMode(AUTOMATIC);
}
void loop() {
time=millis();
Setpoint = 500 * sin(.5*2*3.14*time/1000); // use for part
4-6. Vary amp and frequency as needed
Input = encoder0Pos;
myPID.Compute();
if (Output < 0){
digitalWrite(12, HIGH);
digitalWrite(9, LOW);
analogWrite(3, abs(Output));
}
else if (Output > 0){
digitalWrite(12, LOW);
digitalWrite(9, LOW);
analogWrite(3, Output);
}
else{
digitalWrite(12, LOW);
digitalWrite(9, HIGH);
analogWrite(3, Output);
}
//Serial.print(Output,DEC);
//Serial.print(time);
//Serial.print(", ");
Serial.print(time);
Serial.print(", ");
Serial.print(Setpoint);
Serial.print(", ");
Serial.println(encoder0Pos, DEC); //ticks
delay(1000);
}
void trigger(){
Serial.print("Interrupt triggered: ");
Serial.print(int_flag);
Serial.println(" times");
int_flag = int_flag + 1;
}
void direction(){
if (digitalRead(yellow)==HIGH){
if (digitalRead(white)==LOW){
encoder0Pos = encoder0Pos - 1; //CCW
}
else {
encoder0Pos = encoder0Pos + 1; // CW
}
}
else
{
if (digitalRead(white)==LOW){
encoder0Pos = encoder0Pos + 1; //CW
}
else {
encoder0Pos = encoder0Pos - 1; // CCW
}
}
}
float getVoltage(int analogSignal)
{
return(analogRead(analogSignal)* .004882814);
}
