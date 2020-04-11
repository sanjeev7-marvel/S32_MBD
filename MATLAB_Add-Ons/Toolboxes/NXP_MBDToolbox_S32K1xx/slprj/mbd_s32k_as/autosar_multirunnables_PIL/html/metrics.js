function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["autosar_multirunnables_PIL_Init"] = {file: "C:\\Users\\shivama\\AppData\\Roaming\\MathWorks\\MATLAB_Add-Ons\\Toolboxes\\NXP_MBDToolbox_S32K1xx\\slprj\\mbd_s32k_as\\autosar_multirunnables_PIL\\autosar_multirunnables_PIL.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["autosar_multirunnables_PIL_Runnable1"] = {file: "C:\\Users\\shivama\\AppData\\Roaming\\MathWorks\\MATLAB_Add-Ons\\Toolboxes\\NXP_MBDToolbox_S32K1xx\\slprj\\mbd_s32k_as\\autosar_multirunnables_PIL\\autosar_multirunnables_PIL.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["autosar_multirunnables_PIL_Runnable2"] = {file: "C:\\Users\\shivama\\AppData\\Roaming\\MathWorks\\MATLAB_Add-Ons\\Toolboxes\\NXP_MBDToolbox_S32K1xx\\slprj\\mbd_s32k_as\\autosar_multirunnables_PIL\\autosar_multirunnables_PIL.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["autosar_multirunnables_PIL_Runnable3"] = {file: "C:\\Users\\shivama\\AppData\\Roaming\\MathWorks\\MATLAB_Add-Ons\\Toolboxes\\NXP_MBDToolbox_S32K1xx\\slprj\\mbd_s32k_as\\autosar_multirunnables_PIL\\autosar_multirunnables_PIL.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["autosar_multirunnables_PIL_Start"] = {file: "C:\\Users\\shivama\\AppData\\Roaming\\MathWorks\\MATLAB_Add-Ons\\Toolboxes\\NXP_MBDToolbox_S32K1xx\\slprj\\mbd_s32k_as\\autosar_multirunnables_PIL\\autosar_multirunnables_PIL.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="autosar_multirunnables_PIL_metrics.html">Global Memory: 0(bytes) Maximum Stack: 0(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
