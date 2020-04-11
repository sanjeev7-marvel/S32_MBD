/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Directive 4.9, A function should be used in preference
 * to a function-like macro where they are interchangeable.
 * Function-like macros are used instead of inline functions in order to ensure
 * that the performance will not be decreased if the functions will not be
 * inlined by the compiler.
 *
 */

/**
 * Additional settings for the particular port.
 */

#define LWIP_PORT_INIT_IPADDR(addr)   IP4_ADDR((addr), 192,168,0,200)
#define LWIP_PORT_INIT_GW(addr)       IP4_ADDR((addr), 192,168,0,1)
#define LWIP_PORT_INIT_NETMASK(addr)  IP4_ADDR((addr), 255,255,255,0)

/* MAC address is passed as compilation option */

/* configuration for applications */

#define LWIP_CHARGEN_APP              1
#define LWIP_DNS_APP                  0
#define LWIP_HTTPD_APP                1
/* Set this to 1 to use the netconn http server,
 * otherwise the raw api server will be used. */
/*#define LWIP_HTTPD_APP_NETCONN     */
#define LWIP_HTTPD_APP_NETCONN        1
#define LWIP_NETBIOS_APP              0
#define LWIP_NETIO_APP                0
#define LWIP_RTP_APP                  0
#define LWIP_SHELL_APP                0
#define LWIP_SNTP_APP                 0
#define LWIP_SOCKET_EXAMPLES_APP      0
#define LWIP_TCPECHO_APP              1
/* Set this to 1 to use the netconn tcpecho server,
 * otherwise the raw api server will be used. */
/*#define LWIP_TCPECHO_APP_NETCONN   */
#define LWIP_TCPECHO_APP_NETCONN      1
#define LWIP_UDPECHO_APP              1
/* Set this to 1 to use the netconn udpecho server,
 * otherwise the raw api server will be used. */
/*#define LWIP_UDPECHO_APP_NETCONN   */
#define LWIP_UDPECHO_APP_NETCONN      1
#define LWIP_LWIPERF_APP              1
#define LWIP_SSL_ECHO_APP             1

/* ENET controller setting */
#define ENET_RXBD_NUM                 7
#define ENET_TXBD_NUM                 1

#define ENET_MIIMODE                  ENET_RMII_MODE
#define ENET_MIISPEED                 ENET_MII_SPEED_100M
