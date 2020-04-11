#ifndef PDB0_PARAMS_H
#define PDB0_PARAMS_H
#include "pdb_driver.h"
#include "trgmux_driver.h"

extern trgmux_inout_mapping_config_t trgmuxAllMappingConfig[];
extern trgmux_inout_mapping_config_t pdb0MappingConfig;
extern pdb_timer_config_t pdb0TimerConfig;
extern pdb_adc_pretrigger_config_t pdb0Ch0UPreTrigConfig0U;
extern pdb_adc_pretrigger_config_t pdb0Ch0UPreTrigConfig1U;

#endif
