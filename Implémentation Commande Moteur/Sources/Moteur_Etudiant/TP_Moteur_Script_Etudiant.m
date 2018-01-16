% Script TP MOTEUR

clear all
close all

% Période d'échantillonnage
Te = 0.01;

% Modèle du moteur :
Ke = 3.6/1000*60/(2*pi);

Kc= 3.5/100;
Kg = 0.105;
R=6.2;
L=0.8e-3;
J1=0.039e-4;
TauM1=19.6e-3;

TauM2=500e-3;
mu=J1/TauM1;
J2=Taum2*mu;
TF=tf(Kc,[L*J2 mu*L+R*J2 Ke*Kc+mu*R]);



