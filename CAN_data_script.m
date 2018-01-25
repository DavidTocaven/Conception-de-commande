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

pl=plot(-5:5,-5:5,... %ref
    n.canV,n.cnaV,... %mesurée
    n.canV(14),n.cnaV(14),'b+',...%erreur bas
    n.canV(941),n.cnaV(941),'g+');
pl(3).LineWidth = 1;
pl(4).LineWidth = 1;
legend('Conversions idéales','Conversions du C167','E1','E2','Location','SouthEast')
axis([-5.5 5.5 -5.5 5.5])
xlabel(sprintf('Tension équivalente envoyée (Volt)'));
ylabel('Tension équivalente lue (Volt)');
title('Test du CAN et du CNA')
grid on
