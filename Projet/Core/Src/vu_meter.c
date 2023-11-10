/*
 * vu_meter.c
 *
 *  Created on: Nov 9, 2023
 *      Author: maelkorc48
 */
#include "vu_meter.h"
#include "spi.h"
#include "main.h"

h_vu_t h_vu;
uint8_t buffer[3] = {0x40, 0x00, 0x00};
uint8_t buffer2[3] = {0x40, 0x01, 0x00};
uint8_t buffer3[3] = {0x40, 0x12, 0xFF};
uint8_t buffer4[3] = {0x40, 0x13, 0xFF};
uint8_t buffer5[3] = {0x40, 0x12, 0x55};
uint8_t buffer6[3] = {0x40, 0x13, 0xFE};

int vu_init(){
	HAL_GPIO_WritePin(VU_nRESET_GPIO_Port,VU_nRESET_Pin, SET);
	HAL_Delay(100);

	HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, RESET);
	HAL_SPI_Transmit(&hspi3, buffer, Size, timeout);
	HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, RESET);
	HAL_SPI_Transmit(&hspi3, buffer2, Size, timeout);
	HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, SET);

	for(;;){
		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, RESET);
		HAL_SPI_Transmit(&hspi3, buffer3, Size, timeout);
		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, SET);
		HAL_Delay(10);

		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, RESET);
		HAL_SPI_Transmit(&hspi3, buffer4, Size, timeout);
		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, SET);

		HAL_Delay(100);

		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, RESET);
		HAL_SPI_Transmit(&hspi3, buffer5, Size, timeout);
		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, SET);
		HAL_Delay(10);

		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, RESET);
		HAL_SPI_Transmit(&hspi3, buffer6, Size, timeout);
		HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, SET);

		HAL_Delay(100);
	}
	return 1;
}

int vu_led(){
	HAL_SPI_Transmit(&hspi3, buffer3, Size, timeout);
	HAL_SPI_Transmit(&hspi3, buffer4, Size, timeout);
	HAL_Delay(delay);
	HAL_SPI_Transmit(&hspi3, buffer5, Size, timeout);
	HAL_SPI_Transmit(&hspi3, buffer6, Size, timeout);
	HAL_Delay(delay);
	return 1;
}
