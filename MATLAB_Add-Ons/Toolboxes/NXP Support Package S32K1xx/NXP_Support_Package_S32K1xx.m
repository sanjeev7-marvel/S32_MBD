function varargout = NXP_Support_Package_S32K1xx(varargin)
%   NXP_SUPPORT_PACKAGE_S32K1xx Help
%   The NXP's Model-Based Design Toolbox provides an integrated development
%   environment and toolchain for configuring and generating all of the necessary
%   software automatically (including initialization routines and device drivers)
%   to execute complex applications (e.g.: motor control algorithms, communication
%   protocols CAN, SPI, I2C, UART, and sensor-based applications) on NXP MCUs.
%
%   The toolbox includes integrated Simulink® embedded target for NXP MCUs,
%   peripheral device blocks and drivers, the Math and Motor Control library set
%   and bit-accurate simulation results and provides built-in support for Software
%   and Processor-in-the-Loop (SIL and PIL) simulations, which enables fast
%   prototyping, verification and validation on real targets for the algorithms
%   developed in Matlab environment.
%
%   Copyright (c) 2019 NXP.
%   All rights reserved.

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @NXP_Support_Package_S32K1xx_OpeningFcn, ...
                   'gui_OutputFcn',  @NXP_Support_Package_S32K1xx_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before NXP_Support_Package_S32K1xx is made visible.
function NXP_Support_Package_S32K1xx_OpeningFcn(hObject, eventdata, handles, varargin)
% Choose default command line output for NXP_Support_Package_S32K1xx
handles.output = hObject;
handles.path = pwd;

% Update handles structure
guidata(hObject, handles);
movegui(gcf,'center')

% Load toolbox logo
axes(handles.nxp_logo);
imshow('Installer_Guide_Logo_S32K.png');


% Fill button tooltips
set(handles.Download, 'TooltipString', ...
    sprintf('Click here to open the NXP website download location of the NXP Model-Based Design Toolbox for S32K1xx.\nLog-in with a valid NXP account and download the *.mltbx file on your computer.\nMake sure your web browser downloads the file as *.mltbx'));
  
set(handles.Install, 'TooltipString', ...
    sprintf('Click here to install the NXP Model-Based Design Toolbox mltbx file.\nMATLAB will display a pop up window once the Add-on installation is completed.\nThis might take up to 5 minutes.'));
 
set(handles.OpenToolbox, 'TooltipString', ...
    sprintf('Click here to verify if the NXP Model-Based Design Toolbox for S32K1xx\n was installed correctly and to navigate to toolbox root directory'));

set(handles.License, 'TooltipString', ...
    sprintf('Click here to open the NXP website and generate a cost free, node locked permanent\nlicense file. Check the online documentation for details.\nYou need to provide the Disk ID for the HDD partition on which the toolbox is installed.\ni.e.: use Windows CMD and type: vol C: to obtain the Disk ID'));

set(handles.signup, 'TooltipString', ...
    sprintf('Click here to open the NXP create account website'));


% --- Outputs from this function are returned to the command line.
function varargout = NXP_Support_Package_S32K1xx_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in signup.
function signup_Callback(hObject, eventdata, handles)
web https://www.nxp.com/webapp-signup/register -browser


