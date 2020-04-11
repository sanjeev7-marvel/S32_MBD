% Copyright (c) 2019 NXP.
% All rights reserved.
function helpDir = mbd_s32k11x_mc_block_help()

    fileData = which('mbd_s32k11x_mc_block_help');
    [mscripts_dir, ~, ~] = fileparts(fileData);

    mbdtbx_root_ind = strfind(mscripts_dir, [filesep 'mbdtbx_s32k11x']);
    mbdtbx_root = mscripts_dir(1:mbdtbx_root_ind(1)-1);  % mbdtbx installation directory
    helpDir = fullfile(mbdtbx_root, 'mbdtbx_s32k11x', 'AMMCLIB_s32k11x', 'doc');
end
