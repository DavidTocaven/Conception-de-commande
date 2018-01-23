CommandeEE2
%%%%%%%%%%%%%%%%%
%% simu modèles: 
%%%%%%%%%%%%%%%%%

%%EE0
% step
figure(1);
u=tf(1);
step(u,EE0.ee(1));
title('Réponse temporelle à un échelon de EE0')
legend('u(t)=1','Vs (t)','Location','southeast');
%% rampe
u = tf(1,[1 0]);
figure(2)
step(u,u*EE0.ee(1))
title('Réponse temporelle à une rampe de EE0')
legend('u(t)=t','Vs(t)','Location','southeast')
%% bode
figure(3)
bode(EE0.ee(1))
title('Bode de EE0')
legend('EE0')
%%
%%EE1
% step
figure(5);
u=tf(1);
step(u,EE1.ee(1),EE0.ee(1));
title('Réponse temporelle à un échelon de EE1')
legend('u(t)=1','EE1:Vs(t)','EE0:Vs(t)','Location','southeast')
%% rampe
u = tf(1,[1 0]);
figure(6)
step(u,u*EE1.ee(1),u*EE0.ee(1))
title('Réponse temporelle à une rampe de EE1')
legend('u(t)=t','EE1:Vs(t)','EE0:Vs(t)','Location','southeast')
%% bode
figure(7)
bode(EE1.ee(1),EE0.ee(1))
title('Bode de EE1')
legend('EE1','EE0')



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% A FINIR !!!!!!!!!!!!!!!!!!!!!!!!
%%EE2
% step
figure(8);
u=tf(1);
step(u,EE.ee(1),EE0.ee(1));
title('Réponse temporelle à un échelon de EE1')
legend('u(t)=1','EE1:Vs(t)','EE0:Vs(t)','Location','southeast')
%% rampe
u = tf(1,[1 0]);
figure(6)
step(u,u*EE1.ee(1),u*EE0.ee(1))
title('Réponse temporelle à une rampe de EE1')
legend('u(t)=t','EE1:Vs(t)','EE0:Vs(t)','Location','southeast')
%% bode
figure(7)
bode(EE1.ee(1),EE0.ee(1))
title('Bode de EE1')
legend('EE1','EE0')

%legend('\epsilon = EE1-EE2','Interpreter','latex','FontSize',12);

%% Avec Commande_TD_EE2.slx, variable "simu"
model = 'EE0';
figure (8)
    plot(simu.time,simu.signals.values(:,1),simu.time,simu.signals.values(:,2))
    legend('ref(t)',sprintf('%s:Vg(t)',model),'Location','SouthEast');
    title(sprintf('Asservissement de %s par une commande à temps discret',model));
    xlabel('temps (s)');
    ylabel('Tension (Volt)');
%%
%%
simuEE0=simu;
simuEE1=simu;
simuEE2=simu;
figure (9)
    plot(simuEE0.time,simuEE0.signals.values(:,1),'k',...%ref
         simuEE0.time,simuEE0.signals.values(:,2),'-.b',...%EE0
         simuEE1.time,simuEE1.signals.values(:,2),'--r',...%EE1
         simuEE2.time,simuEE2.signals.values(:,2),'g')%EE2
     
    legend('ref(t)','EE0:Vg(t)','EE1:Vg(t)','EE2:Vg(t)','Location','SouthEast');
    title(sprintf('Asservissement des modeles d''ordre 4, 3 et 2 \n par une commande à temps discret\n(Te=%f)',Te));
    xlabel('temps (s)');
    ylabel('Tension (Volt)');
