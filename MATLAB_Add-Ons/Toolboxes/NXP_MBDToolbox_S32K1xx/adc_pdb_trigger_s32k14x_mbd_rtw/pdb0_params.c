#include "pdb0_params.h"

pdb_timer_config_t pdb0TimerConfig = {
  .loadValueMode = PDB_LOAD_VAL_IMMEDIATELY,
  .seqErrIntEnable = false,
  .clkPreDiv = PDB_CLK_PREDIV_BY_128,
  .clkPreMultFactor = PDB_CLK_PREMULT_FACT_AS_40,
  .triggerInput = PDB_SOFTWARE_TRIGGER,
  .continuousModeEnable = true,
  .dmaEnable = false,
  .intEnable = false
};

pdb_adc_pretrigger_config_t pdb0Ch0UPreTrigConfig0U = {
  .adcPreTriggerIdx = 0U,
  .preTriggerEnable = true,
  .preTriggerOutputEnable = true,
  .preTriggerBackToBackEnable = false,
};

pdb_adc_pretrigger_config_t pdb0Ch0UPreTrigConfig1U = {
  .adcPreTriggerIdx = 1U,
  .preTriggerEnable = true,
  .preTriggerOutputEnable = true,
  .preTriggerBackToBackEnable = false,
};
