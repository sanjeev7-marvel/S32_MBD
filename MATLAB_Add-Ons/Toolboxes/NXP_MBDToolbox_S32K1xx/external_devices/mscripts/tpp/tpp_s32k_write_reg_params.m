% Copyright (c) 2019 NXP.
% All rights reserved.

function reg_params = tpp_s32k_write_reg_params(block)
    reg_params.tppIsrInstance = get_param(block, 'tppInstance');
    tppConfig = find_system(bdroot(gcs),'Regexp','off','LookUnderMasks','on',...
                'FollowLinks','on','MaskType','tpp_s32k_config', 'tppInstance', reg_params.tppIsrInstance);
    reg_params.tppCommand = tpp_get_cmd(get_param(block, 'tppRegister'));
    reg_params.tppSubcommand = tpp_get_subcommand(get_param(block, 'tppRegister'), block);
end

function subcmd = tpp_get_subcommand(reg, block)
    switch(reg)
        case 'TPP_MASK0'
            if (strcmp(get_param(block, 'overtempEvent'), 'on'))
                subcmd = uint32(1);
            else
                subcmd = uint32(0);
            end
            if (strcmp(get_param(block, 'desatEvent'), 'on'))
                subcmd = uint32(subcmd + 2);
            end
            if (strcmp(get_param(block, 'vlsEvent'), 'on'))
                subcmd = uint32(subcmd + 4);
            end
            if (strcmp(get_param(block, 'overcurrentEvent'), 'on'))
                subcmd = uint32(subcmd + 8);
            end

        case 'TPP_MASK1'
            if (strcmp(get_param(block, 'phaseEvent'), 'on'))
                subcmd = uint32(1);
            else
                subcmd = uint32(0);
            end
            if (strcmp(get_param(block, 'framingEvent'), 'on'))
                subcmd = uint32(subcmd + 2);
            end
            if (strcmp(get_param(block, 'writeErrEvent'), 'on'))
                subcmd = uint32(subcmd + 4);
            end
            if (strcmp(get_param(block, 'resetEvent'), 'on'))
                subcmd = uint32(subcmd + 8);
            end

        case 'TPP_MODE'
            if (strcmp(get_param(block, 'DesatMode'), 'on'))
                subcmd = uint32(8);% desatMode is enabled when bit 3 is 0
            else
                subcmd = uint32(0);
            end
            if (strcmp(get_param(block, 'FullonMode'), 'on'))
                subcmd = uint32(subcmd + 2);
            end
            if (strcmp(get_param(block, 'lockMode'), 'on'))
                subcmd = uint32(subcmd + 1);
            end

        case 'TPP_CLINT0'
            if (strcmp(get_param(block, 'clearOvertempEvent'), 'on'))
                subcmd = uint32(1);
            else
                subcmd = uint32(0);
            end
            if (strcmp(get_param(block, 'clearDesatEvent'), 'on'))
                subcmd = uint32(subcmd + 2);
            end
            if (strcmp(get_param(block, 'clearVlsEvent'), 'on'))
                subcmd = uint32(subcmd + 4);
            end
            if (strcmp(get_param(block, 'clearOvercurrentEvent'), 'on'))
                subcmd = uint32(subcmd + 8);
            end

        case 'TPP_CLINT1'
            if (strcmp(get_param(block, 'clearPhaseEvent'), 'on'))
                subcmd = uint32(1);
            else
                subcmd = uint32(0);
            end
            if (strcmp(get_param(block, 'clearFramingEvent'), 'on'))
                subcmd = uint32(subcmd + 2);
            end
            if (strcmp(get_param(block, 'clearWriteErrEvent'), 'on'))
                subcmd = uint32(subcmd + 4);
            end
            if (strcmp(get_param(block, 'clearResetEvent'), 'on'))
                subcmd = uint32(subcmd + 8);
            end
    end
end

function cmd = tpp_get_cmd(str)
    cmd = [str, '_CMD'];
end