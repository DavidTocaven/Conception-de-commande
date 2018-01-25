clear 
close all
%% Lecture data
load('CAN_data.mat');
% Transformation stockage
n.can=data(:,1);
n.cna=data(:,2);
clear data
% conversion en volt
n.canV = 10/2047*(n.can-2048)-5;
%           v_cna0  =   (unsigned int)(2047.0/5.0*((s0 + 5.0)/2.0) + 2048.0);
% <=>       s0      =   10/2047*(v_cna0 - 2048) - 5
n.cnaV = n.cna * (10/1023) - 5.0;
%          mes0 = V_can0 * (10.0/1023.0) - 5.0;

plot(-5:5,-5:5,n.canV,n.cnaV)
legend('CAN idéal','CAN du C167','Location','SouthEast')
axis([-5.5 5.5 -5.5 5.5])
xlabel('Tension envoyée (Volt)');
ylabel('Tension lue (Volt)');
