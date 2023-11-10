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
#define VU_IODIRB_ADDRESS 0x01
#define VU_GPIOA_ADDRESS 0x12
#define VU_GPIOB_ADDRESS 0x13
#define VU_PORTA 0
#define VU_PORTB 1
#define delay 1000
#define timeout 1000
#define Size 3


#endif /* SRC_VU_METER_H_ */

typedef struct h_vu_struct{
   uint8_t led[2];
   uint8_t spi_buffer[3];
} h_vu_t;

int vu_init();
int vu_led();

