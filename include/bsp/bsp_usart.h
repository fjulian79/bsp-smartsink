/*
 * bsp_usart.h
 *
 *  Created on: Jun 4, 2017
 *      Author: julian
 */

#ifndef BSP_USART_H_
#define BSP_USART_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Used to setup the usart.
 *
 * @param baud the desired baud rate
 */
void bspTTYInit(uint32_t baud);

/**
 * Used to transmit any data.
 *
 * @param pData     Pointer to the data to transmit.
 * @param siz       Number of bytes.
 *
 * @return          Number of transmitted bytes.
 */
bspStatus_t bspTTYSendData(uint8_t *pData, uint16_t siz);

/**
 * Used to check if there is data available on the TTY.
 *
 * @return  true if there date.
 *          false it there is no data
 */
bool bspTTYDataAvailable(void);

/**
 * Used to read a single character from the TTY.
 * Hence that this function will block.
 *
 * @return  The read character.
 */
char bspTTYGetChar(void);

#ifdef __cplusplus
}
#endif

#endif /* BSP_USART_H_ */
