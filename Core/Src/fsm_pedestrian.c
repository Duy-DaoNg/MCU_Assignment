/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 8, 2022
 *      Author: LENOVO
 */
#include "fsm_pedestrian.h"

void FSM_Pedestrian(){
	switch(FSM_Pedestrian_State){
	case IDLE:
		if(buttonPressed_flag[3]){
			buttonPressed_flag[3] = 0;
			FSM_Pedestrian_State = WORK;
			setTimer3(2 * TIMER3_PEDESTRIAN_CYCLE * TICK);
		}
		break;
	case WORK:
		if(timer3Flag == 1){
			FSM_Pedestrian_State = IDLE;
			break;
		}
		if(buttonPressed_flag[3]){
			setTimer3(2 * TIMER3_PEDESTRIAN_CYCLE * TICK);
		}
		/* Turn on Pedestrian Light */
		switch (FSM_Traffic_Light_State_Col){
		case AUTO_RED:
			HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, SET);
			HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, RESET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, RESET);
			HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, SET);
			break;
		case AUTO_YEL:
			HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, SET);
			HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, SET);
			break;
		default:
			break;
		}
		//TODO: Buzzer ....

		break;
	default:
		break;
	}
}
