#include "sys_can_recieve.h"
#include "stm32f7xx_hal.h"
#include "main.h"

const int can_num_functions = 2;

static void nop(can_data_t msg) { return; }

static void msg1_handler(can_data_t msg) {
	HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, msg.bval);
}

static void msg2_handler(can_data_t msg) {
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, msg.bval);
}

void (*can_functions[2])(can_data_t) =
		{
			msg1_handler,
			msg2_handler
		};
