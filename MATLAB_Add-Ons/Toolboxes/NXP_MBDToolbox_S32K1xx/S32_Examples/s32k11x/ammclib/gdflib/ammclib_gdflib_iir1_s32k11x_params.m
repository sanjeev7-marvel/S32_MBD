%The filter coefficients were calculated by the following
%Matlab function
%For convenience the IIR1 parameters are pre-computed 

%enable the next code if you own a MATLAB Signal Processing Toolbox License
%freq_cut = 100;                 
%T_sampling = 100e-6;
%[b,a]=butter(1,[freq_cut*T_sampling*2],'low');
a = [ 1.0000   -0.9391 ];
b = [ 0.0305    0.0305 ];

%IIR1 F16
f16B0 = 32767*b(1)/8;
f16B1 = 32767*b(2)/8;
f16A1 = 32767*a(2)/8;

%IIR1 F32
f32B0 = (2^31-1)*b(1)/8;
f32B1 = (2^31-1)*b(2)/8;
f32A1 = (2^31-1)*a(2)/8;

%IIR1 FLT
fltB0 = b(1);
fltB1 = b(2);
fltA1 = a(2);
