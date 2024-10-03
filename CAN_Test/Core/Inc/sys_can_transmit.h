#ifndef SYS_CAN_TRANSMIT_H
#define SYS_CAN_TRANSMIT_H

#include "can.h"
#include "stm32f7xx_hal.h"

typedef struct {
	can_data_t tx_data;
	CAN_TxHeaderTypeDef tx_header;
} tx_param_t;

enum {
	LD1_CAN = 0,
	LD2_CAN
};

// To be set by the user
extern tx_param_t current_tx_params[];

extern const int num_tx_params;

/*
 * inits transmit params to be empty
 */
void can_tx_init();

/**
 * Checks which params have changed and updates them
 */
void can_incremental_update(tx_param_t* tx_params);

/**
 * Updates all tx_params
 */
void can_tx_refresh(tx_param_t* tx_params);


#endif
