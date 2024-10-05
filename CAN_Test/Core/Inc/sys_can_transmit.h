#ifndef SYS_CAN_TRANSMIT_H
#define SYS_CAN_TRANSMIT_H

#include "can.h"
#include "stm32f7xx_hal.h"


typedef struct {
	can_data_t tx_data;
	CAN_TxHeaderTypeDef tx_header;
	bool to_send;
} tx_param_t;

enum {
	LD1_CAN = 0,
	LD2_CAN
};

extern const int num_tx_params;

/*
 * Updates the index-th index of the current_tx_params array
 */
void can_update_bparam(uint32_t index, bool data);
void can_update_iparam(uint32_t index, int32_t data);
void can_update_fparam(uint32_t index, float data);

/*
 * inits transmit params to be empty
 */
void can_tx_init(CAN_HandleTypeDef* hcan, uint32_t* mailbox);

/**
 * Checks which params have changed and updates them
 */
void can_incremental_update(tx_param_t* tx_params);

/**
 * Updates all tx_params
 */
void can_tx_refresh();


#endif
