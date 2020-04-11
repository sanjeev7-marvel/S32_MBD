clear all
clc

% Motor parameters
% (to be set according to measurements)
Ld = 3.e-4;             % inductance in d-axis [H]
Lq = 3.e-4;             % inductance in q-axis [H]
Rs = 0.33;              % resistance of one stator phase [ohms]

% Scaling constants
% (to be set according to known maxima)
Imax = 20;             % maximum stator phase current [A]
Umax = 14.4;           % maximum stator phase voltage [V]
Wmax = 2618;           % maximum angular velocity [rad/s]
Emax = 14.4;           % maximum backEMF [V]

% Control system parameters
% (to be set according to the chosen control system dynamics)
Ts = 1e-4;              % sampling period [s]
i_Ksi = 1;              % current loop attenuation
i_fo = 350;             % current loop natural frequency [Hz]
i_wo = 2*pi*i_fo;       % current loop natural angular frequency [rad/s]
Kp = 2*i_Ksi*i_wo*Ld-Rs;
Ki = i_wo^2*Ld;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Virtual RL circuit parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
maxCoeffRL = max(abs([Ts/(2*Ld+Ts*Rs)*Umax/Imax,...
    Ts*Lq/(2*Ld+Ts*Rs)*Wmax,...
    Ts/(2*Ld+Ts*Rs)*Emax/Imax]));
s16Shift = ceil(log2(maxCoeffRL));
if (s16Shift < -14)
    s16Shift = -14;
end
if (s16Shift > 14)
    error('Input parameters cannot be used - s16Shift exceeds 14');
end

%current gain F16
f16IGain = (2*Ld-Ts*Rs)/(2*Ld+Ts*Rs);
f16IGain = round(f16IGain * 2^15);
f16IGain(f16IGain < -(2^15)) = -(2^15);
f16IGain(f16IGain > (2^15)-1) = (2^15)-1;

%current gain F32
f32IGain = (2*Ld-Ts*Rs)/(2*Ld+Ts*Rs);
f32IGain = round(f32IGain * 2^31);
f32IGain(f32IGain < -(2^31)) = -(2^31);
f32IGain(f32IGain > (2^31)-1) = (2^31)-1;

%current gain FLT
fltIGain = (2*Ld-Ts*Rs)/(2*Ld+Ts*Rs);

%voltage gain F16
f16UGain = Ts/(2*Ld+Ts*Rs)*Umax/Imax*2^-s16Shift;
f16UGain = round(f16UGain * 2^15);
f16UGain(f16UGain < -(2^15)) = -(2^15);
f16UGain(f16UGain > (2^15)-1) = (2^15)-1;

%voltage gain F32
f32UGain = Ts/(2*Ld+Ts*Rs)*Umax/Imax*2^-s16Shift;
f32UGain = round(f32UGain * 2^31);
f32UGain(f32UGain < -(2^31)) = -(2^31);
f32UGain(f32UGain > (2^31)-1) = (2^31)-1;

%voltage gain FLT
fltUGain = Ts/(2*Ld+Ts*Rs);

%speed x current gain F16
f16WIGain = Ts*Lq/(2*Ld+Ts*Rs)*Wmax*2^-s16Shift;
f16WIGain = round(f16WIGain * 2^15);
f16WIGain(f16WIGain < -(2^15)) = -(2^15);
f16WIGain(f16WIGain > (2^15)-1) = (2^15)-1;

%speed x current gain F32
f32WIGain = Ts*Lq/(2*Ld+Ts*Rs)*Wmax*2^-s16Shift;
f32WIGain = round(f32WIGain * 2^31);
f32WIGain(f32WIGain < -(2^31)) = -(2^31);
f32WIGain(f32WIGain > (2^31)-1) = (2^31)-1;

%speed x current gain FLT
fltWIGain = Ts*Lq/(2*Ld+Ts*Rs);

