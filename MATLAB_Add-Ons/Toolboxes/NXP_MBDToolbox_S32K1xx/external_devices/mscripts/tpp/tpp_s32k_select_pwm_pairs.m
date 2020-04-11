% Copyright (c) 2019 NXP.
% All rights reserved
function tpp_s32k_select_pwm_pairs()
    maskObj = Simulink.Mask.get(gcb);
    tppPair0_1 = 0;
    tppPair2_3 = 0;
    tppPair4_5 = 0;
    tppPair6_7 = 0;

    if (strcmp(get_param(gcb, 'tppPair0_1'), 'on'))
		tppPair0_1 = 1;
    end
    if (strcmp(get_param(gcb, 'tppPair2_3'), 'on'))
		tppPair2_3 = 1;
    end
    if (strcmp(get_param(gcb, 'tppPair4_5'), 'on'))
		tppPair4_5 = 1;
    end
    if (strcmp(get_param(gcb, 'tppPair6_7'), 'on'))
		tppPair6_7 = 1;
    end

    warningText = maskObj.getDialogControl('warningPWMpairs');
    sumPwmPairs = tppPair0_1 + tppPair2_3 + tppPair4_5 + tppPair6_7;

    if ((sumPwmPairs > 3) || (sumPwmPairs < 3))
    warningText = maskObj.getDialogControl('warningPWMpairs');
    warningText.Visible = 'on';
    else warningText.Visible = 'off';
    end

end