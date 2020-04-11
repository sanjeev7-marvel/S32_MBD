% SL_CUSTOMIZATION for PIL connectivity config: s32k_as_pil.ConnectivityConfig

% Copyright (c) 2019 NXP.
% All rights reserved.
function sl_customization(cm)
    cm.registerTargetInfo(@loc_createConfig);
    %% Register custom menu function.
    cm.addCustomMenuFcn('Simulink:ToolsMenu', @getMyMenuItems);

    %% Register external mode transport protocol.
    cm.ExtModeTransports.add('mbd_s32k_as.tlc', 'serial', 'ext_serial_win32_comm', 'Level1');
end

%% PIL connectivity
function config = loc_createConfig
    config = rtw.connectivity.ConfigRegistry;
    config.ConfigName = 's32k_as_pil PIL';
    config.ConfigClass = 's32k_as_pil.ConnectivityConfig';
    config.SystemTargetFile = {'mbd_s32k_as.tlc'};
    config.TemplateMakefile = {'mbd_s32k_as.tmf'};
    config.TargetHWDeviceType = {'ARM Compatible->ARM Cortex'};
end

function schemaFcns = getMyMenuItems(callbackInfo)  %#ok
    schemaFcns = {@getItemA};
end

function schema = getItemA(callbackInfo)  %#ok
    schema = sl_container_schema;
    schema.label = 'NXP Model-Based Design AUTOSAR Toolbox for S32K1xx MCUs';
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'pil');
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'sil');
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'nor');
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'acc');
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'pilblock');
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'silblock');
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
    mbd_s32k_set_pilsil_mode(bdroot, 'mbd_s32k_as.tlc', 'standalone');
end


