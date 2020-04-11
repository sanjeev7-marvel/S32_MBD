#include "pdb0_isr.h"

void pdb0_isr(void)
{
  uint32_t fPDBIF = (uint32_t)PDB_DRV_GetTimerIntFlag(0);
  uint32_t errCh0 = PDB_DRV_GetAdcPreTriggerSeqErrFlags(0, 0, 0xFF);
  uint32_t errCh1 = PDB_DRV_GetAdcPreTriggerSeqErrFlags(0, 1, 0xFF);
  adc_pdb_trigger_s32k14x_Y.outPDBIF = fPDBIF;
  adc_pdb_trigger_s32k14x_Y.outCh0Err = errCh0;
  adc_pdb_trigger_s32k14x_Y.outCh1Err = errCh1;
  adc_pdb_trigger_s32k1_Subsystem();
  if (fPDBIF) {
    PDB_DRV_ClearTimerIntFlag(0);
  }

  if (errCh0) {
    PDB_DRV_ClearAdcPreTriggerSeqErrFlags(0, 0, errCh0);
  }

  if (errCh1) {
    PDB_DRV_ClearAdcPreTriggerSeqErrFlags(0, 1, errCh1);
  }
}
