clear 
close all
%% Mod�le de connaissance LINEAIRE
% Donn�es
R       = 6.2           ;   % R�sistance induit
L       = 0.8e-3        ;   % Inductance induit
J1      = 0.039e-4      ;   % Internie rotor
TauM1   = 19.6e-3       ;   % Constante de temps m�canique rotor seul
Ke      = 3.6/1000*60   ;   % Constante de fem
Kc      = 3.5/100       ;   % Constante de couple
Ks      = 10            ;   % Constante de potentiometre 
Kr      = 1/9           ;   % Facteur du r�ducteur
Cn      = 3e-4          ;   % Couple nominal de frottement sec si rotation
rCn     = Cn/2          ;   % 