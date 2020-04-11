% Copyright (c) 2019 NXP.
% All rights reserved
function tpp_s32k_spi_cbk()
    ConfigBlocks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','lpspi_s32k_config');

    inst = get_param(gcb, 'tppSpiInst');

    for i = 1 : length(ConfigBlocks)
        if strcmp(get_param(ConfigBlocks{i}, 'InstanceNumber'), inst)
            open_system(ConfigBlocks{i}, 'mask');
        end
    end
end