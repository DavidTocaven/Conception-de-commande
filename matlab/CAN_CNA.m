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
    plot(can.in.val_pos,can.out.val_pos,'-b',can.in.val_util,can.out.val_util,'-.r');
        title('Convertion Analogique numérique')
        xlabel(sprintf('%s (%s)',can.in.type,can.in.unite));
        ylabel(sprintf('%s (%s)',can.out.type,can.out.unite));
        legend('Valeurs possibles','Valeurs utiles','Location','SouthEast');
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

%%affichage
figure(2)
    plot(cna.in.val_pos,cna.out.val_pos,'-b',cna.in.val_util,cna.out.val_util,'-.r');
        title('Convertion numérique analogique')
        xlabel(sprintf('%s (%s)',cna.in.type,cna.in.unite));
        ylabel(sprintf('%s (%s)',cna.out.type,cna.out.unite));
        legend('Valeurs possibles','Valeurs utiles','Location','SouthEast');
        %axis([-10 4100 -.5 5.5])
        grid on
        
        
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
    plot(can.in.val_pos,can.out.val_pos,'-b',can.in.val_util,can.out.val_util,'-.r');
        title('Convertion Analogique numérique')
        xlabel(sprintf('%s (%s)',can.in.type,can.in.unite));
        ylabel(sprintf('%s (%s)',can.out.type,can.out.unite));
        legend('Valeurs possibles','Valeurs utiles','Location','SouthEast');
        axis([-.5 5.5 -10 1050])
        grid on

        
        
        
        
        
        
        
        