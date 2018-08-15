int yellow = 2;
int white = 4;
int int_flag = 1;
volatile signed int encoder0Pos = 0;
signed int netDistance = 0;
float distance = 0;
float circumference = 10*3.142;
float velocity = 0;
float current = 0;
float voltage = 0;
unsigned long time;
int zz = 1;
void setup() {
Serial.begin(230400);
pinMode(yellow,INPUT);
pinMode(white,INPUT);
pinMode(12, OUTPUT);
pinMode(9, OUTPUT);
pinMode(3, OUTPUT);
attachInterrupt(digitalPinToInterrupt(yellow),direction,CHANGE);
}
void loop() {
time = millis();
distance = encoder0Pos*((circumference)/(960));
float d1 = distance;
float x1 = encoder0Pos;
float dt = 100.00;
delay(100);
float d2 = encoder0Pos*((circumference)/(960));
float x2 = encoder0Pos;
float dd = d2 - d1;
float dx = x2 - x1;
float rpm = ((dx/960)/(dt))*(1000)*(60); //rpm
velocity = (dd/dt)*1000;
voltage = getVoltage(A0);
current = voltage/1.65;
if( encoder0Pos > 5000){
digitalWrite(12, HIGH);
digitalWrite(9, LOW);
analogWrite(3, 255);
}
else if(encoder0Pos < 0){
digitalWrite(12, LOW);
digitalWrite(9,LOW);
analogWrite(3,255);
}
Serial.print(encoder0Pos, DEC); //ticks
Serial.print(", ");
Serial.print(distance); //distance
Serial.print(", ");
Serial.print(velocity); //distance/ 100 ms
Serial.print(", ");
Serial.print(rpm); //amperes
Serial.print(", ");
Serial.print(current);
Serial.print(", ");
Serial.println(time);
delay(1);
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
encoder0Pos = encoder0Pos + 1; //CCW
}
else {
encoder0Pos = encoder0Pos - 1; // CW
}
}
Serial.print(encoder0Pos, DEC);
}
//getVoltage function converts analog signal to voltage
float getVoltage(int analogSignal)
{
return(analogRead(analogSignal)* .004882814);
}
Smoothing​ ​Code
//Staging
int yellow = 2;
int white = 4;
int int_flag = 1;

