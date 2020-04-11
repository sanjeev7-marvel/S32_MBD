% Copyright (c) 2019 NXP.
% All rights reserved
function tpp_s32k_spi_config(block)
    try
        tppSPI_instance = get_param(block, 'tppSpiInst');
        ConfigBlocks = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                    'FollowLinks','on','MaskType','lpspi_s32k_config');

        for i = 1 : length(ConfigBlocks)
            if strcmp(get_param(ConfigBlocks{i}, 'InstanceNumber'), tppSPI_instance)
                set_param(ConfigBlocks{i}, 'BaudRate', '2000000', 'Role', 'Master','TransferSize', '8', 'BitOrder', 'MSB first', 'PCSPol', 'ActiveLow', ...
                'CPHA','1', 'CPOL', '0', 'WhichPCS', '0');	%set spi params in order to communicate with TPP
                if (get_param(ConfigBlocks{i}, 'InstanceNumber') == '0')
                    set_param(ConfigBlocks{i}, 'sck', 'PTB2: [LPSPI0_SCK | LPSPI Serial Clock I/O]', 'sin', 'PTB3: [LPSPI0_SIN | LPSPI Serial Data Input]', ...
                    'sout', 'PTB4: [LPSPI0_SOUT | LPSPI Serial Data Output]');%set pins to communicate with TPP (DEVKIT_MOTORGD)
                end
            end
        end

	catch ME
        mbd_s32k_dprint(ME);
        rethrow(ME)
    end
end