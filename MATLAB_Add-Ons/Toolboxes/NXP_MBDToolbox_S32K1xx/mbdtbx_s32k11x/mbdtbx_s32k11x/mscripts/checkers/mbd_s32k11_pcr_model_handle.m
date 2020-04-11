% Copyright (c) 2019 NXP.
% All rights reserved.
classdef mbd_s32k11_pcr_model_handle < handle
    
    properties (SetAccess = public)
        mask = '';
        module = '';
        abbr = '';
        name = '';
        pcr = {};
        error_flag = 0;
        error_message = {};
        error_message_dist = {};
        error_block_number = {};
        block = '';
        extras = {};
    end
    
    methods (Access = public)
        
        % Constructor
        % [block] - current checking block
        % [name] - name of current block (fot example - 'Motor control block' use for generate error messege)
        % [abbrev] - abbreviation of current block (fot example - 'DSPI' use for generate error messege)
        % [psr_type] - type of pcr. May be:
        %      - {Visible} - simple psr field
        %      - {Script}  - pcr with script accses (only DSPI and ADC)
        %      - {empty}   - matrix accses
        % [pcr_name] - array of pcr name
        function  obj = mbd_s32k11_pcr_model_handle(block, name, abbrev, mask, psr_type, pcr_name)
            % Set mask
            obj.mask = mask;
            % Set pin number
            psr_cell =  {};
            if (strcmp(psr_type, 'Visible'))
                psr_cell = obj.add_pcr(block, mask, psr_cell, pcr_name);
            elseif (strcmp(psr_type, 'Script'))
                psr_cell = obj.add_pcr_script(block, mask, psr_cell, pcr_name);
            else %hiden
                psr_cell = pcr_name;
            end
            obj.pcr = psr_cell;
            % Set abbreviation & name
            obj.name = name;
            obj.abbr = abbrev;
            obj.block = block;
            
            for i = 1 : length(psr_cell)
                if (strcmp(psr_cell{i},'None Selected'))
                    obj.error_flag = 1;
                    obj.error_message = {'Block # contains "None Selected" pin'};
                    obj.error_block_number = {'1'};
                end
            end
        end
        
        % Internal method for checking pcr of current block with early
        % founding block
        % [obj_s] - searching object (current object)
        % [obj_d] - destination objects
        % Return - try if pcr is found in previous object
        function ind = find(obj_s, obj_d)
            ind = 0;
            %Allow PCR assigned to just GPIO to be assigned multiple times
            if (strcmp(obj_s.mask, 'gpio_s32k11_output') || (strcmp(obj_s.mask, 'gpio_s32k11_input'))) && (strcmp(obj_s.mask, obj_d.mask))
                return;
            end
            
            %Allow shared pins for DSPI
            if (strcmp(obj_s.mask, 'lpspi_s32k11_transmit')) && (strcmp(obj_d.mask, 'lpspi_s32k11_transmit'))
                return;
            end
            
            % Allow shared pins for ADC
            if strcmp(obj_s.mask, 'adc_s32k11_start_block') && ...
                    strcmp(obj_d.mask, 'adc_s32k11_start_block')
                return;
            end
            
            for i = 1 : length(obj_s.pcr)
                for j = 1 : length(obj_d.pcr)
                    %if pin name is NONE (255) -> that is not error
                    if (strcmp(char(obj_s.pcr(1,i)), 'None Selected'))
                        continue;
                    end
                    if (strcmp(char(obj_d.pcr(1,j)), 'None Selected'))
                        continue;
                    end
                    if ((strcmp(obj_s.pcr(1,i), '')) || (strcmp(obj_d.pcr(1,j), '')))
                        continue;
                    end
                    if (strcmp(char(obj_s.pcr(1,i)), char(obj_d.pcr(1,j))) == 1)
                        ind = 1;
                    end
                end
            end
        end
        
        % Internal method for generating error messege type of:
        % [Abbr error block] +  error pin of + [name of error block] + # is
        % shared with pin of + [name of finded block] + [Abbr of finded
        % block]
        % Return error string
        function  str = get_error(obj_s, obj_d)
            str = '';
            str = strcat(str, obj_d.abbr);
            str = strcat(str, ' error pin of ');
            str = strcat(str, obj_d.name);
            str = strcat(str, ' # is shared with pin of');
            %if it`s the same type of block
            if (strcmp(obj_s.mask, obj_d.mask))
                str = strcat(str, ' another');
            end
            str = strcat(str, obj_s.name);
            str = strcat(str, ' (');
            str = strcat(str, obj_s.abbr);
            str = strcat(str, ' )');
            str = strcat(str, ' &');
        end
        
    end
    
    methods (Static)
        
        % Static internal method for adding pcr (pcr_type is 'Visible')
        % Standart method for getting pcr value
        % Use anywere
        function psr_cell = add_pcr(block, mask, psr_cell, pcr_name)
%             for i = 1 : length(pcr_name)
%                 pcr_field = get_param(block, char(pcr_name(1, i)));
%                 pinInfo = mbd_s32k11_get_pin_info(pcr_field);
%                 psr_cell = [psr_cell pinInfo.pinNum];
%             end
        end
        
        % Static internal method for adding pcr (pcr_type is 'Script')
        % Use only for ADC
        % Direct getting pcr field
        function psr_cell = add_pcr_script(block, mask, psr_cell, pcr_name)
            % ADC
            %psr_cell = mbd_s32k11_adc_pcr_add(block, mask, psr_cell);
            
            % CMP
            %psr_cell = mbd_s32k11_cmp_pcr_add(block, mask, psr_cell);
            
            % FlexCAN Inputs/Outputs
            %psr_cell = mbd_s32k11_fcan_pcr_add(block, mask, psr_cell);
            
            % FM Inputs/Outputs
            %psr_cell = mbd_s32k11_fm_pcr_add(block, mask, psr_cell);
            
            % FTM Inputs
            %psr_cell = mbd_s32k11_ftm_input_pcr_add(block, mask, psr_cell);
            
            % FTM OutputS
            %psr_cell = mbd_s32k11_ftm_output_pcr_add(block, mask, psr_cell);
            
            % LPI2C
            %psr_cell = mbd_s32k11_lpi2c_pcr_add(block, mask, psr_cell);
            
            % LPSPI
            %psr_cell = mbd_s32k11_lpspi_pcr_add(block, mask, psr_cell);
            
            % LPUART Inputs/Outputs
            %psr_cell = mbd_s32k11_lpuart_pcr_add(block, mask, psr_cell);
            
            % PDB
            %psr_cell = mbd_s32k11_pdb_pcr_add(block, mask, psr_cell);
        end
    end
    
end
