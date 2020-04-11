% Copyright (c) 2019 NXP.
% All rights reserved
function tppParams = tpp_s32k_params(block)
    try

	tppParams.tppInstance = uint32(str2double(get_param(block, 'tppInstance')));
	tppParams.tppSpiInstance = uint32(str2double(get_param(block, 'tppSpiInst')));
	% TPP interrupt variable
    tppParams.tppIntEn = uint32(0);
    if (strcmp(get_param(block, 'mcuTppIntEn'), 'on'))
		tppParams.tppIntEn = uint32(1);
    end
    tppParams.tppIntPrio = get_param(block, 'prioInt');

    if (strcmp(get_param(block, 'DesatMode'), 'on'))
		% DesatMode is enabled when bit 3 is 0
        tppParams.TppMode = uint32(8);
	else
		tppParams.TppMode = uint32(0);
    end
    if (strcmp(get_param(block, 'FullonMode'), 'on'))
		tppParams.TppMode = uint32(tppParams.TppMode + 2);
    end
    if (strcmp(get_param(block, 'lockMode'), 'on'))
		tppParams.TppMode = uint32(tppParams.TppMode + 1);
    end
	% TPP interrupt mask 0
	if (strcmp(get_param(block, 'overtempEvent'), 'on'))
		tppParams.TppIntMask_0 = uint32(1);
	else
		tppParams.TppIntMask_0 = uint32(0);
	end
	if (strcmp(get_param(block, 'desatEvent'), 'on'))
		tppParams.TppIntMask_0 = uint32(tppParams.TppIntMask_0 + 2);
	end
	if (strcmp(get_param(block, 'vlsEvent'), 'on'))
		tppParams.TppIntMask_0 = uint32(tppParams.TppIntMask_0 + 4);
	end
	if (strcmp(get_param(block, 'overcurrentEvent'), 'on'))
		tppParams.TppIntMask_0 = uint32(tppParams.TppIntMask_0 + 8);
	end

    % TPP interrupt mask 1
	if (strcmp(get_param(block, 'phaseEvent'), 'on'))
		tppParams.TppIntMask_1 = uint32(1);
	else
		tppParams.TppIntMask_1 = uint32(0);
	end
	if (strcmp(get_param(block, 'framingEvent'), 'on'))
		tppParams.TppIntMask_1 = uint32(tppParams.TppIntMask_1 + 2);
	end
	if (strcmp(get_param(block, 'writeErrEvent'), 'on'))
		tppParams.TppIntMask_1 = uint32(tppParams.TppIntMask_1 + 4);
	end
	if (strcmp(get_param(block, 'resetEvent'), 'on'))
		tppParams.TppIntMask_1 = uint32(tppParams.TppIntMask_1 + 8);
	end

	% TPP deadtime
	tppParams.Deadtime = uint32(str2double(get_param(block, 'TppDeadtime')));

	ConfigBlocks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','lpspi_s32k_config');

    for i = 1 : length(ConfigBlocks)
        if strcmp(get_param(ConfigBlocks{i}, 'InstanceNumber'), get_param(block, 'tppSpiInst'))
			tppParams.SPI_baudRateHz = get_param(ConfigBlocks{i}, 'BaudRate');
        end
    end

    tppParams.tppPair0_1 = 0;
    tppParams.tppPair2_3 = 0;
    tppParams.tppPair4_5 = 0;
    tppParams.tppPair6_7 = 0;

    tppParams.tppPwmFirstChHS = 0;

    if (strcmp(get_param(block, 'tppPair0_1'), 'on'))
		tppParams.tppPair0_1 = 1;
    end
    if (strcmp(get_param(block, 'tppPair2_3'), 'on'))
		tppParams.tppPair2_3 = 1;
    end
    if (strcmp(get_param(block, 'tppPair4_5'), 'on'))
		tppParams.tppPair4_5 = 1;
    end
    if (strcmp(get_param(block, 'tppPair6_7'), 'on'))
		tppParams.tppPair6_7 = 1;
    end

	tppParams.tppPwmInst = uint32(str2double(get_param(block, 'tppPwmModule')));
	ftmPWMConfigBlks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','FTM_s32k_pwm_config_block');

    for i = 1:length(ftmPWMConfigBlks)
        ftmModule = uint32(str2double(get_param(ftmPWMConfigBlks{i}, 'ftmModule')));
        if ftmModule == tppParams.tppPwmInst
            tppFtmBlock = ftmPWMConfigBlks{i};
            break;
        end
    end

    tppParams.ftmCombinedMode = 0;

	tppParams.tppPinConfig.tppEn1Pin = tpp_s32k_get_pin_info_gpio(block, 'tppEn1Pin');
	tppParams.tppPinConfig.tppEn2Pin = tpp_s32k_get_pin_info_gpio(block, 'tppEn2Pin');
	tppParams.tppPinConfig.tppRstPin = tpp_s32k_get_pin_info_gpio(block, 'tppRstPin');
	tppParams.tppPinConfig.tppCsPin = tpp_s32k_get_pin_info_gpio(block, 'tppCsPin');
	tppParams.tppPinConfig.tppIntPin = tpp_s32k_get_pin_info_gpio(block, 'tppIntPin');
    tppParams.tppPinConfig.pwmPins = tpp_filter_enabled_signals(tpp_s32k_get_pwm_pins(block), block);

    if (strcmp(get_param(block, 'tppFirstChHS'), 'on'))
        tppParams.tppPwmFirstChHS = 1;
    end
    tppParams.tppPairPolarity{6} = {};

    % 3 pairs -> 6 channels
    for i = 1 : 6
        if mod(i, 2) ~= 0
            tppParams.tppPairPolarity{i} = uint8(tppParams.tppPwmFirstChHS);
        else
            tppParams.tppPairPolarity{i} = uint8(bitxor(tppParams.tppPwmFirstChHS,1, 'uint8'));
        end
    end

    % Get TPP ISR instances
    tppIsrBlks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','tpp_s32k_isr', 'tppInstance', get_param(block, 'tppInstance'));
    tppParams.tppIsrBlocks = bitxor(isempty(tppIsrBlks),1);

    tppParams.initTppNow = 0;
    if (strcmp(get_param(block, 'initTppNow'), 'on'))
        tppParams.initTppNow = 1;
    end
	catch ME
        mbd_s32k_dprint(ME);
    end
end

function filtered_pins = tpp_filter_enabled_signals(pins, block)
    filtered_pins = {};
    for i = 0 : 3
        if(strcmp(get_param(block, ['tppPair', num2str(2*i), '_', num2str(2*i+1)]), 'on') && ...
            ~strcmp(pins.user_config.pwm_pins{2*i + 1}, 'None'))
            filtered_pins{end+1} = pins.user_config.pwm_pins{2*i + 1};
            filtered_pins{end+1} = pins.user_config.pwm_pins{2*i + 2};
        end
    end
end