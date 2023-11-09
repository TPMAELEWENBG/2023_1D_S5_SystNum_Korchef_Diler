/*
 * vu_meter.h
 *
 *  Created on: Nov 9, 2023
 *      Author: maelkorc48
 */
#include "main.h"
#ifndef SRC_VU_METER_H_
#define SRC_VU_METER_H_
#define VU_ADDR 0x40
#define VU_IODIRA_ADDRESS 0x00
#define VU_IODIRB_ADDRESS 0x40
#define VU_GPIOA_ADDRESS 0x12
#define VU_GPIOB_ADDRESS 0x13
#define VU_PORTA 0
#define VU_PORTB 1



#endif /* SRC_VU_METER_H_ */

typedef struct h_vu_struct{
   uint8_t led[2];
   uint8_t spi_buffer[3];
} h_vu_t;

int vu_init(h_vu_t *h_vu);
int vu_led(h_vu_t *h_vu, uint8_t port, uint8_t led, uint8_t state);

