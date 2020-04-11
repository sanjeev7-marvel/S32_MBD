%The filter coefficients were calculated by the following
%Matlab function
%For convenience the IIR2 parameters are pre-computed 

%enable the next code if you own a MATLAB Signal Processing Toolbox License
% freq_bot = 400;
% freq_top = 625;
% T_sampling = 100e-6;
% [b,a]= butter(1,[freq_bot freq_top]*T_sampling *2, 'bandpass');
a = [ 1.0000   -1.7762    0.8678 ];
b = [ 0.0661         0   -0.0661 ];

%IIR2 F16
f16B0 = 32767*b(1)/8;
f16B1 = 32767*b(2)/8;
f16B2 = 32767*b(3)/8;
f16A1 = 32767*a(2)/8;
f16A2 = 32767*a(3)/8;

%IIR2 F32
f32B0 = (2^31-1)*b(1)/8;
f32B1 = (2^31-1)*b(2)/8;
f32B2 = (2^31-1)*b(3)/8;
f32A1 = (2^31-1)*a(2)/8;
f32A2 = (2^31-1)*a(3)/8;

%IIR2 FLT
fltB0 = b(1);
fltB1 = b(2);
fltB2 = b(3);
fltA1 = a(2);
fltA2 = a(3);
