/*
 * uart.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Minh Duc Quach
 */

#include "uart.h"

void uart_transmit(){
	switch(FSM_Traffic_Light_State_Row){
		case AUTO_RED:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "A_RED: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case AUTO_GREEN:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "A_GREEN: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case AUTO_YEL:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "A_YEL: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case HAND_RED:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "H_RED: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case HAND_GREEN:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "H_GREEN: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case HAND_YEL:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "H_YEL: %d\r\n", traffic_light_remain_time_row), 1000 );
			break;
		case MANUAL_RED:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "M_RED: %d\r\n", Set_TL_Time), 1000 );
			break;
		case MANUAL_GREEN:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "M_GREEN: %d\r\n", Set_TL_Time), 1000 );
			break;
		case MANUAL_YEL:
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "M_YEL: %d\r\n", Set_TL_Time), 1000 );
			break;
		default:
			break;
	}
}