%back-EMF gain F16
f16EGain = Ts/(2*Ld+Ts*Rs)*Emax/Imax*2^-s16Shift;
f16EGain = round(f16EGain * 2^15);
f16EGain(f16EGain < -(2^15)) = -(2^15);
f16EGain(f16EGain > (2^15)-1) = (2^15)-1;

%back-EMF gain F32
f32EGain = Ts/(2*Ld+Ts*Rs)*Emax/Imax*2^-s16Shift;
f32EGain = round(f32EGain * 2^31);
f32EGain(f32EGain < -(2^31)) = -(2^31);
f32EGain(f32EGain > (2^31)-1) = (2^31)-1;

%back-EMF gain FLT
fltEGain = Ts/(2*Ld+Ts*Rs);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% backEMF Observer parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PIr controller parameters for backEMF observers
maxCoeff = max(abs([( Kp + Ki*Ts/2)*Imax/Umax,...
    (-Kp + Ki*Ts/2)*Imax/Umax]));
u16NShift = max(0, ceil(log2(maxCoeff)));
if (u16NShift > 14)
    error('Inputted parameters cannot be used - u16NShift exceeds 14');
end

%f16CC1 for PIr backEMF controller in D-axis F16
f16CC1sc_D = (Kp + Ki*Ts/2)*Imax/Umax*2^-u16NShift;
f16CC1sc_D = round(f16CC1sc_D * 2^15);
f16CC1sc_D(f16CC1sc_D < -(2^15)) = -(2^15);
f16CC1sc_D(f16CC1sc_D > (2^15)-1) = (2^15)-1;

%f32CC1 for PIr backEMF controller in D-axis F32
f32CC1sc_D = (Kp + Ki*Ts/2)*Imax/Umax*2^-u16NShift;
f32CC1sc_D = round(f32CC1sc_D * 2^31);
f32CC1sc_D(f32CC1sc_D < -(2^31)) = -(2^31);
f32CC1sc_D(f32CC1sc_D > (2^31)-1) = (2^31)-1;

%fltCC1 for PIr backEMF controller in D-axis FLT
fltCC1sc_D = Kp + Ki*Ts/2;

%f16CC2 for PIr backEMF controller in D-axis F16
f16CC2sc_D = (-Kp + Ki*Ts/2)*Imax/Umax*2^-u16NShift;
f16CC2sc_D = round(f16CC2sc_D * 2^15);
f16CC2sc_D(f16CC2sc_D < -(2^15)) = -(2^15);
f16CC2sc_D(f16CC2sc_D > (2^15)-1) = (2^15)-1;

%f32CC2 for PIr backEMF controller in D-axis F32
f32CC2sc_D = (-Kp + Ki*Ts/2)*Imax/Umax*2^-u16NShift;
f32CC2sc_D = round(f32CC2sc_D * 2^31);
f32CC2sc_D(f32CC2sc_D < -(2^31)) = -(2^31);
f32CC2sc_D(f32CC2sc_D > (2^31)-1) = (2^31)-1;

%fltCC2 for PIr backEMF controller in D-axis FLT
fltCC2sc_D = -Kp + Ki*Ts/2;

% PIr backEMF controller limits in D-axis F16
f16UpperLimit_D = 32767;
f16LowerLimit_D = -32768;

% PIr backEMF controller limits in D-axis F32
f32UpperLimit_D = (2^31)-1;
f32LowerLimit_D = -(2^31);

% PIr backEMF controller limits in D-axis FLT
fltUpperLimit_D = 1000;
fltLowerLimit_D = -1000;

%f16CC1 for PIr backEMF controller in Q-axis F16
f16CC1sc_Q = f16CC1sc_D;

%f32CC1 for PIr backEMF controller in Q-axis F32
f32CC1sc_Q = f32CC1sc_D;

%fltCC1 for PIr backEMF controller in Q-axis FLT
fltCC1sc_Q = fltCC1sc_D;

