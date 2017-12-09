%% Creation de notre observateur
% reconstruction de tous les états :
espaceEtat1

%% Cahier des charges
vp_desire = [-4; -5];
%% observateur
obsver.H = EE2.ee.b;
obsver.M = eye(size(EE2.ee.a));
obsver.vp = vp_desire*3; %*3
obsver.G = place(EE2.ee.a', EE2.ee.c(2,:)', obsver.vp)'; % Ne pas utiliser acker

obsver.F = EE2.ee.a - obsver.G*EE2.ee.c(2,:);
           %   a        b               c       D
obsver.ee = ss(obsver.F, [obsver.G obsver.H], obsver.M, 0);

%% commande

K = place(EE2.ee.a, EE2.ee.b, vp_desire);

%%  Analyse du retour d'état basé observateur 
% Pour EE1 :
%Changement de base de EE1
P = [0     0     1;
     1     0     0;
     0     1     0];
EE1_c.a = inv(P)*EE1.ee.a*P;
EE1_c.b = inv(P)*EE1.ee.b;
EE1_c.c = EE1.ee.c*P;

EE1_c.ee = ss(EE1_c.a,EE1_c.b,EE1_c.c,EE1.ee.d);

% Partitionnement de l'EE
EE1.A1 = EE1_c.ee.a(1:2,1:2);
EE1.A2 = EE1_c.ee.a(1:2,3);
EE1.A3 = EE1_c.ee.a(3,1:2);
EE1.A4 = EE1_c.ee.a(3,3);

EE1.B1 = EE1_c.ee.b(1:2);
EE1.B2 = EE1_c.ee.b(3);

EE1.C = [EE1_c.ee.c];


% Construction des matrices
EE1_obsver.A = [EE1.A1      EE1.A2     [0 0;0 0]   ;
                EE1.A3      EE1.A4      [0 0 ] ;
                [0 0;0 0]   -EE1.A2       obsver.F];
EE1_obsver.B = [EE1.B1; EE1.B2; [0;0]];
EE1_obsver.C = [EE1.C [0 0;0 0]; 
                    [0 0 0 0 1]];   % Pour afffiche de l'erreur 
                                % de reconstrcution de la vitesse

% Espace d'état
EE1_obsver.ee = ss(EE1_obsver.A ,EE1_obsver.B, EE1_obsver.C, [0;0;0]);

% Analyse du trasfert de epsilon
% EE1_obsver.vp = eig(EE1_obsver.ee);
% bodemag(EE1.ee(1), EE1_obsver.ee(1))

%% 


%% Calcul du système en boucle fermé basé observateur de EE1
%       cf Cours de GOUAISBAULT
% Etat EE0 : x = [ i1    ; i2    ; theta ; omega ]
% Etat EE1 : x = [ i1    ; theta ; omega ]
% Etat EE2 : x = [ theta ; omega ]


step(EE1_c.ee)


