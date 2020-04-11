% MBD_FIND_S32K_ROOT Locate Model Based Design Toolbox path.
% MBD_FIND_S32K_ROOT returns the full path to Model Based Design Toolbox root
% folder.
%
% Examples
%     rootDir = mbd_find_s32k_root
%     MATLAB returns:
%     rootDir = D:\MBDToolbox\S32K\src
%
% Copyright (c) 2006 Freescale Semiconductor, Inc.
% Copyright (c) 2017 NXP.
% All rights reserved.
function mscripts = mbd_find_s32k_root

    fileData = which('mbd_find_s32k_root');
    [mscripts, ~, ~] = fileparts(fileData);
end
