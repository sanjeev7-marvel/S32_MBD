REM Setup the environment for Visual Studio compiler by running the following
REM command: "C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\SetEnv.cmd" /Debug /x64
set MATLAB="C:\Program Files\MATLAB\R2017b"
set VC="C:\Program Files (x86)\Microsoft Visual Studio 10.0"
%MATLAB%\bin\win64\gmake -f makefile VC_DIR=%VC%