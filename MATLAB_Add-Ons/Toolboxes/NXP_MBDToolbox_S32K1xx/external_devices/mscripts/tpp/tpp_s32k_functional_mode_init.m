% Copyright (c) 2019 NXP.
% All rights reserved
function maskStr = tpp_s32k_functional_mode_init()
    tppInst = get_param(gcb, 'tppInstance');
    mode = get_param(gcb, 'action');
    maskStr = ['TPP Functional Mode', newline, newline, 'TPP instance:', tppInst, newline, mode, newline];
end