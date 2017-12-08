CommandeEE2
%%%%%%%%%%%%%%%%%
%% simu modèles: 
%%%%%%%%%%%%%%%%%

%%EE0
% step
h=figure(1);
u=tf(1);
stepplot(EE0.ee(1));
%setoptions(s,'SettleTimeThreshold',0.05);
%h4 = findall(h,'Label','Settling Time')
%set(h4,'Checked','on')
%set(h4,'Separator','on')
%h4
%A=get(h4,'Callback')
%   feval(A{1},h4,[],A{2:5});
%%
 %o=get(s,'CharacteristicManager')
% o(1).Visible =1
% o(2).Visible =1
% o(3).Visible =1
% o(4).Visible =1
% set(s,'CharacteristicManager',o)
%step
%title('Réponse temporelle à un échelon de EE0')
%legend('u(t)=1','EE0(t)','Location','southeast')
% %% rampe
% u = tf(1,[1 0]);
% figure(2)
% step(u,u*EE0.ee(1))
% title('Réponse temporelle à une rampe de EE0')
% legend('u(t)=t','EE0(t)','Location','southeast')
% %% bode
% figure(3)
% %subplot(1,2,1)
% bode(EE0.ee)
% title('Bode de EE0')
% legend('EE0')
% %subplot(1,2,2)
% %bodemag(EE2.ee)
% %%
% figure(4)
% %subplot(1,2,1)
% step(EE1.ee-EE2.ee)
% %legend('\epsilon = EE1-EE2','Interpreter','latex','FontSize',12);
% 
% 
