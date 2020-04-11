% Copyright (c) 2019 NXP.
% All rights reserved

function maskStr = tpp_s32k_config_string()
    maskStr = 'TPP Config';

    TPP_instance = get_param(gcb, 'tppInstance');
    TPP_SPI_instance = get_param(gcb, 'tppSpiInst');
    TPP_PWM_module = get_param(gcb, 'tppPwmModule');

    maskStr = [maskStr newline newline 'TPP Instance: ' TPP_instance];
    maskStr = [maskStr newline 'SPI Instance: ' TPP_SPI_instance];
    maskStr = [maskStr newline 'FTM Module: ' TPP_PWM_module];
end