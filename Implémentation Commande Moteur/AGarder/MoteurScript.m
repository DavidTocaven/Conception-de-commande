clear all
close all

%%% Modele de connaissance LINEAIRE
% Donnees
R = 6.2; % Resistance induit
L = 0.8e-3; % Inductance induit
J1 = 0.039e-4; % Inertie rotor
TauM1 = 19.6e-3; % Constante de temps mecanique rotor seul
Ke = 3.6/1000*60/(2*pi); % Constante de fem
Kc = 3.5/100; % Constante de couple
Ks = 10; % Constante du potentiometre
Kr = 1/9; % Facteur du reducteur
Cn = 3e-4; % Couple nominal de frottement sec si rotation
rCn = Cn/2; % Rayon de l'incertitude du frottement sec
Kg = 0.105; % Constante de la generatrice tachymetrique
Rchn = 100; % Résistance nominale de la charge de la génératrice tachymétrique
rRch = 0.5; % Rayon de l'incertitude de la résistance de charge

% Mesure
TauM2 = 500e-3; % Constante de temps mecanique rotor+reducteur+charge

% Calculs
mu = J1/TauM1; % Coefficient de frottement visqueux
J2 = TauM2*mu; % Intertie rotor+reducteur+charge

%% MODELE TF
% Fonction de transfert Tension / Vitesse moteur
TFmoteurConnaissanceVmOmega = tf(Kc,[L*J2 mu*L+R*J2 Ke*Kc+mu*R]);
% Fonction de transfert Tension / Vg
TFmoteurConnaissanceVmVg = tf(Kc*Kg,[L*J2 mu*L+R*J2 Ke*Kc+mu*R]);
% Fonction de transfert Tension / Vs
TFmoteurConnaissanceVmVs = tf(Kc*Kr*Ks,[L*J2 mu*L+R*J2 Ke*Kc+mu*R 0]);
%%

%%% Modele de comportement LINEAIRE
% Mesures
tau = 250e-3; % Constante de temps
gain = 14.5; % Gain statique

% Fonction de transfert Tension / Vitesse moteur
TFmoteurComportementVmOmega = tf(gain,[tau 1]);
% Fonction de transfert Tension / Vg
TFmoteurComportementVmVg = tf(gain*Kg,[tau 1]);
% Fonction de transfert Tension / Vs
TFmoteurComportementVmVs = tf(gain*Ks*Kr,[tau 1 0]);

%%% Comparaison modele de connaissance / modele de comportement
figure(1);hold on
step(TFmoteurConnaissanceVmOmega);step(TFmoteurComportementVmOmega);

figure(2);hold on
Om = logspace(-1,9,1000);
bode(TFmoteurConnaissanceVmOmega,Om);bode(TFmoteurComportementVmOmega,Om);

%% MODELE EE1
%%% Modele espace d'état LINEAIRE
A=[-R/L -Ke/L 0;Kc/J2 -mu/J2 0;0 1 0];
B=[1/L;0;0];
C=[0 Kg 0;0 0 Kr*Ks];
D=[0;0];
ModeleEE1 = ss(A,B,C,D);
%%

%% MODELE EE2
%%% Modele espace d'état LINEAIRE
A=[-R/L 0 -Ke/L 0;0 -(R+Rchn)/L -Ke/L 0;Kc/J2 Kc/J2 -mu/J2 0;0 0 1 0];
B=[1/L;0;0;0];
C=[0 0 Kg 0;0 0 0 Kr*Ks];
D=[0;0];
ModeleEE2 = ss(A,B,C,D);
%%

%%% Comparaison des modeles EE1 et EE2

figure(3);hold on
step(ModeleEE1(1));step(ModeleEE2(1));

figure(4);hold on
Om = logspace(-1,9,1000);
bode(ModeleEE1(1),Om);bode(ModeleEE2(1),Om);

figure(5);hold on
Om = logspace(-3,9,1000);
nyquist(ModeleEE1(1),Om);nyquist(ModeleEE2(1),Om);