% Indexing the data from the functions. 
% scVarName means "Scroll compressor varname coefficient
% rcVarName means recip compressor coefficient name 

[scCapacity, scWatts,scCurrent,scMassFlow] = scroll_comp_coeff();
[rcCapacity, rcWatts, rcAmps, rcMassFlow] = recip_comp_coeff();

% Scroll conditions
sMinEvap = 5;
sMaxEvap = 60;
sMinCond = 70; 
sMaxCond = 165;

% Recip conditions
rMinEvap = -10;
rMaxEvap =  55;
rMinCond = 70;
rMaxCond = 140;

% ts is sat evap temp 
% td 