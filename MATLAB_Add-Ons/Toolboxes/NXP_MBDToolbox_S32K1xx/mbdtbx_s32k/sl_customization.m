% SL_CUSTOMIZATION for PIL connectivity config: s32k_pil.ConnectivityConfig

% Copyright (c) 2017 NXP.
% All rights reserved.
function sl_customization(cm)
    cm.registerTargetInfo(@loc_createConfig);
    %% Register custom menu function.
    cm.addCustomMenuFcn('Simulink:ToolsMenu', @getMyMenuItems);
    %% Change the order of libraries in the Simulink Library Browser. 
    cm.LibraryBrowserCustomizer.applyOrder({'NXP Model-Based Design Toolbox for S32K1xx MCUs',-2});
    %% Collaps the Simulink library and expands the NXP library. 
    cm.LibraryBrowserCustomizer.applyNodePreference({'Simulink',false,'NXP Model-Based Design Toolbox for S32K1xx MCUs',true}); 
    %% Register external mode transport protocol.
    cm.ExtModeTransports.add('mbd_s32k.tlc', 'serial', 'ext_serial_win32_comm', 'Level1');
    %% WORKAROUND: Sometimes Simulink selects the Transport MEX-file 'ext_com' instead of
    %% 'ext_serial_win32_comm' and throws an error when you try to run the External Mode. If you
    %% select another Transport layer and select back the 'serial' one, it will use the correct
    %% Transport MEX-file. This strange behaviour is reproducible only in R2019a; in older versions
    %% it works as expected.
    cm.ExtModeTransports.add('mbd_s32k.tlc', 'none', '', 'Level1');

    defineEnumTypes();
end

%% PIL connectivity
function config = loc_createConfig
    config = rtw.connectivity.ConfigRegistry;
    config.ConfigName = 's32k_pil PIL';
    config.ConfigClass = 's32k_pil.ConnectivityConfig';
    config.SystemTargetFile = {'mbd_s32k.tlc'};
    config.TemplateMakefile = {'mbd_s32k.tmf'};
    config.TargetHWDeviceType = {'ARM Compatible->ARM Cortex'};
end

function schemaFcns = getMyMenuItems(callbackInfo)  %#ok
    schemaFcns = {@getItemA};
end

function schema = getItemA(callbackInfo)  %#ok
    schema = sl_container_schema;
    schema.label = 'NXP Model-Based Design Toolbox for S32K1xx MCUs';
    schema.childrenFcns = {@getItem1, @getItem2, @getItem3, @getItem4, @getItem5, @getItem6, @getItem7};
end

%% Define the schema function for first menu item.
function schema = getItem1(callbackInfo)  %#ok
    schema = sl_action_schema;
    schema.label = 'To PIL Mode on S32K';
    schema.userdata = 'udd1';
    schema.callback = @myCallback1;
end

function myCallback1(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'pil');
end

function schema = getItem2(callbackInfo)  %#ok
    % Make a submenu label 'Item Two' with
    % the menu item above three times.
    schema = sl_action_schema;
    schema.label = 'To SIL Mode';
    schema.userdata = 'udd2';
    schema.callback = @myCallback2;
end

function myCallback2(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'sil');
end

function schema = getItem3(callbackInfo)  %#ok
    % Make a submenu label 'Item Two' with
    % the menu item above three times.
    schema = sl_action_schema;
    schema.label = 'To Normal Mode';
    schema.userdata = 'udd3';
    schema.callback = @myCallback3;
end

function myCallback3(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'nor');
end

function schema = getItem4(callbackInfo)  %#ok
    % Make a submenu label 'Item Two' with
    % the menu item above three times.
    schema = sl_action_schema;
    schema.label = 'To Accelerator Mode';
    schema.userdata = 'udd3';
    schema.callback = @myCallback4;
end

function myCallback4(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'acc');
end

function schema = getItem5(callbackInfo)  %#ok
    % Make a submenu label 'Item Two' with
    % the menu item above three times.
    schema = sl_action_schema;
    schema.label = 'Generate PIL Block';
    schema.userdata = 'udd3';
    schema.callback = @myCallback5;
end

function myCallback5(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'pilblock');
end

function schema = getItem6(callbackInfo)  %#ok
    % Make a submenu label 'Item Two' with
    % the menu item above three times.
    schema = sl_action_schema;
    schema.label = 'Generate SIL Block';
    schema.userdata = 'udd3';
    schema.callback = @myCallback6;
end

function myCallback6(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'silblock');
end

function schema = getItem7(callbackInfo)  %#ok
    % Make a submenu label 'Item Two' with
    % the menu item above three times.
    schema = sl_action_schema;
    schema.label = 'To Stand-Alone model';
    schema.userdata = 'udd3';
    schema.callback = @myCallback7;
end

function myCallback7(callbackInfo)  %#ok
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k.tlc', 'standalone');
end

function defineEnumTypes()
    s32k_root = mbd_find_s32k_root();

    enums = {
        'STATUS_SUCCESS'
        'STATUS_ERROR'
        'STATUS_BUSY'
        'STATUS_TIMEOUT'
        'STATUS_UNSUPPORTED'
        'STATUS_FLEXCAN_MB_OUT_OF_RANGE'
        % CSEc specific error codes
        'STATUS_CSEC_SEQUENCE_ERROR'
        'STATUS_CSEC_KEY_NOT_AVAILABLE'
        'STATUS_CSEC_KEY_INVALID'
        'STATUS_CSEC_KEY_EMPTY'
        'STATUS_CSEC_NO_SECURE_BOOT'
        'STATUS_CSEC_KEY_WRITE_PROTECTED'
        'STATUS_CSEC_KEY_UPDATE_ERROR'
        'STATUS_CSEC_RNG_SEED'
        'STATUS_CSEC_NO_DEBUGGING'
        'STATUS_CSEC_MEMORY_FAILURE'
        };

    intValues = hex2dec(strrep({
        '0x0'
        '0x1'
        '0x2'
        '0x3'
        '0x4'
        '0x300'
        % CSEc specific error codes
        '0x400'
        '0x401'
        '0x402'
        '0x403'
        '0x404'
        '0x405'
        '0x406'
        '0x407'
        '0x408'
        '0x409'
        }, '0x', ''));

    Simulink.defineIntEnumType('status_t', ...
        enums, ...
        intValues, ...
        'HeaderFile', fullfile(s32k_root, 'S32_Platform_SDK\platform\devices\status.h'), ...
        'DataScope', 'Imported', ...
        'AddClassNameToEnumNames', false, ...
        'StorageType', 'int32');
end