%f16CC2 for PIr backEMF controller in Q-axis F16
f16CC2sc_Q = f16CC2sc_D;

%f32CC2 for PIr backEMF controller in Q-axis F32
f32CC2sc_Q = f32CC2sc_D;

%fltCC2 for PIr backEMF controller in Q-axis FLT
fltCC2sc_Q = fltCC2sc_D;

% PIr backEMF controller limits in Q-axis F16
f16UpperLimit_Q = 32767;
f16LowerLimit_Q = -32768;

% PIr backEMF controller limits in Q-axis F32
f32UpperLimit_Q = (2^31)-1;
f32LowerLimit_Q = -(2^31);

% PIr backEMF controller limits in Q-axis FLT
fltUpperLimit_Q = 1000;
fltLowerLimit_Q = -1000;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Tracking Observer parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% (to be set according to the chosen control system dynamics)
p_Ksi = 0.707;          % position loop attenuation
p_fo = 15;              % position loop natural frequency [Hz]
p_wo = 2*pi*p_fo;       % position loop natural angular frequency [rad/s]
Kp = 4*pi*p_Ksi*p_fo;
Ki = p_wo^2;

% PIr controller parameters for position tracking observer
maxCoeff = max(abs([( Kp + (Ki*Ts)/2)*pi/Wmax,...
    (-Kp + (Ki*Ts)/2)*pi/Wmax]));
NShift = max(0, ceil(log2(maxCoeff)));
if (NShift > 14)
    error('Inputted parameters cannot be used - u16NShift exceeds 14');
end

%f16CC1 for PIr Tracking Observer controller F16
f16CC1sc = (Kp+(Ki*Ts)/2)*pi/Wmax*2^-NShift;
f16CC1sc = round(f16CC1sc * 2^15);
f16CC1sc(f16CC1sc < -(2^15)) = -(2^15);
f16CC1sc(f16CC1sc > (2^15)-1) = (2^15)-1;

%f32CC1 for PIr Tracking Observer controller F32
f32CC1sc = (Kp+(Ki*Ts)/2)*pi/Wmax*2^-NShift;
f32CC1sc = round(f32CC1sc * 2^31);
f32CC1sc(f32CC1sc < -(2^31)) = -(2^31);
f32CC1sc(f32CC1sc > (2^31)-1) = (2^31)-1;

%fltCC1 for PIr Tracking Observer controller FLT
fltCC1 = (Kp+(Ki*Ts)/2);

%f16CC2 for PIr Tracking Observer controller F16
f16CC2sc = (-Kp+(Ki*Ts)/2)*pi/Wmax*2^-NShift;
f16CC2sc = round(f16CC2sc * 2^15);
f16CC2sc(f16CC2sc < -(2^15)) = -(2^15);
f16CC2sc(f16CC2sc > (2^15)-1) = (2^15)-1;

%f32CC2 for PIr Tracking Observer controller F32
f32CC2sc = (-Kp+(Ki*Ts)/2)*pi/Wmax*2^-NShift;
f32CC2sc = round(f32CC2sc * 2^31);
f32CC2sc(f32CC2sc < -(2^31)) = -(2^31);
f32CC2sc(f32CC2sc > (2^31)-1) = (2^31)-1;

%fltCC2 for PIr Tracking Observer controller FLT
fltCC2 = (-Kp+(Ki*Ts)/2);

%u16NShift for PIr Tracking Observer controller
u16NShift = NShift;

%f16C1, u16IntegNShift for PIr Tracking Observer integrator F16
f16C1 = (Ts/2)*Wmax/pi;
f16C1 = round(f16C1 * 2^15);
u16IntegNShift = 0;

%f32C1, u32IntegNShift for PIr Tracking Observer integrator F32
f32C1 = (Ts/2)*Wmax/pi;
f32C1 = round(f32C1 * 2^31);
u16IntegNShift = 0;

%fltC1 PIr Tracking Observer integrator FLT
fltC1 = (Ts/2);

