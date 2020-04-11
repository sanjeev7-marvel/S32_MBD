% Copyright (c) 2019 NXP.
% All rights reserved.
function mbd_s32k_as_make_rtw_hook(hookMethod, modelName, rtwroot, templateMakefile, buildOpts, buildArgs, buildInfo)
    % Calling matlab _hook file for additional messages
    % ert_make_rtw_hook(hookMethod, modelName, rtwroot, templateMakefile, buildOpts, buildArgs);
    autosar_make_rtw_hook(hookMethod, modelName, rtwroot, templateMakefile, buildOpts, buildArgs, buildInfo);

    switch hookMethod
        case 'entry'
            % This call forces the model to ignore the checksum
            % and also to regenerate the top model code
            rtw.targetNeedsCodeGen('set', true);
        case 'before_make'
            try
                mbd_s32k_copy_required_files(modelName);

                sourceFiles = dir('*.c');
                for i = 1 : length(sourceFiles)
                    buildInfo.addSourceFiles(sourceFiles(i).name);
                end

                tbxSrcs = '';
                tbxVPath = '';
                tbxIncludes = '';
                

                if strcmp(mbd_s32k_get_target_family, 's32k11')
                    switch  mbd_s32k_get_config_param('target_compiler')
                        case 'GCC'
                            cpu_type_flags = '-mcpu=cortex-m0plus -mfloat-abi=soft';
                        case 'IAR'
                            cpu_type_flags = '--cpu Cortex-M0+ --fpu none';
                        otherwise
                            cpu_type_flags = '-cpu=cortexm0plus -fsoft';
                    end
                else
                    switch  mbd_s32k_get_config_param('target_compiler')
                        case 'GCC'
                            cpu_type_flags = '-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard';
                        case 'IAR'
                            cpu_type_flags = '--cpu Cortex-M4 --fpu VFPv4_sp';
                        otherwise
                            cpu_type_flags = '-cpu=cortexm4 -fpu=vfpv4_d16 -fhard';
                    end
                end

                buildInfo.addTMFTokens('|>TARGET_COMPILER<|', mbd_s32k_get_config_param('target_compiler'), 'makevar');
                buildInfo.addTMFTokens('|>TARGET_MEMORY<|', ['START_FROM_', mbd_s32k_get_config_param('target_memory')], 'makevar');
                buildInfo.addTMFTokens('|>TARGET_MCU<|', mbd_s32k_get_config_param('mcu_target_name'), 'makevar');

                buildInfo.addTMFTokens('|>GCC_TARGET_CC_OPTS<|', [mbd_s32k_get_config_param('gcc_target_compile_opts'), ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>GCC_TARGET_ASM_OPTS<|', [mbd_s32k_get_config_param('gcc_target_assemble_opts'), ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>GCC_TARGET_LINK_OPTS<|', [mbd_s32k_get_config_param('gcc_target_link_opts'), ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>GCC_TARGET_LIB_OPTS<|', mbd_s32k_get_config_param('gcc_target_lib_opts'), 'makevar');

                buildInfo.addTMFTokens('|>GHS_TARGET_CC_OPTS<|', [mbd_s32k_get_config_param('ghs_target_compile_opts'), ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>GHS_TARGET_ASM_OPTS<|', [mbd_s32k_get_config_param('ghs_target_assemble_opts'), ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>GHS_TARGET_LINK_OPTS<|', [mbd_s32k_get_config_param('ghs_target_link_opts'), ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>GHS_TARGET_LIB_OPTS<|', mbd_s32k_get_config_param('ghs_target_lib_opts'), 'makevar');

                iar_cc_flags = strip_old_flags(mbd_s32k_get_config_param('iar_target_compile_opts'));
                iar_asm_flags = strip_old_flags(mbd_s32k_get_config_param('iar_target_assemble_opts'));
                iar_link_flags = strip_old_flags(mbd_s32k_get_config_param('iar_target_link_opts'));

                buildInfo.addTMFTokens('|>IAR_TARGET_CC_OPTS<|', [iar_cc_flags, ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>IAR_TARGET_ASM_OPTS<|', [iar_asm_flags, ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>IAR_TARGET_LINK_OPTS<|', [iar_link_flags, ' ', cpu_type_flags], 'makevar');
                buildInfo.addTMFTokens('|>IAR_TARGET_LIB_OPTS<|', mbd_s32k_get_config_param('iar_target_lib_opts'), 'makevar');

                if strcmp(mbd_s32k_get_target_family, 's32k11')
                    buildInfo.addTMFTokens('|>TARGET_FPU<|', '0', 'makevar');
                    if strcmp(mbd_s32k_get_config_param('target_compiler'), 'IAR')
                        buildInfo.addTMFTokens('|>TARGET_LINKER<|', 'S32K11x.icf', 'makevar');
                    else
                        buildInfo.addTMFTokens('|>TARGET_LINKER<|', 'S32K11x.ld', 'makevar');
                    end
                else
                    buildInfo.addTMFTokens('|>TARGET_FPU<|', '1', 'makevar');
                    if strcmp(mbd_s32k_get_config_param('target_compiler'), 'IAR')
                        buildInfo.addTMFTokens('|>TARGET_LINKER<|', 'S32K14x.icf', 'makevar');
                    else
                        buildInfo.addTMFTokens('|>TARGET_LINKER<|', 'S32K14x.ld', 'makevar');
                    end
                end
                %SDK Target MCU
                if strcmp(mbd_s32k_get_config_param('mcu_target_name'), 'S32K144')
                    buildInfo.addTMFTokens('|>SDK_TARGET_MCU<|', 'S32K144HFT0VLLT', 'makevar');
                else
                    buildInfo.addTMFTokens('|>SDK_TARGET_MCU<|', mbd_s32k_get_config_param('mcu_target_name'), 'makevar');
                end
                
                 if mbd_s32k_is_rtiostreamtest()
                    tbxSrcs = strtrim(strjoin({tbxSrcs, strjoin({
                        'rtiostreamtest.c'
                        })}));
                    
                    tbxVPath = strtrim(strjoin({tbxVPath, strrep(strjoin({
                        fullfile('$(MATLAB_ROOT)', 'toolbox', 'coder', 'rtiostream', 'src', 'rtiostreamtest')
                        }), '\', '/')}));
                    
                    tbxIncludes = strtrim(strjoin({tbxIncludes, strjoin({
                        ['-I', fullfile('$(MATLAB_ROOT)', 'rtw', 'c', 'src')]
                        ['-I', fullfile('$(MATLAB_ROOT)', 'toolbox', 'coder', 'rtiostream', 'src')]
                        ['-I', fullfile('$(MATLAB_ROOT)', 'toolbox', 'coder', 'rtiostream', 'src', 'rtiostreamtest')]
                        })}));
                end

                buildInfo.addTMFTokens('|>TBX_SRCS<|', tbxSrcs, 'makevar');
                buildInfo.addTMFTokens('|>TBX_VPATH<|', tbxVPath, 'makevar');
                buildInfo.addTMFTokens('|>TBX_INCLUDES<|', tbxIncludes, 'makevar');

                % Trying to link Math for fmodf
                linkFlags = {'-lm'};
                buildInfo.addLinkFlags(linkFlags);
            catch ME
                mbd_s32k_dprint(ME);
            end
    end
end

% Strip flags from model (e.g. --cpu) to avoid duplicate flags
function stripped = strip_old_flags(str)
    stripped = strrep(str, '--cpu=Cortex-M4F', '');
    stripped = strrep(stripped, '--cpu Cortex-M4F', '');
    stripped = strrep(stripped, '--fpu=VFPv4_sp', '');
    stripped = strrep(stripped, '--fpu VFPv4_sp', '');
end
