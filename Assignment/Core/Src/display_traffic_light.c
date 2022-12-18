/*
 * display_traffic_light.c
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */

#include "display_traffic_light.h"

void display_traffic_light(){
	switch (FSM_Traffic_Light_State_Row){
	case AUTO_RED:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
		break;
	case MANUAL_RED:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
		break;
	case MANUAL_RED:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, RESET);
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case MANUAL_GREEN:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case MANUAL_GREEN:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case AUTO_YEL:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case MANUAL_YEL:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case MANUAL_YEL:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	default:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
	}
	switch (FSM_Traffic_Light_State_Col){
	case AUTO_RED:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, RESET);
		break;
	case MANUAL_RED:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, RESET);
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case MANUAL_GREEN:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case AUTO_YEL:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case MANUAL_YEL:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	default:
		break;
	}
}
