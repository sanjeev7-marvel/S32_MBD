% Copyright (c) 2019 NXP.
% All rights reserved
function tpp_s32k_pwm_cbk()
    ConfigBlocks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','FTM_s32k_pwm_config_block');

    inst = get_param(gcb, 'tppPwmModule');

    for i = 1 : length(ConfigBlocks)
        if strcmp(get_param(ConfigBlocks{i}, 'ftmModule'), inst)
            open_system(ConfigBlocks{i}, 'mask');
        end
    end
end