% Copyright (c) 2019 NXP.
% All rights reserved
function cfg = tpp_s32k_get_config_block(inst)
    cfg = find_system(bdroot(gcs),'Regexp','off', 'LookUnderMasks','on',...
                'FollowLinks','on', 'MaskType','tpp_s32k_config', 'tppInstance', num2str(inst));
    % Transform cell array to string
    cfg = cfg{1};
end