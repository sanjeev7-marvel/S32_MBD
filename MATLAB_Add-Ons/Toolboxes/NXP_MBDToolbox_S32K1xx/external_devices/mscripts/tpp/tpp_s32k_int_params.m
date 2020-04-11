% Copyright (c) 2019 NXP.
% All rights reserved.

function int_params = tpp_s32k_int_params(block)
    int_params.tppIsrInstance = get_param(block, 'tppInstance');
    tppConfig = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','tpp_s32k_config', 'tppInstance', int_params.tppIsrInstance);
    int_params.tppIntPrio = get_param(block, 'prioInt');

    int_params.tppIntEn = uint32(0);
    if (strcmp(get_param(block, 'mcuTppIntEn'), 'on'))
		int_params.tppIntEn = uint32(1);
    end
end