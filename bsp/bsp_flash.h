/*
 * bsp_flash.h
 *
 *  Created on: Jul 19, 2018
 *      Author: julian
 */

#ifndef BSP_NUCLEO_F103_FLASH_H_
#define BSP_NUCLEO_F103_FLASH_H_

#include "bsp/bsp.h"

#define BSP_FLASH_NUMPAGES      ((FLASH_BANK1_END-FLASH_BASE+1)/FLASH_PAGE_SIZE)

/**
 * @brief The Flash error reasons. 
 */
#define BSP_FLASH_ERR_NONE      0x00000000    /*!< No error */
#define BSP_FLASH_ERR_PROG      0x00000001    /*!< Programming error */
#define BSP_FLASH_ERR_WRP       0x00000002    /*!< Write protection error */
#define BSP_FLASH_ERR_OPTV      0x00000004    /*!< Option validity error */

/**
 * @brief Used to get the last flash error reason.
 * 
 * @return The detected errors. For each detected error a bit will be set in
 *         this value. See BSP_FLASH_ERR_xxxx for bit detinitions.
 */
uint32_t bspFlashGetErr(void);

/**
  * @brief  Unlock the FLASH control register access.
  * 
  * @retval BSP_OK    in case of success.
  *         BSP_ERR   if unlocking fails.
  */
bspStatus_t bspFlashUnlock(void);

/**
  * @brief  Locks the FLASH control register access.
  * 
  * @retval BSP_OK    in case of success.
  *         BSP_ERR   if locking the flash fails.
  */
bspStatus_t bspFlashLock(void);

/**
  * @brief  Program a half-word (16-bit) at a specified address.
  * 
  * @param  Address specify the address to be programmed.
  * @param  Data    specify the data to be programmed.
  * 
  * @retval BSP_OK      In case of success.
  *         BSP_ELOCK   If the flash is locked.
  *         BSP_EBUSSY  If the flash is busy.
  *         BSP_ERANGE  If the given address can not be programmed.
  *         BSP_ERR     In case of a error while writing to the flash.
  *                     See bspFlashGetErr in that case.
  */
bspStatus_t bspFlashProgHalfWord(uint16_t *addr, uint16_t data);

/**
  * @brief  Program a half-word (16-bit) at a specified address.
  * 
  * @param  Address   specify the address to be programmed.
  * @param  Data      specify the data to be programmed.
  * @param  siz       The number of bytes to program, must be even!
  * 
  * @retval BSP_OK      In case of success.
  *         BSP_ELOCK   If the flash is locked.
  *         BSP_EBUSSY  If the flash is busy.
  *         BSP_ERANGE  If the given address can not be programmed.
  *         BSP_ESIZE   If the given amount of data is not even.
  *         BSP_ERR     In case of a error while writing to the flash.
  *                     See bspFlashGetErr in that case.
  */
bspStatus_t bspFlashProg(uint16_t *addr, uint16_t *pData, size_t siz);


/**
  * @brief  Erase the specified FLASH memory page
  * 
  * @param  addr   Address of the page to erase.
  * 
  * @retval BSP_OK      In case of success.
  *         BSP_ELOCK   If the flash is locked.
  *         BSP_EBUSSY  If the flash is busy.
  *         BSP_ERR     In case of a error while writing to the flash.
  *                     See bspFlashGetErr in that case.
  */
bspStatus_t bspFlashErasePage(uint32_t addr);

/**
  * @brief  Wait for a FLASH operation to complete.
  * 
  * ATTENTION:  On a stm32f103 a write or erase opteration block the flash
  * controller from fetching further instructions. Therefore no code can be 
  * executed while programming or erasing flash. This function does not really
  * makes that much sense!
  * 
  * @param  Timeout   Timeout in ms.
  * 
  * @retval BSP_OK        In case of success.
  *         BSP_ETIMEOUT  In case of a timeout.
  *         BSP_ERR       In case of a error while writing to the flash.
  *                       See bspFlashGetErr in that case.
  */
bspStatus_t bspFlashWaitForLastOperation(uint32_t timeout);

#endif /* BSP_NUCLEO_F103_FLASH_H_ */