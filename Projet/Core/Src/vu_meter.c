/*
 * vu_meter.c
 *
 *  Created on: Nov 9, 2023
 *      Author: maelkorc48
 */
#include "vu_meter.h"

h_vu_t h_vu;
int led[] = {0x00, 0xFF};

int vu_init(h_vu_t *h_vu){
	HAL_GPIO_WritePin(GPIO_TypeDef* VU_ADRESS, uint16_t VU_IODIRA_ADRESS, GPIO_PinState 0);
	HAL_GPIO_WritePin(GPIO_TypeDef* VU_ADRESS, uint16_t VU_IODIRB_ADRESS, GPIO_PinState 0);
}
