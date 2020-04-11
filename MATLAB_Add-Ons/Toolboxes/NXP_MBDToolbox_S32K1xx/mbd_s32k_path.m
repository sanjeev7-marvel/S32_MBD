% MBD_S32K_PATH Setup Model Based Design Toolbox paths.
% MBD_S32K_PATH changes the MATLAB path to remove old Model Based Design
% Toolbox paths and use the newest Model Based Design Toolbox installation.
% By default, the Model Based Design Toolbox paths are prepended to your current
% path.
%
% MBD_S32K_PATH('append') appends the new paths, instead of the default prepending.
% MBD_S32K_PATH('remove') removes old installation paths only.
%
% Examples
%     mbd_s32k_path()
%     MATLAB returns:
%     Treating 'D:\MBDToolbox\S32K\src' as MBD Toolbox installation root.
%     MBD Toolbox path prepended.
%     Successful.
%
% Copyright (c) 2006 Freescale Semiconductor, Inc.
% Copyright (c) 2017 NXP.
% All rights reserved.
function mbd_s32k_path(varargin)
    
    rem = path;
    newpth = [];
    root = fileparts(which('mbd_s32k_path'));
    
    while ~isempty(rem)
        [pth, rem] = strtok(rem, ';');
        if isempty(regexp(pth, 'mbdtbx_s32k', 'once')) && ~strcmpi(pth, root)
            newpth = [newpth pathsep pth];
        end
    end
    
    if nargin == 1 && strcmpi(varargin{1}, 'remove')
        path(newpth);
        savepath;
        rehash toolboxcache;
        disp('Successful.');
        return;
    end
    
    % Add (certain) new MBD Toolbox paths
    
    expandPaths = {
        'external_devices/blocks'
        'external_devices/mscripts'
        'mbdtbx_s32k/src'
        'mbdtbx_s32k/devices'
        'mbdtbx_s32k/mex_files'
        'mbdtbx_s32k/blocks'
        'mbdtbx_s32k/mscripts'
        'mbdtbx_s32k11x/src'
        'mbdtbx_s32k11x/AMMCLIB_s32k11x/bam'
        'mbdtbx_s32k11x/mbdtbx_s32k11x/mscripts'
        'mbdtbx_s32k14x/src'
        'mbdtbx_s32k14x/AMMCLIB_s32k14x/bam'
        'S32_Examples/common'
        'S32_Examples/s32k11x'
        'S32_Examples/s32k14x'
        %autosar files
        'mbdtbx_s32k_as/blocks'
        'mbdtbx_s32k_as/mscripts'
        'mbdtbx_s32k_as/blocks'
        'S32_Examples/autosar'
        };
    
    paths = {
        'external_devices'
        'mbdtbx_s32k'
        'mbdtbx_s32k11x'
        'mbdtbx_s32k11x/mbdtbx_s32k11x'
        'mbdtbx_s32k14x'
        'mbdtbx_s32k14x/mbdtbx_s32k14x'
        'S32_Platform_SDK/platform/devices'
        'S32_Examples'
        'mbdtbx_s32k_as'
        ''
        };
    
    mustFind = [expandPaths; paths];
    
    while true
        notFound = true(length(mustFind), 1);
        for idx = 1 : length(mustFind)
            d = dir([root filesep mustFind{idx}]);
            notFound(idx) = isempty(d);
        end
        
        if sum(notFound) > 0
            newRoot = fileparts(root);
            if strcmpi(newRoot, root)
                disp('Could not find a valid MBD Toolbox installation.');
                return;
            end
            root = newRoot;
        else
            break;
        end
    end
    
    disp(['Treating ''' root ''' as MBD Toolbox installation root.']);
    
    rppth = [];
    for idx = 1 : length(expandPaths)
        rppth = [rppth pathsep genpath([root filesep expandPaths{idx}])];
    end
    for idx = 1 : length(paths)
        rppth = [rppth pathsep root filesep paths{idx}];
    end
    
    % Save, reload, done
    
    if nargin == 1 && strcmpi(varargin{1}, 'append')
        path([newpth pathsep rppth]);
        disp('MBD Toolbox path appended.');
    else
        path([rppth pathsep newpth]);
        disp('MBD Toolbox path prepended.');
    end
    
    savepath;
    rehash toolboxcache;
    sl_refresh_customizations();
    disp('Successful.');
end
