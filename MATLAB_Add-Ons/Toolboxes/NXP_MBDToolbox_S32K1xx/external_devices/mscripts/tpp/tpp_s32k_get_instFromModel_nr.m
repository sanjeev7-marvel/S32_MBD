% Copyright (c) 2019 NXP.
% All rights reserved.

function tpp_s32k_get_instFromModel_nr(moduleSearched, outParam, instSearched, message)
    ConfigBlocks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType',moduleSearched);
    % Get a handle for the mask object of block
    maskObj = Simulink.Mask.get(gcb);
    % Get a handle for the dropdown display
    outInst = maskObj.getParameter(outParam);
    if isempty(ConfigBlocks)
        modules_number_cell = message;
        outInst.Enabled = 'off';
    else
       outInst.Enabled = 'on';
    end

    for i = 1 : length(ConfigBlocks)
        modules_number_cell(i) = get_param(ConfigBlocks{i}, instSearched);
    end

    if ~isempty(ConfigBlocks)
        modules_number_cell = num2cell(modules_number_cell);
        modules_number_cell = cellfun(@(x) num2str(x), modules_number_cell, 'uni', false);
        % Re-write TypeOptions for the dropdown list
        outInst.TypeOptions = modules_number_cell;
    end
end