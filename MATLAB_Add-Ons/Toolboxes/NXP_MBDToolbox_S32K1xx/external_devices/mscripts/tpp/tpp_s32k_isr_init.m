% Copyright (c) 2019 NXP.
% All rights reserved

function maskStr = tpp_s32k_isr_init(title, str)
    tppInst = get_param(gcb, str);
    maskStr = [newline, title, newline, newline, 'TPP instance:', tppInst, newline];
end