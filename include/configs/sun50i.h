/*
 * Configuration settings for the Allwinner A64 (sun50i) CPU
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * A64 specific configuration
 */

#ifdef CONFIG_USB_EHCI_HCD
#define CONFIG_USB_EHCI_SUNXI
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif

#define CONFIG_SUNXI_USB_PHYS	1

#define GICD_BASE		0x1c81000
#define GICC_BASE		0x1c82000
/*mine
#define CONFIG_BOOTCOMMAND  "run distro_bootcmd"
*/

#define CONFIG_RAMBOOTCOMMAND						\
	"tftp $kernel_addr_r Image;"				\
	"tftp $fdt_addr_r $fdtfile;"					\
	"booti $kernel_addr_r - $fdt_addr_r"

#define CONFIG_SERVERIP 192.168.5.100
#define CONFIG_IPADDR 192.168.5.123
/*
 * Flash orange pipc 2∞Â‘ÿ 2M nor flash
 */


#if defined(CONFIG_MTD_NOR_FLASH)
/*#define CONFIG_CFI_FLASH_USE_WEAK_ACCESSORS
#define CONFIG_FLASH_SHOW_PROGRESS	45

#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT

*/
#define CONFIG_SYS_FLASH_CFI

#define CONFIG_FLASH_CFI_DRIVER		/* Use common CFI driver	*/

#define CONFIG_SYS_FLASH_BASE		0x00000000
#define CONFIG_SYS_FLASH_SIZE		0x00200000	/* 2 MB */

#define CONFIG_SYS_MAX_FLASH_SECT	512
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_FLASH_BANKS_LIST	{ (CONFIG_SYS_FLASH_BASE) }
#define CONFIG_SYS_FLASH_BANKS_SIZES	{ (CONFIG_SYS_FLASH_SIZE) }
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SPL_TEXT_BASE


/*
#define CONFIG_SYS_FLASH_ERASE_TOUT	3000
#define CONFIG_SYS_FLASH_WRITE_TOUT	3000
#define CONFIG_SYS_FLASH_LOCK_TOUT	3000
#define CONFIG_SYS_FLASH_UNLOCK_TOUT	3000
#undef  CONFIG_CMD_SF
#undef  CONFIG_CMD_SPI
*/
#endif


/*end mine*/
/*
 * Include common sunxi configuration where most the settings are
 */
#include <configs/sunxi-common.h>

#endif /* __CONFIG_H */
