% Copyright (c) 2019 NXP.
% All rights reserved
function tpp_s32k_check_deadtime_interval(blk, strParam)
    value = str2double(get_param(blk, strParam));

    if isnan(value)
        value = 0;
    end

    if value > 15000
        value = 15000;
    elseif value < 0
        value = 0;
    end

    set_param(blk, strParam, num2str(value));
end
