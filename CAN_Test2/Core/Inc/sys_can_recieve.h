#ifndef SYS_CAN_H
#define SYS_CAN_H

#include "can.h"
#include "main.h"

extern const int can_num_functions;
extern void (*can_functions[])(can_data_t);

void can_recieve_message(CAN_HandleTypeDef* hcan);

void can_recieve_stale();

#endif
