%% Creation de notre observateur
% reconstruction de tous les �tats :
espaceEtat1

%% Cahier des charges
vp_desire = [-4 ; - 5];
%% observateur
obsver.H = EE2.ee.b;
obsver.M = eye(size(EE2.ee.a));
obsver.vp =     vp_desire; %*3
obsver.G = place(EE2.ee.a', EE2.ee.c(2,:)', obsver.vp)'; % Ne pas utiliser acker
%%
obsver.F = EE2.ee.a - obsver.G*EE2.ee.c(2,:);
           %   a           b                  c       D
obsver.ee = ss(obsver.F, [obsver.G obsver.H], obsver.M, 0);

%% commande

K = place(EE2.ee.a, EE2.ee.b, vp_desire);
K = [0 K(2)];
EE2_bf.a = [EE2.ee.a-EE2.ee.b*K     -EE2.ee.b*K;
            [0 0; 0 0]              obsver.F];  

EE2_bf.b = [EE2.ee.b; 0;0];

EE2_bf.c = [EE2.ee.c [0 0;0 0]
               [0 0 1 0]];
EE2_bf.ee = ss(EE2_bf.a, EE2_bf.b, EE2_bf.c, [0;0;0]);

EE2_bf.gain = dcgain(EE2_bf.ee(1));
%   N = 1/EE2_bf.gain; %Modif En salle 
%%  Analyse du retour d'etat base observateur 
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
                    [0 0 0 1 0]];   % Pour afffiche de l'erreur 
                                % de reconstrcution de la

% Espace d'etat
EE1_obsver.ee = ss(EE1_obsver.A ,EE1_obsver.B, EE1_obsver.C, [0;0;0]);


% gain statique
EE1_obsver.gain = dcgain(EE1_obsver.ee(1));
% comparaison de gain statique

err_gain_stat=EE2.gain - EE1_obsver.gain;

% Analyse pour EE0
% Changement de base [theta, omega, i1, i2]
P_0 = [0 0 1 0; 0 0 0 1; 1 0 0 0; 0 1 0 0];

EE0_c.a = inv(P_0)*EE0.ee.a*P_0;
EE0_c.b = inv(P_0)*EE0.ee.b;
EE0_c.c = EE0.ee.c*P_0;

EE0_c.ee = ss(EE0_c.a,EE0_c.b,EE0_c.c, EE0.d);
% Partitionnement de l'EE
EE0.A1 = EE0_c.ee.a(1:2,1:2);
EE0.A2 = EE0_c.ee.a(1:2,3:4);
EE0.A3 = EE0_c.ee.a(3:4,1:2);
EE0.A4 = EE0_c.ee.a(3:4,3:4);

EE0.B1 = EE0_c.ee.b(1:2);
EE0.B2 = EE0_c.ee.b(3:4);

EE0.C = [EE0_c.ee.c];


% Construction des matrices
EE0_obsver.A = [EE0.A1      EE0.A2     [0 0;0 0]   ;
                EE0.A3      EE0.A4      [0 0;0 0 ] ;
                [0 0;0 0]   -EE0.A2       obsver.F];
EE0_obsver.B = [EE0.B1; EE0.B2; [0;0]];
EE0_obsver.C = [EE0.C [0 0;0 0]
                   zeros(2,4) eye(2,2)];   % Pour afffiche de l'erreur 
                                % de reconstrcution de la

EE0_obsver.ee = ss(EE0_obsver.A, EE0_obsver.B, EE0_obsver.C,[0;0;0;0]);

% Analyse du trasfert de epsilon
EE0_obsver.vp = eig(EE0_obsver.ee);
figure(1)


%% 


%% Calcul du systeme en boucle ferme base observateur de EE1
%       cf Cours de GOUAISBAULT
% Etat EE0 : x = [ i1    ; i2    ; theta ; omega ]
% Etat EE1 : x = [ i1    ; theta ; omega ]
% Etat EE2 : x = [ theta ; omega ]

% EE1

EE1_bf.a = [EE1.A1-EE1.B1*K      EE1.A2     -EE1.B1*K   ;
            EE1.A3-EE1.B2*K      EE1.A4     -EE1.B2*K;
                [0 0;0 0]       -EE1.A2       obsver.F];
EE1_bf.b = EE1_obsver.B;
EE1_bf.c = EE1_obsver.C;

EE1_bf.ee = ss(EE1_bf.a, EE1_bf.b, EE1_bf.c, EE1_obsver.ee.d);
EE1_bf.vp = eig(EE1_bf.ee);

% EE0 


EE0_bf.a = [EE0.A1-EE0.B1*K      EE0.A2     -EE0.B1*K   ;
            EE0.A3-EE0.B2*K      EE0.A4     -EE0.B2*K;
                [0 0;0 0]       -EE0.A2       obsver.F];
EE0_bf.b = EE0_obsver.B;
EE0_bf.c = EE0_obsver.C;

EE0_bf.ee = ss(EE0_bf.a, EE0_bf.b, EE0_bf.c, EE0_obsver.ee.d);
EE0_bf.vp = eig(EE0_bf.ee);
EE0_bf.gain = dcgain(EE0_bf.ee(1));

N = 1/(EE2_bf.gain);
%% Bloc de commande
Te = 0.052;
%% input : [Vref Vs];
CommTD.a = obsver.F-EE2.ee.b*K;
CommTD.b = [EE2.ee.b*N obsver.G];
CommTD.c = -K;
CommTD.d = [N 0];
CommTD.ee = ss(CommTD.a, CommTD.b, CommTD.c, CommTD.d);
CommTD.zz = c2d(CommTD.ee, Te, 'zoh');
CommTD.ft=tf(CommTD.zz);
ftRef=CommTD.ft(1);
ftVs=CommTD.ft(2);
%%
ftTD=CommTD.ft(1)+CommTD.ft(2);
%% test 

%% save in file
numY =CommTD.ft(1,1).num{1,1};
numU =CommTD.ft(1,2).num{1,1};
denumY = CommTD.ft(1,1).den{1,1};

File        = fopen('Parametres_Commande.txt','w+');

fprintf(File,'\t Param�tres de la commande en temps discret \n\n');
%ny 1 2 3
fprintf(File,'static float my0 =  %f;\n',numY(1));
fprintf(File,'static float my1 =  %f;\n',numY(2));
fprintf(File,'static float my2 =  %f;\n\n',numY(3));
%d 1 2
fprintf(File,'static float d1 =  %f;\n',denumY(2));
fprintf(File,'static float d2 =  %f;\n\n',denumY(3));
% nu 1 2 3
fprintf(File,'static float mref0 =  %f;\n',numU(1));
fprintf(File,'static float mref1 =  %f;\n',numU(2));
fprintf(File,'static float mref2 =  %f;\n\n',numU(3));

fclose(File);
