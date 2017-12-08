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

%% Changement de base de EE1
P = [0     0     1;
     1     0     0;
     0     1     0];
EE1_c.a = inv(P)*EE1.ee.a*P;
EE1_c.b = inv(P)*EE1.ee.b;
EE1_c.c = EE1.ee.c*P;

EE1_c.ee = ss(EE1_c.a,EE1_c.b,EE1_c.c,EE1.ee.d);


%% Calcul du système en boucle fermé basé observateur de EE1
%       cf Cours de GOUAISBAULT
A1 = EE1_c.ee.a(1:2,1:2);
A2 = EE1_c.ee.a(1:2, 3);
A3 = EE1_c.ee.a(3, 1:2);
A4 = EE1_c.ee.a(3,3);

B1 = EE1_c.ee.b(1:2);
B2 = EE1_c.ee.b(3);

EE1_bf.a = [A1-(B1*K),  A2 ,    -B1*K    ;
            A3-(B2*K),  A4 ,    -B2*K    ;
        zeros(size(obsver.F))   , -A2 ,   obsver.F  ];
EE1_bf.b = [B1;B2; [0;0] ];

EE1_bf.c = [EE1_c.ee.c [0 0 ;0 0]];

EE1_bf.ee = ss(EE1_bf.a, EE1_bf.b, EE1_bf.c, [0;0]);

EE1_bf.vp = eig(EE1_bf.a);



