% Copyright (c) 2019 NXP.
% All rights reserved.
function helpDir = mbd_s32k11_block_help ()

    fileData = which ('mbd_s32k11_block_help');
    [mscripts_dir, ~, ~] = fileparts (fileData);

    tbx_root_ind = strfind (mscripts_dir, '\mbdtbx_s32k11x');
    tbx_root = mscripts_dir (1:tbx_root_ind(1)-1);  % installation directory
    helpDir = fullfile(tbx_root, 'mbdtbx_s32k', 'help');
end