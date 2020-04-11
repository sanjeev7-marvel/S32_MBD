% Copyright (c) 2019 NXP.
% All rights reserved
function tpp_s32k_select_write_reg()
    maskObj = Simulink.Mask.get(gcb);
    valReg = get_param(gcb, 'tppRegister');

    registerMask0 = maskObj.getDialogControl('tppMask0Bits');
    registerMask1 = maskObj.getDialogControl('tppMask1Bits');
    registerMode = maskObj.getDialogControl('tppModeBits');
    registerClint0 = maskObj.getDialogControl('tppClint0Bits');
    registerClint1 = maskObj.getDialogControl('tppClint1Bits');

    switch valReg
        case 'TPP_MASK0'
            registerMask0.Visible = 'on';
            registerMask1.Visible = 'off';
            registerMode.Visible = 'off';
            registerClint0.Visible = 'off';
            registerClint1.Visible = 'off';
        case 'TPP_MASK1'
            registerMask0.Visible = 'off';
            registerMask1.Visible = 'on';
            registerMode.Visible = 'off';
            registerClint0.Visible = 'off';
            registerClint1.Visible = 'off';
         case 'TPP_MODE'
            registerMask0.Visible = 'off';
            registerMask1.Visible = 'off';
            registerMode.Visible = 'on';
            registerClint0.Visible = 'off';
            registerClint1.Visible = 'off';
        case 'TPP_CLINT0'
            registerMask0.Visible = 'off';
            registerMask1.Visible = 'off';
            registerMode.Visible = 'off';
            registerClint0.Visible = 'on';
            registerClint1.Visible = 'off';
        case 'TPP_CLINT1'
            registerMask0.Visible = 'off';
            registerMask1.Visible = 'off';
            registerMode.Visible = 'off';
            registerClint0.Visible = 'off';
            registerClint1.Visible = 'on';
    end
end