% Copyright (c) 2019 NXP.
% All rights reserved

function pin_info = tpp_s32k_get_pin_info_gpio(block, pin)
    pin_info = mbd_s32k_get_pin_info('gpio', get_param(block, pin));
    pin_info.user_config.inst = get_inst(pin_info.user_config.pt);
end

function instance = get_inst(str)
    instance = ['instance', str(end)];
end