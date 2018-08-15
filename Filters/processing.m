clc
clear
clf
close all
A = csvread('Lab01T1.csv');
time = 1:length(A(:,1));
k = [10,25,50,100];
for i =(1:4)
 M(:,i) = movmean(A(:,2),k(i));
end
hold on
plot(time,A(:,2))
for i = (1:4)
 plot(time,M(:,i))
end
xlabel('Time (seconds)')
ylabel('Temp (Celsius)')
title('Filt Temp Data')
legend('raw','k=10','k=25','k=50','k=100')
clc
clear
clf
close all
A = csvread('Lab01L1.csv', 5);
time = [1:length(A(:,1))];
k = [10,25,50,100];
for i =(1:4)

 M(:,i) = movmean(A(:,1),k(i));

end
hold on
plot(time,A(:,1))
for i = (1:4)

 plot(time,M(:,i))
end
xlabel('Time (seconds*10)')
ylabel('Voltage')
title('Filt Light Data')
legend('raw','k=10','k=25','k=50','k=100')
%%
clear
clc
clf
close all
samples = ["Lab_03_a10.csv","Lab_03_a25.csv","Lab_03_a50.csv","Lab_03_a100.csv"];
for j=4 %manually change for each graph

 Mats(:,:,j)= csvread(samples(j), 30);

 time = 1:length(Mats(:,1,j));
 NumSamp = length(time);

 Fs = NumSamp/((Mats(end,1,j)-Mats(1,1,j))/1000);
 T = 1/Fs;
 L = NumSamp;
 t = (0:L-1)*T;
 figure(1)
 hold on
 
 name = ["10","25","50","100"];

 for i = 2:3
 plot(1000*t(1:NumSamp),Mats(:,i,j))
 end
 title(name(j))
 xlabel('t (milliseconds)')
 ylabel('X(t)')
 legend('raw','Avg')
 Y(:,:,j) = fft(Mats(:,:,j));

 figure(2)
 for i = 2:3
 P2 = abs(Y(:,i,j)/L);
 P1 = P2(1:L/2+1);
 P1(2:end-1) = 2*P1(2:end-1);

 f = Fs*(0:(L/2))/L;
 plot(f,P1)
 hold on
 end

 title(name(j))
 xlabel('f (Hz)')
 ylabel('|P1(f)|')
 legend('raw','Avg')
end
%%
clear
clc
clf
close all

M = csvread('Lab03Filter_1Hz.csv', 20);
time = (1:length(M(:,1)));
time2 = length(time);
Fs = time2/((M(end,1)-M(1,1))/1000); % Sampling
frequency
T = 1/Fs; % Sampling period
L = time2; % Length of signal
t = (0:L-1)*T; % Time vector


figure(1)
hold on


for i= 2:3
 plot(1000*t(1:time2),M(:,i))
end

title('.7Hz Filter and Raw')
xlabel('t (milliseconds)')
ylabel('X(t)')
legend('Raw','Filt')
Y = fft(M);

for i = 2:3
 P2 = abs(Y(:,i)/L);
 P1 = P2(1:L/2+1);
 P1(2:end-1) = 2*P1(2:end-1);
 figure(2)
 f = Fs*(0:(L/2))/L;
 plot(f,P1)
 hold on
end

title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
legend('Raw','Filt')