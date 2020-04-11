function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["sim_sil_target_AMMCLIB_s32k1xx.c:27c4"]=1;
    this.traceFlag["sim_sil_target_AMMCLIB_s32k1xx.c:27c32"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["sim_sil_target_AMMCLIB_s32k1xx.c:27"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
