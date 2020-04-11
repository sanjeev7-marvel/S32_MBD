/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * csec_utils.h
 *
 *  Created on: Nov 10, 2016
 *      Author: B50609
 */

#ifndef SOURCES_CSEC_UTILS_H_
#define SOURCES_CSEC_UTILS_H_

#include "csec_driver.h"

/* This function computes the M1-M3 values.
 */
status_t CSEC_Utils_computeM1M2M3(csec_key_id_t authId, uint8_t *authKey, csec_key_id_t keyId, const uint8_t *key, uint32_t counter,
                                  uint8_t *uid, uint8_t *m1, uint8_t *m2, uint8_t *m3);

/* This function erases all the key. After using it, the Flash needs to be partitioned
 * again.
 * */
bool CSEC_Utils_eraseKeys(const uint8_t *authKey);


#endif /* SOURCES_CSEC_UTILS_H_ */
