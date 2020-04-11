% This function checks the current model for shared pins between different
% blocks.

% Copyright (c) 2019 NXP.
% All rights reserved.

function [errors] = mbd_s32k11_pcr_global_check(model, errors)

    pin_list = {};
    % Block reference needed for displaying shared pin error.
    block_list = {};

    %% Get Pins from all blocks (and also save the references from those blocks).
    % ADC pins
    CrossCheckEnDis = mbd_s32k_get_config_param('ADC_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'adc_chan'};
        block_type = 'adc_s32k11_start_block';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);

        % Get unique pins used, while maintaining the order
        % Note: ADC can use same pin, but different channel
        % Duplicate channel usage is verified in other script
        % and it is not included in the scope of this one
        [pin_list, uidxs, ~] = unique(pin_list_tmp, 'stable');
        block_list = block_list_tmp(uidxs);
    end

    % CMP pins
    CrossCheckEnDis = mbd_s32k_get_config_param('CMP_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'ope', 'psel', 'msel'};
        block_type = 'cmp_s32k11_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % GPIO pins
    % Get all unique pins in order to avoid comparing 2 GPIO blocks (of same type) between them
    % e.g.: the model has 2 GPO: one for switching the red LED ON if fault is encountered
    % and the other to clear it after that fault is handled. So gpio pins must be compared
    % with all other pins used in other blocks, but not between themselves
    %
    % GPO
    CrossCheckEnDis = mbd_s32k_get_config_param('GPIO_OutputPcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'gpio_pin'};
       
        block_type = 'gpio_s32k11_output';
        [gpio_pin_list, gpio_block_list] = get_pins_from_block(model, block_type, mask_ids);

        % Get the unique pins and their block's reference
        [pin_list_tmp, uidxs, ~] = unique(gpio_pin_list);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, gpio_block_list(uidxs)];
    end

    %GPI
    CrossCheckEnDis = mbd_s32k_get_config_param('GPIO_InputPcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'gpio_pin'};
        
        block_type = 'gpio_s32k11_input';
        [gpio_pin_list, gpio_block_list] = get_pins_from_block(model, block_type, mask_ids);

        block_type = 'gpi_s32k11_isr';
        [gpio_pin_list_tmp, gpio_block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        gpio_pin_list = [gpio_pin_list, gpio_pin_list_tmp];
        gpio_block_list = [gpio_block_list, gpio_block_list_tmp];

        block_type = 'gpi_s32k11_isr_control';
        [gpio_pin_list_tmp, gpio_block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        gpio_pin_list = [gpio_pin_list, gpio_pin_list_tmp];
        gpio_block_list = [gpio_block_list, gpio_block_list_tmp];

        % Get the unique pins and their block's reference
        [pin_list_tmp, uidxs, ~] = unique(gpio_pin_list);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, gpio_block_list(uidxs)];
    end

    % Input edge capture pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FTM_Input_Edge_Inputs_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'pinFtmCh'};
        block_type = 'Input_Edge_Capture_s32k14';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % Dual edge capture pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FTM_Dual_Edge_Inputs_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'pinFtmCh'};
        block_type = 'Dual_Edge_Capture_s32k14';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % Quadrature decoder pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FTM_Quadrature_Inputs_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'phA_pin', 'phB_pin'};
        block_type = 'Quadrature_Decoder_FTM_s32k14';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % FTM PWM pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FTM_PWM_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        block_type = 'FTM_s32k11_pwm_config_block';
        [pin_list_tmp, block_list_tmp] = get_pins_from_ftm_pwm_block(model, block_type);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % FreeMaster pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FM_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'rxd', 'txd'};
        block_type = 'fm_s32k11_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % LPUART pins
    CrossCheckEnDis = mbd_s32k_get_config_param('LPUART_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'rx', 'tx', 'cts', 'rts'};
        block_type = 'lpuart_s32k11_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % LPI2C pins
    CrossCheckEnDis = mbd_s32k_get_config_param('LPI2C_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'sda', 'scl'};
        block_type = 'lpi2c_s32k11_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % LPSPI pins
    CrossCheckEnDis = mbd_s32k_get_config_param('LPSPI_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'sin', 'sout', 'sck', 'pcs0', 'pcs1', 'pcs2', 'pcs3'};
        block_type = 'lpspi_s32k11_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % FlexCAN pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FlexCAN_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'can_rx', 'can_tx'};
        block_type = 'fcan_s32k11_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % FlexIO UART pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FlexIO_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'TxPin', 'RxPin'};
        block_type = 'flexio_uart_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % FlexIO I2C pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FlexIO_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'SDA_pin', 'SCL_pin'};
        block_type = 'flexio_i2c_master_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    % FlexIO SPI pins
    CrossCheckEnDis = mbd_s32k_get_config_param('FlexIO_PcrCheckEnDis');
    if strcmp(CrossCheckEnDis, 'on')
        mask_ids = {'MOSIPin', 'MISOPin', 'SCKPin', 'SSPin'};
        block_type = 'flexio_spi_config';
        [pin_list_tmp, block_list_tmp] = get_pins_from_block(model, block_type, mask_ids);
        pin_list = [pin_list, pin_list_tmp];
        block_list = [block_list, block_list_tmp];
    end

    %% Get duplicate pins and display error message, referencing the blocks
    % that are using them.
    [~,~,pin_idxs] = unique(pin_list);
    dupl_lists = {};
    for i = 1 : length(pin_idxs)-1
        curr_duplicates = {}; 
        for j = i+1 : length(pin_idxs)
            % Pin already parsed
            if pin_idxs(i) == -1
                continue;
            end
            % Duplicate found
            if pin_idxs(i) == pin_idxs(j)
                % Get all duplicates for this pin only once, to avoid unclear error message display.
                curr_duplicates{end + 1} = block_list{j};
                pin_idxs(j) = -1;
           end
        end
        if length(curr_duplicates) > 0
            %mbd_s32k_nag_error(block_list{i}, 'Pin check failed on block #. Pin is shared with other module');
            curr_duplicates = [{block_list{i}}, curr_duplicates];
            dupl_lists{end + 1} = curr_duplicates;
        end
        errors = errors + length(curr_duplicates);
    end

    % Display error messages
    pairs_used = {};
    skip_duplicated_list = false;
    for i = 1 : length(dupl_lists)
        for dupl_idx = 1 : length(dupl_lists{i})-1
            % Check if duplicates were already displayed
            for pair_used_idx = 1 : length(pairs_used)
                if((strcmp(pairs_used{pair_used_idx}{1}, dupl_lists{i}{dupl_idx}) && strcmp(pairs_used{pair_used_idx}{2}, dupl_lists{i}{dupl_idx+1}))...
                || (strcmp(pairs_used{pair_used_idx}{1}, dupl_lists{i}{dupl_idx+1}) && strcmp(pairs_used{pair_used_idx}{2}, dupl_lists{i}{dupl_idx})))
                    skip_duplicated_list = true;
                    break;
                end
            end
            if skip_duplicated_list
                skip_duplicated_list = false;
                continue;
            end
            mbd_s32k_nag_error(dupl_lists{i}{dupl_idx}, 'Pin check failed on block #. Pin is shared with other module: &', dupl_lists{i}{dupl_idx+1});
            % Once shown, mark them as _used_
            pairs_used{end + 1} = [{dupl_lists{i}{dupl_idx}, dupl_lists{i}{dupl_idx+1}}];
        end
    end
end

% block_type: Type attribute from mask (Mask editor -> Documentation -> Type (e.g.: adc_s32k11_start_block)
% mask_idx: array of ids of the pins mask attributes (e.g.: {'sck_pin', 'ss_pin'}) 
% pins: array of pins selected
function [pins, blks] = get_pins_from_block(model, block_type, mask_ids)
    pins = {};
    blks = {};
    blocks = find_system(model,'Regexp','off', 'LookUnderMasks','on', 'FollowLinks','on', 'MaskType',block_type);
    for i = 1 : length(blocks)
        for j = 1 : length(mask_ids)
            % Save pins used and the block where it came from
            % Note: only port_pinNumber will be saved (e.g.: PTA0); it's
            % function or description will be ignored, so they can be matched
            curr_pin = regexp(get_param(blocks{i}, mask_ids{j}), '[a-zA-Z0-9]*:', 'match');
            % Get only value of cell (the string itself)
            % Note: some peripherals have other inputs for pins
            % e.g.: VDD_LV for ADC input, so first check if curr_pin
            % exists to avoid index out of range exception thrown
            if(~isempty(curr_pin))
                pins{end + 1} = curr_pin{1};
                blks{end + 1} = blocks{i};
            end
        end
    end
end

% This is a separate function as the FTM PWM Config block has variable pins in use
% block_type: Type attribute from mask (Mask editor -> Documentation -> Type (e.g.: adc_s32k11_start_block)
% pins: array of pins selected
function [pins, blks] = get_pins_from_ftm_pwm_block(model, block_type)
    pins = {};
    blks = {};
    curr_pin = {};
    blocks = find_system(model,'Regexp','off', 'LookUnderMasks','on', 'FollowLinks','on', 'MaskType',block_type);
    for i = 1 : length(blocks)
        % Iterate through all ftm pins from FTM_PWM_Config block
        for k = 0:2:6
            pair_enable = get_param(blocks{i}, ['chan', num2str(k), 'En']);
            if strcmp(pair_enable, 'on')
                ftm_pin1 = get_param(blocks{i}, ['pinFtmCh', num2str(k)]);
                ftm_pin2 = get_param(blocks{i}, ['pinFtmCh', num2str(k+1)]);

                for ftm_pin_idx = 0:1
                    if ftm_pin_idx == 0
                        curr_pin = ftm_pin1;
                    elseif ftm_pin_idx == 1
                        curr_pin = ftm_pin2;
                    end
                    % Save pins used and the block where it came from
                    % Note: only port_pinNumber will be saved (e.g.: PTA0); it's
                    % function or description will be ignored, so they can be matched
                    curr_pin = regexp(curr_pin, '[a-zA-Z0-9]*:', 'match');
                    if(~isempty(curr_pin))
                        pins{end + 1} = curr_pin{1};
                        blks{end + 1} = blocks{i};
                    end
                end
            end
        end

        % Get ftm fault pins
        ftm_module = int8(str2double(get_param(blocks{i}, 'ftmModule')));
        % The number of faults is variable; it changes depending on the module used
        max_fault = 4;
        if(ftm_module > 3)
            max_fault = 2;
        end
        % Get the pins of all the enabled faults
        for k = 0:(max_fault - 1)
            fault_enable = get_param(blocks{i}, ['fault_disen_', num2str(k)]);
            if strcmp(fault_enable, 'on')
                curr_pin = get_param(blocks{i}, ['fault_pin_', num2str(k)]);
                curr_pin = regexp(curr_pin, '[a-zA-Z0-9]*:', 'match');
                % Get only value of cell (the string itself)
                % Note: some peripherals have other inputs for pins
                % e.g.: VDD_LV for ADC input, so first check if curr_pin
                % exists to avoid index out of range exception thrown
                if(~isempty(curr_pin))
                    pins{end + 1} = curr_pin{1};
                    blks{end + 1} = blocks{i};
                end
            end
        end
    end
end