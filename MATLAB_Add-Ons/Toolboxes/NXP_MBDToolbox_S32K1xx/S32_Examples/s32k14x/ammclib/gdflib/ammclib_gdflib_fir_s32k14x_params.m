%The filter coefficients were calculated by the following
%Matlab function (coefficients are contained in Hd.Numerator)
%For convenience the FIR parameters are pre-computed 

N = 15;             % Filter order (time delay will be (N-1)/2)
F6dB = 0.5;         % Cutoff frequency

%enable the next code if you own a MATLAB Signal Processing Toolbox License
%h = fdesign.lowpass('n,fc', N, F6dB);
%Hd = design(h, 'window')

u16Order = N;
u32Order = N;

%pf16CoefBuf = 32767*Hd.Numerator;
pf16CoefBuf = 32767*[-0.0024 -0.0042 0.0095 0.0200 -0.0380 -0.0696 0.1374 0.4472 0.4472 0.1374 -0.0696 -0.0380 0.0200 0.0095 -0.0042 -0.0024];

%pf32CoefBuf = (2^31-1)*Hd.Numerator;
pf32CoefBuf = (2^31-1)*[-0.0024 -0.0042 0.0095 0.0200 -0.0380 -0.0696 0.1374 0.4472 0.4472 0.1374 -0.0696 -0.0380 0.0200 0.0095 -0.0042 -0.0024];

%pfltCoefBuf = Hd.Numerator;
pfltCoefBuf = [-0.0024 -0.0042 0.0095 0.0200 -0.0380 -0.0696 0.1374 0.4472 0.4472 0.1374 -0.0696 -0.0380 0.0200 0.0095 -0.0042 -0.0024];
