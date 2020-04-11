% SLBLOCKS Defines the block library for a specific Toolbox or Blockset.
%
% Copyright (c) 2017 NXP.
% All rights reserved.
function blkStruct = slblocks

    blkStruct.Name = ['NXP Model-Based Design Toolbox for S32K1xx MCUs' sprintf('\n')]; 
    blkStruct.OpenFcn = 'mbd_s32k_ec_toolbox';
    blkStruct.MaskDisplay = '';
    Browser(1).Library = 'mbd_s32k_ec_toolbox';
    Browser(1).Name    = 'NXP Model-Based Design Toolbox for S32K1xx MCUs';
    Browser(1).IsFlat  = 0;
    Browser(1).Choice  = 1;  % http://www.mathworks.com/matlabcentral/answers/163074-update-library-repository-for-simulink-custom-library
    blkStruct.Browser = Browser;
    
end


