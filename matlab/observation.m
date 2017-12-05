%% Creation de notre observateur
% reconstruction de tous les états :

% Nécessite l'éxéution de espaceEtat1.m

obsv.H = EE2.ee.b;
obsv.M = eye(size(EE2.ee.a));
obsv.vp_obeservateur = (EE2.vp*3);

obsv.G = place(EE2.ee.a,EE2.ee.c,vp_obeservateur);

obsv.F = EE2.ee.a - G*EE2.ee.c;

obsv.ee = ss(obsv.F, [obsv.G obsv.H], obsv.M, 0);