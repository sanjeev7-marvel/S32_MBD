% Copyright (c) 2019 NXP.
% All rights reserved.

function func_params = tpp_s32k_functional_mode_params(block)
    func_params.tppFuncInstance = get_param(block, 'tppInstance');
    tppConfig = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','tpp_s32k_config', 'tppInstance', func_params.tppFuncInstance);

    func_params.configBlkConfigNow = uint8(0);
    if (strcmp(get_param(tppConfig, 'initTppNow'), 'on'))
        func_params.configBlkConfigNow = uint8(1);
    end
	func_params.tppIntEn = uint32(0);
    if (strcmp(get_param(tppConfig, 'mcuTppIntEn'), 'on'))
		func_params.tppIntEn = uint32(1);
    end
    func_params.tppIntPrio = get_param(tppConfig, 'prioInt');

    % Get TPP ISR instances
    tppIsrBlks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','tpp_s32k_isr', 'tppInstance', func_params.tppFuncInstance);
    func_params.tppIsrBlocks = bitxor(isempty(tppIsrBlks),1);

    func_params.tppFunctionalMode = get_mode(get_param(block, 'action'));
    if (strcmp(func_params.tppFunctionalMode, 'tppModeEnable'))
        func_params.tppFunctionalModeEn = uint8(1);
    else
        func_params.tppFunctionalModeEn = uint8(0);
    end
end

function mode = get_mode(str)
    mode = ['tppMode',str];
end