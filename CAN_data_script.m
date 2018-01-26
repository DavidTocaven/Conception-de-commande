%% C167 #1
clear 
close all
%% Lecture data
load('dataCAN_CNA_1.mat')
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
figure(1)
plot(-5:5,-5:5,... %ref
    n.canV,n.cnaV);% mesurée

legend('Conversions idéales',...    
       'Conversions du C167',...
       'Location','SouthEast');
axis([-5.5 5.5 -5.5 5.5])
xlabel(sprintf('Tension équivalente envoyée (Volt)'));
ylabel('Tension équivalente lue (Volt)');
title(sprintf('C167 #1 \nTest du CAN et du CNA'))
grid on
clear n
%% C167 #2
%% Lecture data
load('CAN_data.mat')
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
figure(2)
pl=plot(-5:5,-5:5,... %ref
    n.canV,n.cnaV,... %mesurée
    n.canV(14),n.cnaV(14),'b+',...% erreur basse E1
    n.canV(941),n.cnaV(941),'g+');% erreur haute E2
pl(3).LineWidth = 1;    
pl(4).LineWidth = 1;
legend('Conversions idéales',...    
       'Conversions du C167',...
       sprintf('E1 (%f,%f)',n.canV(14),n.cnaV(14)),...
       sprintf('E2 (%f,%f)',n.canV(941),n.cnaV(941)),...
       'Location','SouthEast')
axis([-5.5 5.5 -5.5 5.5])
xlabel(sprintf('Tension équivalente envoyée (Volt)'));
ylabel('Tension équivalente lue (Volt)');
title(sprintf('C167 #2 \nTest du CAN et du CNA'))
grid on
