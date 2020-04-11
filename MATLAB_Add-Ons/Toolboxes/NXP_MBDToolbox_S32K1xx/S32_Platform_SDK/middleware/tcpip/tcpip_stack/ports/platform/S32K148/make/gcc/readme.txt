lwIP for S32K148 port for baremetal & FreeRTOS environments

To get this compiling:
- have S32 Design Studio for ARM installed (we'll use compiler, newlib libraries and make tool)
- clone the lwIP core repository in a folder "lwip" next to the "tcip_stack" folder
- clone the SDK repository
- cd tcpip_stack/ports/platform/S32K148/make/gcc
- Edit UserPaths.mk file pointing to existing paths (S32DS, SDK). Otherwise you can provide the paths when invoking make
- Invoke make, specifying the MAC address that will be configured and OS envirnment (FreeRTOS or baremetal)
  make LWIP_MAC_ADDR_BASE=10:11:12:00:00:00 TARGET_OS=FreeRTOS -j
  It is possible to override paths defined in UserPaths.mk by passing appropriate variables when invoking make:
  make S32DS_DIR_=C:/NXP/S32DS_ARM_v2.0 SDK_DIR_=C:/WORK/sdk_codebase LWIP_MAC_ADDR_BASE=10:11:12:00:00:00 TARGET_OS=FreeRTOS -j

You can modify config files lwipcfg.h & lwipopts.h in ports/platform/S32K148/config/<OS> to suit your needs (stack configuration parameters, included applications etc).

Included in the ports\netif\enetif directory is the interface to ENET driver.

lwIP: http://savannah.nongnu.org/projects/lwip/

