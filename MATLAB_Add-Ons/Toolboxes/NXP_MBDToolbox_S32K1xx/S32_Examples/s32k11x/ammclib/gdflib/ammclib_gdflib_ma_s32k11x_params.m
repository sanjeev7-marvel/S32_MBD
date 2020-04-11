%The MA filter coefficients were calculated for N number of samples
N = 16;

%Smoothing factor for MA F16/F32 is u16NSamples variable. This variable 
%represents the binary logarithm of the number of averaged samples N of
%the corresponding uniform sliding-window moving average filter
u16NSamples = sqrt(N);

%smoothing factor fro MA FLT is set according to the following formula 
%lambda = 1/N that will yield results equivalent to the fixed-point 
%variants

fltLambda = 1/N;
