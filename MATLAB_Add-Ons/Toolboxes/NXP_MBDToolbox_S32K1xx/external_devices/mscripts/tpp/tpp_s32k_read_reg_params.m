% Copyright (c) 2019 NXP.
% All rights reserved.

function reg_params = tpp_s32k_read_reg_params(block)
    reg_params.tppIsrInstance = get_param(block, 'tppInstance');
    tppConfig = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','tpp_s32k_config', 'tppInstance', reg_params.tppIsrInstance);
    reg_params.tppSelectedRegister = tpp_get_selected_reg(get_param(block, 'tppRegister'));
end

function reg = tpp_get_selected_reg(str)
    idx = regexp(str, '[0-9]', 'match');
    reg = ['TPP_NULL_STATUS', idx{1}];
end