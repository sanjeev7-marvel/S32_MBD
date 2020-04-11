% Copyright (c) 2019 NXP.
% All rights reserved.
function mbd_s32k11_ds(model)
    if (strcmp(mbd_s32k_get_config_param(model, 'ds_import_enable'), 'on')) && (strcmp(mbd_s32k_get_config_param(model, 'target_compiler'), 'GCC') == 1)
        dest_dir = fullfile(pwd, [bdroot, '_mbd_rtw']);
        importer_file = fullfile(dest_dir,'ProjectInfo.xml');
        mcu = mbd_s32k_get_config_param(model, 'mcu_target_name');
        
        % path list
        paths = { '' };
        paths_h = { ...
            '', ...
            strcat('common',filesep), ...
            strcat('inc',filesep), ...
            strcat(mcu,filesep,'include',filesep), ...
            strcat('src',filesep,'clock',filesep,'S32K1xx',filesep), ...
            strcat('src',filesep,'power',filesep,'S32K1xx',filesep) ...
            };
        
        %--------------- xml header --------------------------
        fo = fopen(importer_file,'w+');
        fprintf(fo,'<?xml version="1.0" encoding="UTF-8"?>\n');
        fprintf(fo,'<!--\n');
        fprintf(fo,'	  Copyright : %s NXP, Inc. All Rights Reserved.\n', datestr(datetime('now'),'yyyy'));
        fprintf(fo,'	  This configuration file is a standard interchange file that''s format is maintained\n');
        fprintf(fo,'	  by NXP, Inc. The configuration file is a derivative work\n');
        fprintf(fo,'	  of the Processor Expert Software technology licensed for use by customers\n');
        fprintf(fo,'	  as defined as SOFTWARE in the product''s End User License Agreement. This file\n');
        fprintf(fo,'	  and format are free to use and distribute for read-only purposes. You do not have\n');
        fprintf(fo,'	  the right to create these files or modify this format or use for any purposes other\n');
        fprintf(fo,'	  than interchange with the Processor Expert Software technology.\n');
        fprintf(fo,'	  THIS SOFTWARE IS PROVIDED ''AS IS''.\n');
        fprintf(fo,'	  NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT\n');
        fprintf(fo,'	  LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n');
        fprintf(fo,'	  PURPOSE APPLY TO THIS SOFTWARE. IN NO EVENT WILL NXP BE LIABLE, WHETHER\n');
        fprintf(fo,'	  IN CONTRACT, TORT, OR OTHERWISE, FOR ANY INCIDENTAL, SPECIAL, INDIRECT,\n');
        fprintf(fo,'	  CONSEQUENTIAL OR PUNITIVE DAMAGES, INCLUDING, BUT NOT LIMITED TO, DAMAGES FOR\n');
        fprintf(fo,'	  ANY LOSS OF USE, LOSS OF TIME, INCONVENIENCE, COMMERCIAL LOSS, OR LOST PROFITS,\n');
        fprintf(fo,'	  SAVINGS, OR REVENUES TO THE FULL EXTENT SUCH MAY BE DISCLAIMED BY LAW.\n');
        fprintf(fo,'-->\n');
        
        %--------------- processor --------------------------
        fprintf(fo,'<export xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:noNamespaceSchemaLocation="ProjectInfoDescription.xsd">\n');
        fprintf(fo,'  <PROCESSOR>\n');
        fprintf(fo,['    <DeviceID>', mcu, '</DeviceID>\n']);
        fprintf(fo,'    <CoreNum>1</CoreNum>\n');
        fprintf(fo,'    <Cores>\n');
        fprintf(fo,'      <Core>\n');
        fprintf(fo,'        <CoreSet>cortex-m0plus</CoreSet>\n');
        fprintf(fo,'      </Core>\n');
        fprintf(fo,'    </Cores>\n');
        fprintf(fo,'  </PROCESSOR>\n');
        
        %--------------- paths --------------------------
        % linker file
        fprintf(fo,'  <PATHS>\n');
        ld_list = dir(fullfile(dest_dir, '*.ld'));
        for i = 1:length(ld_list)
            f = ld_list(i).name;
            fprintf(fo,'    <LinkerCommandFile>%s</LinkerCommandFile>\n',f);
        end
        % include files paths
        fprintf(fo,'    <IncludePaths>\n');
        fprintf(fo,'      <Path>.</Path>\n');
        for j = 2: length(paths_h)
            fprintf(fo,'      <Path>%s</Path>\n',paths_h{j});
        end
        fprintf(fo,'    </IncludePaths>\n');
        fprintf(fo,'    <SourceCodePaths>\n');
        fprintf(fo,'      <Path>.</Path>\n');
        fprintf(fo,'    </SourceCodePaths>\n');
        fprintf(fo,'  </PATHS>\n');
        
        %--------------- files --------------------------
        fprintf(fo,'  <FILES>\n');
        
        % list of C-files
        generate_file_list (paths, dest_dir, fo, 'GeneratedCs', 'c');
        
        % list of H-files
        generate_file_list (paths_h, dest_dir, fo, 'GeneratedHs', 'h');
        
        % list of ASM-files
        generate_file_list (paths, dest_dir, fo, 'GeneratedASMs', 's');
        
        % list of libraries
        generate_file_list (paths, dest_dir, fo, 'Libraries', 'a');
        fprintf(fo,'  </FILES>\n');
        
        %--------------- options --------------------------
        fprintf(fo,'  <OPTIONS>\n');
        fprintf(fo,'   <BuildOptions>\n');
        % list of C options
        fprintf(fo,'    <CCoptList>\n');
        user_c_options = mbd_s32k_get_config_param(model, 'gcc_target_compile_opts');
        
        cpu_define = ['CPU_', mbd_s32k_get_config_param('mcu_target_name')];
        if strcmp(cpu_define, 'CPU_S32K144')
            cpu_define = 'CPU_S32K144HFT0VLLT';
        end
        
        all_c_options = strcat(user_c_options,' -DARM_MATH_CM4 -D', cpu_define, ' -D__FPU_PRESENT=1 -D__FPU_USED=1 -D__NVIC_PRIO_BITS=FEATURE_NVIC_PRIO_BITS');
        options = get_option_list(all_c_options);
        for i=1:length(options)
            fprintf(fo,'      <Option>%s</Option>\n',options{i});
        end
        
        % include paths
        inc_dir = '-I.';
        for j = 2: length(paths_h)
            inc_dir = [inc_dir, ' -I.\', paths_h{j}];
        end
        inc_dir = [inc_dir, strcat(' -I"',getenv ('GCC_S32K_TOOL'),'/arm-none-eabi/include"')];
        fprintf(fo,'      <Option>%s</Option>\n',inc_dir);
        fprintf(fo,'    </CCoptList>\n');
        % list of ASM options
        fprintf(fo,'    <ASMoptList>\n');
        user_asm_options = mbd_s32k_get_config_param(model, 'gcc_target_assemble_opts');
        options = get_option_list(user_asm_options);
        for i=1:length(options)
            fprintf(fo,'      <Option>%s</Option>\n',options{i});
        end
        fprintf(fo,'    </ASMoptList>\n');
        
        % list of Linker options
        fprintf(fo,'    <LinkerOptList>\n');
        user_linker_options = mbd_s32k_get_config_param(model, 'gcc_target_link_opts');
        all_linker_options = strcat(user_linker_options,' -Xlinker --gc-sections -Xlinker --defsym=__ram_vector_table__=1 -specs=nosys.specs');
        all_linker_options = strcat(all_linker_options, ' -Wl,-Map,', bdroot, '.map');
        if (isempty(ld_list) == 0)
            all_linker_options = strcat(all_linker_options, ' -T "',ld_list(1).name,'"');
        end
        options = get_option_list(all_linker_options);
        options = [options strcat('--sysroot=',getenv ('GCC_S32K_TOOL'),'/arm-none-eabi/newlib')];
        for i=1:length(options)
            fprintf(fo,'      <Option>%s</Option>\n',options{i});
        end
        fprintf(fo,'    </LinkerOptList>\n');
        fprintf(fo,'   </BuildOptions>\n');
        fprintf(fo,'  </OPTIONS>\n');
        fprintf(fo,'</export>\n');
        fclose(fo);
    end
end

function generate_file_list (paths, dest_dir, fo, name, extension)
    fprintf(fo,strcat('    <',name,'>\n'));
    for j = 1: length(paths)
        c_list = dir(fullfile(dest_dir, [paths{j}, '*.', extension]));
        for i = 1:length(c_list)
            f = c_list(i).name;
            fprintf(fo,'      <PathName>%s</PathName>\n',strcat(paths{j},f));
        end
    end
    fprintf(fo,strcat('    </',name,'>\n'));
end

function list = get_option_list (str)
    list = {};
    [startIndex,endIndex] = regexp(str,'-[A-Z,a-z].*? +(?=-[A-Z,a-z])');
    if (isempty(startIndex) == 0)
        for i=1:length(startIndex)
            s = strtrim(str(startIndex(i):endIndex(i)));
            list = [list s];
        end
        if (endIndex(length(startIndex)) <= length(str))
            ls = str(endIndex(length(startIndex)):length(str));
            [startIndex,endIndex] = regexp(ls,'-[A-Z,a-z].*');
            if (isempty(startIndex) == 0)
                s = strtrim(ls(startIndex(1):endIndex(1)));
                list = [list s];
            end
        end
    end
end
