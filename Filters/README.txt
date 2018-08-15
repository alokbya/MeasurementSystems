This lab consists of filtering data, or noise by use of various methods. Software and hardware
filters are used to clean up lab data from an accelerometer and thermistor, and an interrupt is
used to reduce the noise from button bouncing within a circuit.
The first section in this lab is specific to sensor filtering. During this part, we created a software
filter to implement a moving average on previously recorded data, from both week 1 and week
2. By use of the MATLAB function movmean(), a moving average of the temperature data was
calculated with 10, 25, 50 and 100 samples. This process was also performed on the light
sensor data from Lab 1. Next, a moving average was implemented in real-time data collection.
This was performed with the accelerometer, recording voltage.
The following section incorporated the use of a hardware filter, namely a low-pass filter, to the
accelerometer circuit. For this, data from Lab 2 with voltage information from the fast-aspossible
trial was cleaned up. The objective was to reduce the noise surrounding the frequency
that the accelerometer was rotated. 0.7 Hz, 4 Hz and 6 Hz were the cutoff frequencies we chose
to eliminate from the FFT plot. The low-pass filters included a 1 microFarad capacitor and a set
of three different resistors whose values depend of the desired cutoff frequency.
The second section in this lab involved button debouncing. The phenomena of button bouncing
occurs due to mechanical and physical issues, generating false transactions when pressed. The
act of debouncing means to check and verify to ensure that the button is actually pressed. This
prevents unpredictable results. For this section, a circuit with two LEDs, two 330 ohm resistors,
a button and several wires were used to demonstrate the effect of debouncing. 