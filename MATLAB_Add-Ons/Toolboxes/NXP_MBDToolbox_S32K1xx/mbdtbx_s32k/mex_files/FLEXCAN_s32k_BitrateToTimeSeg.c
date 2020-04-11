/*********************************************************************
*% Copyright (c) 2019 NXP.
% All rights reserved.
* Function Name : FLEXCAN_BitrateToTimeSeg
* Description   : Converts a bitrate (kbit/s) in time segment values for
*                 standard CAN frame.
********************************************************************/
#include <matrix.h>
#include <stdlib.h>
#include <math.h>
#include <mex.h>
#include <stdint.h>

/* CAN bit timing values */
#define FLEXCAN_RJW_MAX        3U

void FLEXCAN_s32k_BitrateToTimeSeg(int bitrate, int clkFreq, int samplePoint, int fd, int *tempSeg)
{
    int prediv_max, min_tq, max_tq, t_seg1_min, t_seg1_max;
    int t_seg2_min, t_seg2_max, propseg_max, pseg1_max, pseg2_max;
    int real_bitrate, real_sample;
    int found_values = false;
    int pseg1, pseg2, propseg, presdiv;
    uint64_t min_dsample, min_dbitrate, tmp_presdiv;
    int t_seg1, t_seg2;
    int tmp_sample, dSample, dBitrate;
    int tmp_pseg1, tmp_pseg2, tmp_propseg, num_tq, tmp_bitrate;

    if (fd == 0)
    {
        prediv_max = 256;
        min_tq = 8;
        max_tq = 25;
        t_seg1_min = 4;
        t_seg1_max = 16;
        t_seg2_min = 2;
        t_seg2_max = 8;
        propseg_max = 7;
        pseg1_max = 7;
        pseg2_max = 7;
    }
    else
    {
        prediv_max = 1024;
        min_tq = 5;
        max_tq = 48;
        t_seg1_min = 2;
        t_seg1_max = 39;
        t_seg2_min = 2;
        t_seg2_max = 8;
        propseg_max = 31;
        pseg1_max = 7;
        pseg2_max = 7;
    }

    min_dsample = 0xFFFFFFFFFFFFFFFF;
    min_dbitrate = 0xFFFFFFFFFFFFFFFF;

    for (tmp_presdiv  = 0U; tmp_presdiv < prediv_max; tmp_presdiv ++) {

        /* Compute the number of time quanta in 1 bit time */
        num_tq = ((clkFreq / ((tmp_presdiv  + 1U) * bitrate * 1000)) + 0.5);
        /* Compute the real bitrate resulted */
        tmp_bitrate = ((clkFreq / ((tmp_presdiv  + 1U) * num_tq)) + 0.5);

        if (num_tq < min_tq)
        {
            break;
        }
        /* The number of time quanta in 1 bit time must be lower than the one supported */
        if (num_tq <= max_tq) {

            /* Compute time segments based on the value of the sampling point */
            t_seg1 = ((num_tq * samplePoint / 100U) + 0.5) - 1U;
            t_seg2 = num_tq - 1U - t_seg1;

            /* Adjust time segment 1 and time segment 2 */
            while ((t_seg1 >= t_seg1_max) || (t_seg2 < 2))
            {
                t_seg2 = t_seg2 + 1U;
                t_seg1 = t_seg1 - 1U;
            }

            tmp_pseg2 = t_seg2 - 1U;

            /* Start from pseg1 = pseg2 and adjust until propseg is valid */
            tmp_pseg1 = tmp_pseg2;

            if (fd == 0)
                tmp_propseg = t_seg1 - tmp_pseg1 - 2;
            else
                tmp_propseg = t_seg1 - tmp_pseg1 - 1;
            while (tmp_propseg <0U)
            {
                tmp_propseg = tmp_propseg + 1U;
                tmp_pseg1 = tmp_pseg1 - 1U;
            }
            while (tmp_propseg  > propseg_max)
            {
                tmp_propseg = tmp_propseg - 1U;
                tmp_pseg1 = tmp_pseg1 + 1U;
            }

            if ((t_seg1 > t_seg1_max) || (t_seg2 > t_seg2_max) || (t_seg2 < t_seg2_min) || (t_seg1 < t_seg1_min))
            {
                continue;
            }
            if ((tmp_propseg > propseg_max) || (tmp_pseg1 > pseg1_max) || (tmp_pseg2 > pseg2_max))
            {
                continue;
            }

            tmp_sample = ((t_seg1 + 1U) * 100U) / (num_tq  + 0.5);
            dSample = (tmp_sample > samplePoint) ? (tmp_sample - samplePoint) : (samplePoint - tmp_sample);
            dBitrate = (tmp_bitrate  > bitrate * 1000U) ? (tmp_bitrate  - bitrate * 1000U) : (bitrate * 1000U - tmp_bitrate);

            if ((dBitrate < min_dbitrate) ||
                ((dBitrate == min_dbitrate) && (dSample < min_dsample)))
            {
                min_dsample = dSample;
                min_dbitrate = dBitrate;
                pseg1 = tmp_pseg1;
                pseg2 = tmp_pseg2;
                presdiv = tmp_presdiv;
                propseg = tmp_propseg;
                real_bitrate = tmp_bitrate;
                real_sample = tmp_sample;
                found_values = true;
            }
        }
    }
    if (found_values)
    {
        tempSeg[0] = propseg;
        tempSeg[1] = pseg1;
        tempSeg[2] = pseg2;
        tempSeg[3] = presdiv;
        tempSeg[4] = (pseg1 < FLEXCAN_RJW_MAX) ? pseg1 : FLEXCAN_RJW_MAX;
        tempSeg[5] = real_bitrate/1000;
        tempSeg[6] = real_sample;
    }
    else
    {
        tempSeg[0] = 7;
        tempSeg[1] = 4;
        tempSeg[2] = 1;
        tempSeg[3] = 2;
        tempSeg[4] = 1;
        tempSeg[5] = 500;
        tempSeg[6] = 87.5;
    }

}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* declare variables */
    int *tempSeg;
    int bitrate, clkFreq, samplePoint, fd;
    const mwSize dims[1] = {7};

    /* associate inputs */
    bitrate = mxGetScalar(prhs[0]);
    clkFreq = mxGetScalar(prhs[1]);
    samplePoint = mxGetScalar(prhs[2]);
    fd = mxGetScalar(prhs[3]);

    plhs[0] = mxCreateNumericArray(1, dims, mxUINT32_CLASS, mxREAL);
    tempSeg = mxGetPr(plhs[0]);

    FLEXCAN_s32k_BitrateToTimeSeg(bitrate, clkFreq, samplePoint, fd, tempSeg);
}
