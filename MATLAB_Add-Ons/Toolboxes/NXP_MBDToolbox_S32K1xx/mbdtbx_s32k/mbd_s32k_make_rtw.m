%mbd_s32k_make_rtw

% Copyright (c) 2015 Freescale Semiconductor, Inc.
% Copyright (c) 2017 NXP.
% All rights reserved.
function mbd_s32k_make_rtw(buildArgs, varargin)
    
    mbd_s32k_build_args(buildArgs);
    
    % Workaround for rtwmakecfg.m search path issue
    mcu = mbd_s32k_get_target_family();
    path(genpath(fullfile(mbd_find_s32k_root, ['mbdtbx_', mcu, 'x'], ['AMMCLIB_', mcu, 'x'], 'bam')), path);
    
    model = mbd_s32k_get_cur_model();
    
    % Remove warning "Converting 'SLData(0)' value to MATLAB value" by setting the maximum
    % length of a vector that can appear literally in the file to 1000 (10 by default)
    set_param(0, 'RTWDataReferencesMinSize', 1000);
    
    if strcmp(get_param(model, 'SimulationMode'), 'external')
        set_param(model, 'OnTargetWaitForStart', 'on')
    end
    
    set_param(model, 'GenerateSampleERTMain','off');
    try
        save_system(model);
    catch ME
        mbd_s32k_dprint(ME);
    end
    
    env_err = 0;
    
    compiler = mbd_s32k_get_config_param(model, 'target_compiler');
    
    if strcmp(get_param(model, 'GenCodeOnly'), 'off')
        configBlocks = find_system(model, 'Regexp','on', 'LookUnderMasks','on', 'MaskType','MBDTBX_EC_S32K');
        if ~isempty(configBlocks)
            configBlocks = configBlocks{1};
        else
            configBlocks = model;
        end
        
        if strcmp(compiler, 'GCC')
            % Add gcc-6.3-arm32-eabi\bin to PATH system environment
            % [libwinpthread1.dll resides there]
            mbd_s32k_add_gcc_to_path();
            
            path_exists = mbd_s32k_set_gcc_path('matlab');
            if path_exists == 0
                % The path variable was not set but the
                % 'mbd_s32k_set_gcc_path' script set it
                sldiagviewer.reportWarning(['Environment Variable GCC_S32K_TOOL was not explicitly set. The generated code will be compiled using the default GCC compiler ', getenv('GCC_S32K_TOOL')]);
            elseif path_exists == 2
                errorMsg = 'Environment Variable GCC_S32K_TOOL not set. Set the location of GCC target compiler and restart MATLAB, please. Example: GCC_S32K_TOOL="C:\NXP\S32DS_ARM_v2018.R1\Cross_Tools\gcc-6.3-arm32-eabi"';
                mbd_s32k_nag_error(configBlocks, errorMsg);
                env_err = 1;
            end
        elseif strcmp(compiler, 'GreenHills Multi')
            if isempty(getenv('GHS_S32K_TOOL'))
                errorMsg = 'Environment Variable GHS_S32K_TOOL not set. Set the location of GHS_S32K_TOOL target compiler and restart MATLAB, please. Example: GHS_S32K_TOOL=c:\ghs\comp_201516';
                mbd_s32k_nag_error(configBlocks, errorMsg);
                env_err = 1;
            end
        elseif strcmp(compiler, 'IAR')
            if isempty(getenv('IAR_TOOL'))
                errorMsg = 'Environment Variable IAR_TOOL not set. Set the location of IAR target compiler and restart MATLAB, please. Example: IAR_TOOL="C:\IAR"';
                mbd_s32k_nag_error(configBlocks, errorMsg);
                env_err = 1;
            end
        end
        
        if env_err == 0
            make_rtw(buildArgs, varargin{:});

            try
                if ~strcmp(buildArgs.ModelReferenceTargetType, 'RTW') && ~mbd_s32k_is_sil
                    mbd_s32k_bam(model, '', 'BAM');
                    mbd_s32k_ds(model);
                end
            catch ME
                fprintf('Exception id %s  message %s ', ME.identifier, ME.message);
                mbd_s32k_dprint(ME);
            end
        end
    end
end