% --- Executes on selection change in mbdt_version.
function mbdt_version_Callback(hObject, eventdata, handles)
% hObject    handle to mbdt_version (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns mbdt_version contents as cell array
%        contents{get(hObject,'Value')} returns selected item from mbdt_version


% --- Executes during object creation, after setting all properties.
function mbdt_version_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Download.
function Download_Callback(hObject, eventdata, handles)
handles = guidata(hObject);
user_selection = get(handles.mbdt_version,'Value');  
switch (user_selection)
    case {1}
        web https://www.nxp.com/webapp/swlicensing/sso/downloadSoftware.sp?catid=MCTB-EX -browser
        set(handles.Download,'BackgroundColor',[0.1 1 0.4]);
    case {2}
        web https://nxp.flexnetoperations.com/control/frse/download?element=10221477 -browser
        set(handles.Download,'BackgroundColor',[0.1 1 0.4]);
    case {3}
        web https://nxp.flexnetoperations.com/control/frse/download?element=9501347 -browser
        set(handles.Download,'BackgroundColor',[0.1 1 0.4]);
    otherwise
        % should not reach out here, but just in case for the future
        warndlg ('OOPS! No valid version found');
        set(handles.OpenToolbox,'BackgroundColor',[0.9 0.1 0.1]);
end     


% --- Executes on button press in Install.
function Install_Callback(hObject, eventdata, handles)
handles = guidata(hObject);
user_selection = get(handles.mbdt_version,'Value');
contents       = get(handles.mbdt_version,'String');
mbdt_version   = contents{user_selection, 1};

[filename, pathname, filterindex] = uigetfile( ...
    {  '*.mltbx','Matlab Toolbox File (*.mltbx)'; ...
    '*.*',  'All Files (*.*)'}, ...
    'Pick a file', ...
    'MultiSelect', 'off');

if ~isequal(filename,0) || ~isequal(pathname,0)
    if contains(filename,extractBefore(mbdt_version,' '))  
        open(fullfile(pathname,filename));
        set(handles.Install,'BackgroundColor',[0.1 1 0.4]);
    else
        user_option = questdlg('A mismatch between the toolbox version and the selected file has been detected. Are you sure you wish to proceed with the selected file installation?',...
                'Mismatch warning',...
                'Yes','No','No');
        if strcmpi(user_option,'Yes') 
            open(fullfile(pathname,filename));
            set(handles.Install,'BackgroundColor',[0.1 1 0.4]);
        else
            set(handles.Install,'BackgroundColor',[0.9 0.1 0.1]);
        end
    end
end


% --- Executes on button press in OpenToolbox.
function OpenToolbox_Callback(hObject, eventdata, handles)
handles = guidata(hObject);
user_selection = get(handles.mbdt_version,'Value');
contents       = get(handles.mbdt_version,'String');
mbdt_version   = contents{user_selection, 1};
toolboxes = matlab.addons.toolbox.installedToolboxes;
result  = zeros;
for i = 1 : length(toolboxes)
    result(i) = contains(toolboxes(i).Name, 'NXP_MBDToolbox_S32K1xx');
end

if any(result)
    uiwait(msgbox('NXP Model-Based Design Toolbox for S32K1xx was installed successfully','Info','modal'));
    cd(mbd_find_s32k_root);
    set(handles.OpenToolbox,'BackgroundColor',[0.1 1 0.4]);
else
    uiwait(msgbox({'NXP Model-Based Design Toolbox for S32K1xx was not found!', ...
        'Please check Add-Ons/Manage Add-Ons menu to verify if the toolbox exists',...
        'If you have installed a previous version in the past you may want to remove it manually before installing again'},'Warning','modal'));
    set(handles.OpenToolbox,'BackgroundColor',[0.9 0.1 0.1]);
end


% --- Executes on button press in License.
function License_Callback(hObject, eventdata, handles)
handles = guidata(hObject);
user_selection = get(handles.mbdt_version,'Value');  
switch (user_selection)
    case {1}
        web https://www.nxp.com/webapp/swlicensing/sso/downloadSoftware.sp?catid=MCTB-EX -browser
        set(handles.Download,'BackgroundColor',[0.1 1 0.4]);
    case {2}
        web https://nxp.flexnetoperations.com/control/frse/download?element=10221477 -browser
        set(handles.Download,'BackgroundColor',[0.1 1 0.4]);
    case {3}
        web https://nxp.flexnetoperations.com/control/frse/download?element=9501347 -browser
        set(handles.Download,'BackgroundColor',[0.1 1 0.4]);
    otherwise
        % should not reach out here, but just in case for the future
        warndlg ('OOPS! No valid version found');
end


% --- Executes on button press in ActivateLicense.
function ActivateLicense_Callback(hObject, eventdata, handles)
[filename, pathname, filterindex] = uigetfile( ...
    {'*.dat','NXP MBD Toolbox license file (*.dat)'; ...
    '*.lic','NXP MBD Toolbox license file (*.lic)'; ...
    '*.*',  'All Files (*.*)'}, ...
    'Pick a license file', ...
    'MultiSelect', 'off');
if ~isequal(filename,0) || ~isequal(pathname,0)
    toolboxes = matlab.addons.toolbox.installedToolboxes;
    result = zeros;
    for i = 1 : length(toolboxes)
        result(i) = contains(toolboxes(i).Name, 'NXP_MBDToolbox_S32K1xx');
    end
    if any(result)
        copyfile(fullfile(pathname,filename),fullfile(mbd_find_s32k_root,'lic'));
        set(handles.ActivateLicense,'BackgroundColor',[0.1 1 0.4]);
    else
        uiwait(msgbox({'NXP Model-Based Design Toolbox for S32K1xx was not found!', ...
            'Please check Add-Ons/Manage Add-Ons menu to verify if the toolbox exists'},'Warning','modal'));
        set(handles.ActivateLicense,'BackgroundColor',[0.9 0.1 0.1]);
    end
end

% --- Executes on button press in LicenseVerification.
function LicenseVerification_Callback(hObject, eventdata, handles)
try
    toolboxes = matlab.addons.toolbox.installedToolboxes;
    result = zeros;
    for i = 1 : length(toolboxes)
        result(i) = contains(toolboxes(i).Name, 'NXP_MBDToolbox_S32K1xx');
    end
    if any(result)
         if ( (mbd_s32k_check_lic_expire(gcs, 0)) == 0 )
             uiwait(msgbox({'NXP Model-Based Design Toolbox for S32K1xx license activation was successful!','Enjoy using this toolbox'},'Info','modal'));
             set(handles.LicenseVerification,'BackgroundColor',[0.1 1 0.4]);
         else
             uiwait(errordlg('NXP Model-Based Design Toolbox license activation failed','License Error','modal'));
             set(handles.LicenseVerification,'BackgroundColor',[0.9 0.1 0.1]);
         end
    else
        uiwait(msgbox({'NXP Model-Based Design Toolbox for S32K1xx was not found!', ...
            'Please check Add-Ons/Manage Add-Ons menu to verify if this toolbox exists'},'Warning','modal'));
        set(handles.LicenseVerification,'BackgroundColor',[0.9 0.1 0.1]);
    end
    catch ME
        uiwait(errordlg(ME.message,'License Error','modal'));
        set(handles.LicenseVerification,'BackgroundColor',[0.9 0.1 0.1]);
end

% --- Executes on button press in Help.
function Help_Callback(hObject, eventdata, handles)
web https://community.nxp.com/community/mbdt -browser


% --- Executes on button press in NXPPage.
function NXPPage_Callback(hObject, eventdata, handles)
web https://www.nxp.com/mbdt -browser


% --- Executes on button press in Close.
function Close_Callback(hObject, eventdata, handles)
close




