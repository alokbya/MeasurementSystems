This lab consisted of interrupts, an Arduino V2 Motorshield, and a SainSmart Metal
Gearmotor with 64 CPR Encoder. The objective of this lab was to become familiar with the
Arduino motorshield and encoder to control the motor and take a variety of relevant
measurements. These measurements included:
? Net distance traveled
? Ticks per motor shaft revolution
? Speed calculations (velocity)
? Current as read by motorshield current sensor
? Stall current of motor
This lab required the use of an interrupt to engage the encoder at the moment the drive
shaft of the motor began to rotate. With the interrupt in place, we were able to count the number
of encoder ticks per revolution of the drive shaft. Using the given wheel circumference at the
end of the drive shaft, we were able to calculate the distance traveled by the wheel in terms of
encoder ticks, which were then converted to units of distance. Exact units were not used, as the
wheel circumference given was 10p. The velocity measurement required a delay of 100 ms to
gather information about the rotation of the drive shaft of the motor. The velocity calculation
incorporates both magnitude and direction of the velocity of the motor.
The next stage of the lab was to implement current sensing; a feature of the motorshield
allows for determining this value relatively easily. Plots were made by use of PuTTy, funneling
the real-time data from the encoder to a .csv file and then using MATLAB to plot the data.
The no-load speed of the motor was determined by running the motor at its maximum
speed to determine the maximum revolutions per minute. The no-load speed was found to have
a maximum of 255 rpm. Finally, stall current was determined. This phenomenon occurs with the
load torque is greater than the shaft torque, and was achieved by stopping the motor at full
speed with pliers. A current sensing plot demonstrates a spike in current when load torque
overcomes the shaft torque.