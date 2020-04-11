% Copyright (c) 2019 NXP.
% All rights reserved

function pin_info = tpp_s32k_get_pwm_pins(block)
    ftmPWMConfigBlks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','FTM_s32k_pwm_config_block', 'ftmModule', get_param(block, 'tppPwmModule'));

    ftmModule = uint32(str2double(get_param(block, 'tppPwmModule')));
    pin_info.user_config.pwm_pins = {};

    for currChannel = 0 : 7
        if ~strcmp(get_param(ftmPWMConfigBlks{1},['pinFtmCh', num2str(currChannel)]), 'None') && ...
                (strcmp(get_param(ftmPWMConfigBlks{1},['chan', num2str(floor(currChannel/2) * 2) ,'En']), 'on'))
            pin_info.user_config.pwm_pins{end+1} = ...
            mbd_s32k_get_pin_info(['FTM', num2str(ftmModule), '_CH', num2str(currChannel)], get_param(ftmPWMConfigBlks{1},['pinFtmCh', num2str(currChannel)]));
        else
            pin_info.user_config.pwm_pins{end+1} = 'None';
        end
    end
end