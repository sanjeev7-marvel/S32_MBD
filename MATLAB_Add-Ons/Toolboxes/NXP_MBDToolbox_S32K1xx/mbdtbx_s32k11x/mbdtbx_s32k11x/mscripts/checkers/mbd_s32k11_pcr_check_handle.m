% Copyright (c) 2019 NXP.
% All rights reserved.
classdef mbd_s32k11_pcr_check_handle < handle
    
    properties (SetAccess = public)
        index = 0;
        elements = {};
    end
    
    methods (Access = public)
        % Constructor
        % Creat new object typt of 'mbd_s32k14_pcr_check_handle'.
        % [model]  - current checking model
        % [name]   - name of current block (fot exsample - 'Motor control block' use for generate error messege)
        % [abbrev] - abbreviation of current block (for example - 'DSPI' use for generate error messege)
        % [mask ]  - mask of current block
        function  obj = mbd_s32k14_pcr_check_handle(model, name, abbrev, mask)  %#ok
            
        end
        
        % Internal method for add new element
        % [block]    - current checking block
        % [name]     - name of current block (fot exsample - 'Motor control block' use for generate error messege)
        % [abbrev]   - abbreviation of current block (fot exsample - 'DSPI' use for generate error messege)
        % [psr_type] - type of pcr. May be:
        %      - {Visible} - simple psr field
        %      - {Script}  - pcr with script accses (only DSPI and ADC)
        %      - {hiden}   - hardware
        % [pcr_name] - array of pcr name
        function add_elements(obj, model, name, abbrev,  mask, pcr_type, pcr_name)
            % find new element in current model
            Blocks = find_system(model,'Regexp','off','LookUnderMasks','on','FollowLinks','on','MaskType',mask);
            
            % if some element is found -> get pcr name
            for i = 1 : length(Blocks)
                %configure pcr_name arrya
                if strcmp(pcr_type, 'Script')
                    new_model = mbd_s32k14_pcr_model_handle(Blocks{i}, name, abbrev, mask, 'Script', pcr_name);
                elseif strcmp(pcr_type, 'Simple')
                    new_model = mbd_s32k14_pcr_model_handle(Blocks{i}, name, abbrev, mask, 'Visible', pcr_name);
                else
                    new_model = mbd_s32k14_pcr_model_handle(Blocks{i}, name, abbrev, mask, 'none', pcr_name);
                end
                obj.index = obj.index + 1;
                
                %check new element for duplicate pin
                for j = 1 : length(obj.elements)
                    error_index = find(obj.elements(j), new_model);
                    %if element is found -> generate error
                    if error_index == 1
                        %generate error string for 1-st element (current element)
                        err_str_current = get_error(obj.elements(j), new_model);
                        new_model.error_message = [new_model.error_message err_str_current];
                        %save index destination block
                        new_model.error_block_number = [new_model.error_block_number num2str(j)];
                        %modify error flag
                        new_model.error_flag = 1;
                    end
                end
                % Add new element in the cell
                % That is wrong!!!
                % We are adding new element with error!!!
                % That is governed by the previous developments (Leopard relise ("close in spirit" error)).
                obj.elements = [obj.elements new_model];
            end
        end
        
        % Public metod for send all error string in matlab framework
        % Sending 2 different message:
        %   - current block  (error_message)
        %   - destination block (error_message_dist (temporarity locked,
        %     becose was founded new method of visualisation at the error
        %     block))
        % Onse method for all block.
        % May be used in the next release.
        function errors = send_error(obj)
            errors = 0;
            for j = 1 : length(obj.elements)
                if obj.elements(j).error_flag == 1
                    for k = 1 : length(obj.elements(j).error_block_number)
                        errors = errors + 1;
                        % send error-message current block
                        dest_block_index = obj.elements(j).error_block_number(k);
                        idx = str2double(char(dest_block_index));
                        mbd_s32k_nag_error(obj.elements(j).block, char(obj.elements(j).error_message(k)), char(obj.elements(idx).block));
                    end
                end
            end
        end
        
    end
    
end
