classdef Modele_non_lineaire
    %input ports
    %Vm % In_1 - 1D real
    %output ports
    %Vs % Out_1 - 1D real
    %Vg % Out_2 - 1D real

    properties
        Delta1
        Delta2
        dx
        xC
        R       
        L       
        J1      
        TauM1   
        Ke      
        Kc      
        Ks      
        Kr      
        Cn      
        rCn     
        Kg      
        Rchn    
        rRch    
        Znmrt
        TauM2 
        mu
        J2
    end
    methods 
        function obj = Modele_non_lineaire()
            obj.Delta1 = 2*rand(1)-1;
            obj.Delta2 = 2*rand(1)-1;
            obj.R       = 6.2;                  % Resistance induit
            obj.L       = 0.8e-3;               % Inductance induit
            obj.J1      = 0.039e-4;             % Inertie rotor
            obj.TauM1   = 19.6e-3;              % Constante de temps mecanique rotor seul
            obj.Ke      = 3.6/1000*60/(2*pi);   % Constante de fem
            obj.Kc      = 3.5/100;              % Constante de couple
            obj.Ks      = 10;                   % Constante du potentiometre
            obj.Kr      = 1/9;                  % Facteur du reducteur
            obj.Cn      = 3e-4;                 % Couple nominal de frottement sec si rotation
            obj.rCn     = obj.Cn/2;                 % Rayon de l'incertitude du frottement sec
            obj.Kg      = 0.105;                % Constante de la generatrice tachymetrique
            obj.Rchn    = 100;                  % Résistance nominale de la charge de la génératrice tachymétrique
            obj.rRch    = 0.5;                  % Rayon de l'incertitude de la résistance de charge
            obj.Znmrt   = 0.01;
            obj.TauM2   = 500e-3;               % Constante de temps mecanique rotor+reducteur+charge
            obj.mu      = obj.J1/obj.TauM1;             % Coefficient de frottement visqueux
            obj.J2      = obj.TauM2*obj.mu;             % Intertie rotor+reducteur+charge
            
            obj.dx = zeros(4,1);
            obj.xC = zeros(4,1);
        end
        
        function [Vs , Vg] = ModeleDemonstrateurMoteur(obj,Vm)
            % Parameters 
            
            % Continuous Derivatives
            obj.dx(1) = -obj.R/obj.L*obj.xC(1) - obj.Ke/obj.L*obj.xC(3) + 1/obj.L*Vm;
            obj.dx(2) = -(obj.R+(obj.Rchn+obj.rRch*obj.Delta2))/obj.L*obj.xC(2) - obj.Ke/obj.L*obj.xC(3);

            if(abs(obj.xC(3))>obj.Znmrt)
                obj.dx(3) = obj.Kc/obj.J*obj.xC(1) + obj.Kc/obj.J*obj.xC(2) - obj.mu/obj.J*obj.xC(3) - sign(obj.xC(3))/obj.J*obj.Cn*(1+obj.rCn*obj.Delta1);
            else
                if(abs(obj.Kc*obj.xC(1) + obj.Kc*obj.xC(2) - obj.mu*obj.xC(3)) >= obj.Cn*(1+obj.rCn*obj.Delta1))
                    obj.dx(3) = obj.Kc/J*obj.xC(1) + obj.Kc/obj.J*obj.xC(2) - obj.mu/obj.J*obj.xC(3) - sign(obj.Kc*obj.xC(1) + obj.Kc*obj.xC(2) - obj.mu*obj.xC(3))/obj.J*obj.Cn*(1+obj.rCn*obj.Delta1);
                else
                    obj.xC(3)=0;
                    obj.dx(3)=0;
                end
            end
            obj.dx(4) = obj.xC(3);


            % Outputs
            Vs = obj.Kr*obj.Ks*obj.xC(4)-10*floor((obj.Kr*obj.Ks*obj.xC(4)+5)/10);
            Vg = obj.Kg*obj.xC(3);
        end
            
    end
    
end