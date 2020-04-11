/**
 *######################################################################
 *                (c) Copyright 2017 NXP.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 */

#ifdef __cplusplus
extern "C"{
#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "rtiostream_serial.h"

#include <stddef.h>
#include "rtwtypes.h"
#include "device_registers.h"
#include "lpuart_driver.h"
#include "lpuart_hw_access.h"

  /******************************************************************************
   *                  Macros
   ******************************************************************************/
#define BUF_MASK                       0x3F
#define BUF_SIZE                       (BUF_MASK+1)              /* power of 2 */

  /******************************************************************************
   *                  Static variables
   ******************************************************************************/
  static uint8_T recBuf[BUF_SIZE];
  static volatile uint8_T recNum = 0;
  static uint8_T recBufStart = 0;

    /******************************************************************************
   *                   Global functions
   ******************************************************************************/
  extern void hw_init(void);
  
  void jumpStart(void){
    
    uint32_T *u32Ptr = 0;
    void (*Startup)(void);
#if defined(__GNUC__)	
    extern  uint32_T *__isr_vector;
#elif defined(__IAR_SYSTEMS_ICC__)
    extern  uint32_T *__vector_table;
#endif
    
    /* Bootloader function call */
#if defined(__GNUC__)	
    u32Ptr = (uint32_T *)(&__isr_vector + 1);     /* reset location that contains startup address */
#elif defined(__IAR_SYSTEMS_ICC__)
    u32Ptr = (uint32_T *)(&__vector_table + 1);     /* reset location that contains startup address */
#endif
    
    Startup = (void(*)())(*u32Ptr);    /* Address of start of bootloader */
    Startup();                         /* jump to bootloader code if valid */
    
  }
  

  /******************************************************************************
   *   Function:  SCI_ISR_handler
     @brief    SCI ISR handler .
     @details   SCI ISR handler


     @return none
   */
  void PIL_UART_RX_TX_IRQHandler(void *driverState, uart_event_t event, void *userData)
  {
      if (event == UART_EVENT_RX_FULL) {
        recNum++;
        LPUART_DRV_SetRxBuffer(UART_INSTANCE, &recBuf[(recBufStart+recNum)&BUF_MASK], 1);
      }
      if (event == UART_EVENT_ERROR) {
        LPUART_DRV_ReceiveData(UART_INSTANCE, &recBuf[(recBufStart+recNum)&BUF_MASK], 1);
      }
  }

  /******************************************************************************
   *                   Global functions
   ******************************************************************************/
  /******************************************************************************
   *   Function:  rtIOStreamOpen
     @brief    rtIOStreamOpen .
     @details   rtIOStreamOpen

     @param[in]     argc
     @param[in]     argv

     @return  always 1
   */
  int rtIOStreamOpen(int argc, void * argv[])
  {
    hw_init();

    LPUART_DRV_ReceiveData(UART_INSTANCE, recBuf, 1);

    return 1;
  }

  /******************************************************************************
   *   Function:  rtIOStreamClose
     @brief    rtIOStreamClose .
     @details   rtIOStreamClose

     @param[in]     streamID     streamID

     @return  always 0
   */
  int rtIOStreamClose(int streamID)
  {
    LPUART_DRV_Deinit(UART_INSTANCE);
    jumpStart();
   
    return 0;
  }
  

  /******************************************************************************
   *   Function:  rtIOStreamSend
     @brief    rtIOStreamSend .
     @details   rtIOStreamSend

     @param[in]     streamID     streamID
     @param[in]     src     pointer to data
     @param[in]     size     size
     @param[out]     sizeSent     sizeSent

     @return  always 0
   */
  int rtIOStreamSend(
                     int streamID,
                     const void *src,
                     size_t size,
                     size_t *sizeSent)
  {
    uint8_t* buf = (uint8_T*)src;
    
    LPUART_DRV_SendDataPolling(UART_INSTANCE, buf, (uint32_t) size);
    *sizeSent = size;

    return 0;
  }

  /******************************************************************************
   *   Function:  rtIOStreamRecv
     @brief    rtIOStreamRecv .
     @details   rtIOStreamRecv

     @param[in]     streamID     streamID
     @param[in]     src     pointer to data
     @param[in]     size     size
     @param[out]     sizeRecvd     sizeRecvd

     @return  always 0
   */
  int rtIOStreamRecv(
                     int streamID,
                     void * dst,
                     size_t size,
                     size_t * sizeRecvd)
  {
    int i;
    uint8_T* buf = (uint8_T*)dst;
	
    if (recNum == 0) {
        *sizeRecvd = 0;
        return 0;
    }
    
    INT_SYS_DisableIRQ(UART_RxTx_IRQn);
    
    if (recNum > size) {
      *sizeRecvd = size;
    } else {
      *sizeRecvd = recNum;
    }

    for (i = 0; i < *sizeRecvd; i++) {
      *buf = recBuf[recBufStart];
      buf++;
      recBufStart = (recBufStart+1)&BUF_MASK;
    }
    recNum -= *sizeRecvd;
    INT_SYS_EnableIRQ(UART_RxTx_IRQn);

    return 0;
  }

#ifdef __cplusplus
}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
