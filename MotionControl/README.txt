This lab will utilize the standard Vilros Arduino Uno Kit, the Arduino PID library, the
Arduino motor shield from lab 4, the motor with quadrature encoder, and 12 V power supply.
Additionally, MATLAB will be used to plot the PID response to the motor.
This lab requires the use of the Arduino PID library to control the motor. The objective is
to specify the PID parameters Kd, Ki, and Kp, which signify the derivative constant, integral
constant, and proportional constant respectively, in order to obtain a critical damping response
from the PID. During this lab, Ki will be set to 0, and not changed thereafter.
After importing the PID library, all parameters were set to initial values in order to run the
motor. The following step required the manipulation of Kp and Kd to produce a critically-damped
response to a setpoint of 1500 ticks. A tuning map was created, with plots, of angle vs time,
demonstrating the effects of different damping ratios on the system response. Following this
step, a variable time delay was inserted at values equal to 1ms, 10ms, 100ms, 1000ms, and
5000ms. By doing this we were able to see that beyond 100ms delay, the motor encoder would
surpass the setpoint, and change direction in full force. This produced dramatic plots with large
fluctuations in position.
A plot demonstrating system response to a sine wave control target was created. During
this portion of the lab, we were able to determine phase lag, amplitude attenuation, and stability
of the system.
Finally, using the critically-damped system, different time delays were inserted at the end
of the loop and a plot of encoder ticks vs time was created by importing the serial data through
PuTTy to a .csv file, and then processed in MATLAB.