%% convertion CAN
% input
can.in.type ='Tension';
can.in.unite = 'Volt';
can.resol =2^10;
can.in.val_pos= linspace(0,5,can.resol);
can.in.val_util = linspace(0,5,can.resol);
% output
can.out.type ='Bits';
can.out.unite = 'entier';
can.out.val_pos = int16((can.resol/5)*can.in.val_pos);
can.out.val_util = int16((can.resol/5)*can.in.val_util);

%%affichage
figure(1)
    plot(0,0,'^b',5,can.resol-1,'vb',can.in.val_pos,can.out.val_pos,'-b',0,0,'>r',5,can.resol-1,'<r',can.in.val_util,can.out.val_util,'-.r');
    %p(2).LineWidth = 2;
    %p(1).LineWidth = 2,
        title('Convertion Analogique Numérique')
        xlabel(sprintf('%s (%s)',can.in.type,can.in.unite));
        ylabel(sprintf('%s (%s)',can.out.type,can.out.unite));
        legend('min pos','max pos','Valeurs possibles','min ut','max ut','Valeurs utiles','Location','SouthEast');
        axis([-.5 5.5 -10 1050])
        grid on

%% A Finir        
%% convertion CNA
% input
cna.in.type ='Bits';
cna.in.unite = 'entiers';
cna.resol =2^12;
cna.in.val_pos= 0:cna.resol-1;
cna.in.val_util = 2^11:2^12-1;
% output
cna.out.type ='Tension';
cna.out.unite = 'Volt';
cna.out.val_pos = 10/(cna.resol-1)*cna.in.val_pos-5;%a mod
cna.out.val_util =10/(cna.resol-1)*cna.in.val_util-5;

%affichage
figure(2)
%plot(-5,0,'vb',...
%      5,cna.resol-1,'^b',...
%      cna.out.val_pos,'-b',...
%      0,0,'>r',...
%      5,cna.resol-1,'<r',...
%      cna.out.val_util,'-.r');        

plot(0,-5,'^b',...
     cna.resol-1,5,'vb',...
     cna.in.val_pos,cna.out.val_pos,'-b',...
     2048,0,'>r',...
     cna.resol-1,5,'<r',...
     cna.in.val_util,cna.out.val_util,'--r');        
title('Convertion Numérique Analogique')
        xlabel(sprintf('%s (%s)',cna.in.type,cna.in.unite));
        ylabel(sprintf('%s (%s)',cna.out.type,cna.out.unite));
         legend('min pos','max pos','Valeurs possibles','min ut','max ut','Valeurs utiles','Location','SouthEast');
        axis([-10 4100 -5.5 5.5])
        grid on
        
%% CAN err        
%% abs et ord de ref
x       = 0:.1:5;
y       = 2047/5*x;
yGain   = 1.1*y;
yInt    = -31.46*x.^2 + 566.69*x;
yOffs   = y - 100;

figure(3)
p=plot(0,0,'>b',5,2047,'<b',x,y,'b',x,yGain,'r',x,yOffs,'--g',x,yInt,'-*k')
    p(1).LineWidth=1.5;
    p(2).LineWidth=1.5;
    p(3).LineWidth=2;
    title('CAN : différentes erreurs de conversions')
    legend('min','max','théorique','Erreur gain','Erreur d''offset','non-linéarité intégrale','Location','SouthEast');
    axis([0 5 0 2050])        
    xlabel('Tension (Volt)');
    ylabel('Valeurs (entier)');
    grid on