% Copyright (c) 2019 NXP.
% All rights reserved.

function mbd_s32k11_consistency_checks(model)
    errors = 0;

    try
        systemTargetFile = get_param(model, 'SystemTargetFile');
        if strcmp(systemTargetFile, 'mbd_s32k11.tlc')
            % Check for model reference.
            errors = mbd_s32k_check_ref_config(model, errors);

            % Check for config block.
            errors = mbd_s32k_config_block_check(model, errors);

%             % Check for shared pins errors.
%             errors = mbd_s32k11_pcr_global_check(model, errors);

%             % Check for ADC sub modules and configuration
%              errors = mbd_s32k11_block_adc_check(model, errors);
%
            % Check for AMMCLIB sub modules and configuration
            errors = mbd_s32k11_block_ammclib_check(model, errors);
%
            % Check for CMP sub modules and configuration
            errors = mbd_s32k11_block_cmp_check(model, errors);
%
%             % Check for CMP sub modules and configuration
%             errors = mbd_s32k11_csec_block_check(model, errors);
%
%             % Check for Custom Init sub modules and configuration
%             errors = mbd_s32k11_block_custom_init_check(model, errors);
%
%             % Check for eDMA sub modules and configuration
%             errors = mbd_s32k11_edma_block_check(model, errors);
%
            % Check for GPIO sub modules and configuration
            errors = mbd_s32k11_block_gpio_check(model, errors);
%
            % Check for FlexCAN sub modules and configuration
            errors = mbd_s32k11_block_fcan_check(model, errors);
%
%             % Check for FlexIO I2C Master sub modules and configuration
%             errors = mbd_s32k11_flexio_i2c_master_check(model, errors);
%
%             % Check for FlexIO SPI sub modules and configuration
%             errors = mbd_s32k11_flexio_spi_check(model, errors);
%
%             % Check for FlexIO UART sub modules and configuration
%             errors = mbd_s32k11_flexio_uart_check(model, errors);

            % Check for FM sub modules and configuration
            errors = mbd_s32k11_block_fm_check(model, errors);

%             % Check for FTM sub modules and configuration
%             errors = mbd_s32k11_block_ftm_check (model, errors);
%
            % Check for LPI2C sub modules and configuration
            errors = mbd_s32k_block_lpi2c_check(model, errors);
%
%             % Check for LPSPI sub modules and configuration
%             errors = mbd_s32k11_block_lpspi_check(model, errors);

            % Check for LPTMR sub modules and configuration
            errors = mbd_s32k11_block_lptmr_check(model, errors);

            % Check for LPUART sub modules and configuration
            errors = mbd_s32k11_block_lpuart_check(model, errors);
%
%             % Check for PDB sub modules and configuration
%             errors = mbd_s32k11_block_pdb_check (model, errors);
%
%             % Check for PIT sub modules and configuration
%             errors = mbd_s32k11_block_pit_check(model, errors);
%
%             % Check for Profiler sub modules and configuration
%             errors = mbd_s32k11_block_profiler_check(model, errors);
%
%             % Check for RTC sub modules and configuration
%             errors = mbd_s32k11_block_rtc_check(model, errors);
%
%             % Check for SBC sub modules and configuration
%             errors = mbd_s32k11_sbc_block_check(model, errors);

             % Check for WDOG sub modules and configuration
             errors = mbd_s32k11_block_wdog_check(model, errors);
        end
    catch ME
        mbd_s32k_dprint(ME);
    end

    % Check for errors and if errors exist fire the error dialog.
    [errors, lic_err_cc] = mbd_s32k_check_lic_expire(gcs, errors);

    if errors > 0
        error('MBD Toolbox configuration check error');
    end

    if lic_err_cc
        error('MBD Toolbox License Fault');
    end
end
