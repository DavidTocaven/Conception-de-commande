close all
%%%%%%%%%%%%%%%%%
%% simu modèles: 
%%%%%%%%%%%%%%%%%

%%EE0
% step
figure(1)
step(tf(1),EE0.ee(1))
title('Réponse temporelle à un échelon de EE0')
legend('u(t)=1','EE0(t)','Location','southeast')
%% rampe
t = tf(1,[1 0]);
figure(2)
step(t,t*EE0.ee(1))
title('Réponse temporelle à une rampe de EE0')
legend('u(t)=t','EE0(t)','Location','southeast')
%% bode
figure(1)
%subplot(1,2,1)
bode(EE0.ee)
title('Bode de EE0
legend('EE1','EE2')
%subplot(1,2,2)
%bodemag(EE2.ee)
%%
figure(2)
%subplot(1,2,1)
step(EE1.ee-EE2.ee)
aaa=legend('\epsilon = EE1-EE2','Interpreter','latex','FontSize',12)


