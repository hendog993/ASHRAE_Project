clear all, close all, clc
%%Data Enter File

% Temp=[8.4 56.4 30.1 0.6 18.0 18.2 30.1 17.8 17.9]
% Press=[200 


%%
prompt={'Enter a value for T (degrees C)','Enter a value for P High (kPA)','Enter a value for P low','Select a Refrigerant'};
title='Props';
definput={'10 20 30 40 50 60 70 80 90','950','200','R134a'};
opts.Interpreter= 'tex';
inputprops=inputdlg(prompt,title,[1 50],definput,opts);
Temperature=inputprops{1,1};
PressureHigh=inputprops{2,1};
PressureLow=inputprops{3,1};
Refrigerant=inputprops{4,1};
Temp=str2num(Temperature)+273.15;
PressH=str2num(PressureHigh).*1000;
Pres=str2num(PressureLow).*1000;
Press=[Pres PressH PressH Pres Pres Pres Pres Pres Pres];


%%
N=length(Temp);
Temperature=zeros(1,N);
Pressure=zeros(1,N);
Quality=zeros(1,N);
SaturationTemperature=zeros(1,N);
Enthalpy=zeros(1,N);
IsentropicEnthalpy=zeros(1,N);
Entropy=zeros(1,N);
Density=zeros(1,N);
Cp=zeros(1,N);
Cv=zeros(1,N);
DynamicViscosity=zeros(1,N);
KinematicViscosity=zeros(1,N);


for i=1:N;

T=Temp(i);
Temperature(i)=T;
P=Press(i);
Pressure(i)=P;



%%
h=CoolProp.PropsSI('H','P',PressH,'T',T,Refrigerant);
hf=CoolProp.PropsSI('H','P',P,'Q',0,Refrigerant);
hg=CoolProp.PropsSI('H','P',P,'Q',1,Refrigerant);
Qual=(h-hf)./(hg-hf);

% Qual=CoolProp.PropsSI('Q','P',P,'T',T,Refrigerant);
if (Qual >= 1) | (Qual <0)
    Qual=1;
else 
    Qual=Qual;
end
Quality(i)=Qual;
%% 
SaturationTemp=CoolProp.PropsSI('T','P',P,'Q',0,Refrigerant);
SaturationTemperature(i)=SaturationTemp;
Enth=CoolProp.PropsSI('H','T',T,'Q',Qual,Refrigerant);
Enthalpy(i)=Enth;
IsentropicEnth=CoolProp.PropsSI('H','T',T,'Q',1,Refrigerant);
IsentropicEnthalpy(i)=IsentropicEnth;
Entr=CoolProp.PropsSI('S','P',P,'T',T,Refrigerant);
Entropy(i)=Entr;
Den=CoolProp.PropsSI('D','P',P,'T',T,Refrigerant);
Density(i)=Den;
Cpress=CoolProp.PropsSI('C','P',P,'T',T,Refrigerant);
Cp(i)=Cpress;
Cvol=CoolProp.PropsSI('O','P',P,'T',T,Refrigerant);
Cv(i)=Cvol;
DynamicV=CoolProp.PropsSI('V','P',P,'T',T,Refrigerant);
DynamicViscosity(i)=DynamicV;
KinematicV=DynamicV./Den;
KinematicViscosity(i)=KinematicV;

i=i+1;
end
Temperature
Pressure
Quality
SaturationTemperature
Enthalpy
IsentropicEnthalpy
Entropy
Density
Cp
Cv
DynamicViscosity
KinematicViscosity
