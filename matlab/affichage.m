close all
figure(1)
%subplot(1,2,1)
bode(EE1.ee,EE2.ee)
legend('EE1','EE2')
%subplot(1,2,2)
%bodemag(EE2.ee)
%%
figure(2)
%subplot(1,2,1)
step(EE1.ee,EE2.ee)
legend('EE1','EE2')


