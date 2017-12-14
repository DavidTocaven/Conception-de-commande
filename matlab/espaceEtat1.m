clear 
close all
MoteurScript
%% Modèle Niveau 0 - Ordre 4 - EE
%%% Modele espace d'état LINEAIRE
% etat    = [ i1 ; i2 ; theta ; omega ]
% entrée  = [ Vm ]
% sorties = [ Vg ; Vs]

% Matrices EE

EE0.a   =[-R/L,     0,             0,   -Ke/L;
          0,        -(R+Rchn)/L,   0,   -Ke/L;
          0,        0,             0,   1;
          Kc/J2,    Kc/J2,         0,   -mu/J2];
      
EE0.b   =[1/L;
          0;
          0;
          0];
      
EE0.c   =[0, 0, 0,      Kg;
          0, 0, Kr*Ks,  0 ];
      
EE0.d   =[0;
          0];
% EE
EE0.ee= ss(EE0.a,EE0.b,EE0.c,EE0.d);
% Valeurs propres
EE0.vp = eig(EE0.ee);

% gain statique
EE0.gain = dcgain(EE0.ee(1));
%% Modèle Niveau 1 - Ordre 3 - EE
%%% Modele espace d'état LINEAIRE
% etat    = [ i1 ; omega ; theta ]
% entrée  = [ Vm ]
% sorties = [ Vg ; Vs]

% Matrices EE
EE1.a = EE0.a([1,3,4],[1,3,4]);
EE1.b = EE0.b([1, 3, 4]);
EE1.c = EE0.c(:,[1, 3, 4]);
EE1.d = EE0.d;

% Espace Etat
EE1.ee= ss(EE1.a,EE1.b,EE1.c,EE1.d);
% Valeurs propres
EE1.vp = eig(EE1.ee);

% gain statique
EE1.gain = dcgain(EE1.ee(1));
%% Modèle Niveau 2 - Ordre 2 - EE
%%% Modele espace d'état LINEAIRE
% etat    = [ theta ; omega ]
% entrée  = [ Vm ]
% sorties = [ Vg ; Vs]

% Matrices EE
% EE2.a = [ -(Ks*Ke)/(J2*R) , 0 ;
%           1               , 0 ]; % ca marche pas...
EE2.a = [  0  ,   1 ;
           0  ,   -(Kc*Ke)/(R*J2)-(mu/J2)];
EE2.b = [ 0         ;
          Kc/(J2*R) ];
      
EE2.c = EE1.c(:,[2, 3]);
%EE2.c =[];
EE2.d = EE1.d;

% EE
EE2.ee= ss(EE2.a,EE2.b,EE2.c,EE2.d);
% Valeurs propres

EE2.vp = eig(EE2.ee);

% gain statique
EE2.gain = dcgain(EE2.ee(1));

% Commandabilitée
Controlabilite = ctrb(EE0.a,EE0.b);
disp('Controlable ?')
disp(rank(Controlabilite) == size(EE0.a,1))

% Observabilité
[ABAR,BBAR,CBAR,T,K] = obsvf(EE0.a,EE0.b,EE0.c)
disp('Observable ?')
disp(rank(Observabilite) == size(EE0.a,1))
