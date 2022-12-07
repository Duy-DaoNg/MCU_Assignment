/*
 * fsm_traffic_light.c
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */


#include "fsm_traffic_light.h"

int To_Default_State = 0;
void resetAllButtonState(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		buttonPressed_flag[i] = 0;
	}
}

void changeTime(){
	Set_TL_Time++;
	if(Set_TL_Time >= 100){
		Set_TL_Time = 1;
	}
}
void FSM_Traffic_Light_Row(){
	switch (FSM_Traffic_Light_State_Row) {
	case AUTO_RED:
		if(timer1Flag == 1){
			/* Count down time */
			traffic_light_remain_time_row--;
			if(traffic_light_remain_time_row == 0){
				/* Move to next state*/
				FSM_Traffic_Light_State_Row = AUTO_GREEN;
				traffic_light_remain_time_row = green_time;
			}

			setTimer1(TIMER1_SECOND_DURATION * TICK);
		}
		/* Check if button state is pressed */
		if(buttonPressed_flag[0]){
			/* If button is pressed --> move to MANUAL state */
			buttonPressed_flag[0] = 0;
			Set_TL_Time = red_time;
			FSM_Traffic_Light_State_Row = MANUAL_RED;
			FSM_Traffic_Light_State_Col = BLACK_HOLE;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
			resetAllButtonState();
		}
		break;
	case AUTO_GREEN:
		if(timer1Flag == 1){
			/* Count down time */
			traffic_light_remain_time_row--;
			if(traffic_light_remain_time_row == 0){
				/* Move to next state*/
				FSM_Traffic_Light_State_Row = AUTO_YEL;
				traffic_light_remain_time_row = yellow_time;
			}
			setTimer1(TIMER1_SECOND_DURATION * TICK);
		}
		/* Check if button state is pressed */
		if(buttonPressed_flag[0]){
			/* If button is pressed --> move to MANUAL state */
			buttonPressed_flag[0] = 0;
			Set_TL_Time = red_time;
			FSM_Traffic_Light_State_Row = MANUAL_RED;
			FSM_Traffic_Light_State_Col = BLACK_HOLE;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
			resetAllButtonState();
		}
		break;
	case AUTO_YEL:
		if(timer1Flag == 1){
			/* Count down time */
			traffic_light_remain_time_row--;
			if(traffic_light_remain_time_row == 0){
				/* Move to next state*/
				FSM_Traffic_Light_State_Row = AUTO_RED;
				traffic_light_remain_time_row = red_time;
			}
			setTimer1(TIMER1_SECOND_DURATION * TICK);
		}
		/* Check if button state is pressed */
		if(buttonPressed_flag[0]){
			/* If button is pressed --> move to MANUAL state */
			buttonPressed_flag[0] = 0;
			Set_TL_Time = red_time;
			FSM_Traffic_Light_State_Row = MANUAL_RED;
			FSM_Traffic_Light_State_Col = BLACK_HOLE;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
			resetAllButtonState();
		}
		break;
	case MANUAL_RED:
		if(timer1Flag == 1){
			/* Back to default state */
			FSM_Traffic_Light_State_Row = AUTO_RED;
			traffic_light_remain_time_row = red_time;
			To_Default_State = 1;
			setTimer1(TIMER1_SECOND_DURATION * TICK);
			break;
		}
		if(buttonPressed_flag[0]){
			/* Move to next state */
			buttonPressed_flag[0] = 0;
			Set_TL_Time = green_time;
			FSM_Traffic_Light_State_Row = MANUAL_GREEN;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		if(buttonPressed_flag[1]){
			/* INC. time */
			buttonPressed_flag[1] = 0;
			changeTime();
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		if(buttonPressed_flag[2]){
			/* Save value */
			buttonPressed_flag[2] = 0;
			red_time = Set_TL_Time;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		break;
	case MANUAL_GREEN:
		if(timer1Flag == 1){
			/* Back to default state */
			FSM_Traffic_Light_State_Row = AUTO_RED;
			To_Default_State = 1;
			traffic_light_remain_time_row = red_time;
			setTimer1(TIMER1_SECOND_DURATION * TICK);
			break;
		}
		if(buttonPressed_flag[0]){
			/* Move to next state */
			buttonPressed_flag[0] = 0;
			Set_TL_Time = yellow_time;
			FSM_Traffic_Light_State_Row = MANUAL_YEL;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		if(buttonPressed_flag[1]){
			/* INC. time */
			buttonPressed_flag[1] = 0;
			changeTime();
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		if(buttonPressed_flag[2]){
			/* Save value */
			buttonPressed_flag[2] = 0;
			green_time = Set_TL_Time;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		break;
	case MANUAL_YEL:
		if(timer1Flag == 1){
			/* Back to default state */
			FSM_Traffic_Light_State_Row = AUTO_RED;
			To_Default_State = 1;
			traffic_light_remain_time_row = red_time;
			setTimer1(TIMER1_SECOND_DURATION * TICK);
			break;
		}
		if(buttonPressed_flag[0]){
			/* Move to next state */
			buttonPressed_flag[0] = 0;
			Set_TL_Time = red_time;
			traffic_light_remain_time_row = red_time;
			To_Default_State = 1;
			FSM_Traffic_Light_State_Row = AUTO_RED;
			setTimer1(TIMER1_SECOND_DURATION * TICK);
		}
		if(buttonPressed_flag[1]){
			/* INC. time */
			buttonPressed_flag[1] = 0;
			changeTime();
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		if(buttonPressed_flag[2]){
			/* Save value */
			buttonPressed_flag[2] = 0;
			yellow_time = Set_TL_Time;
			setTimer1(TIMER1_10SECOND_DURATION * TICK);
		}
		break;
	default:
		FSM_Traffic_Light_State_Row = AUTO_RED;
	}
}
void FSM_Traffic_Light_Col(){
	switch (FSM_Traffic_Light_State_Col) {
	case AUTO_RED:
		if(timer2Flag == 1){
			traffic_light_remain_time_col--;
			if(traffic_light_remain_time_col == 0){
				FSM_Traffic_Light_State_Col = AUTO_GREEN;
				traffic_light_remain_time_col = green_time;
			}
			setTimer2(TIMER1_SECOND_DURATION * TICK);
		}
		break;
	case AUTO_GREEN:
		if(timer2Flag == 1){
			traffic_light_remain_time_col--;
			if(traffic_light_remain_time_col == 0){
				FSM_Traffic_Light_State_Col = AUTO_YEL;
				traffic_light_remain_time_col = yellow_time;
			}
			setTimer2(TIMER1_SECOND_DURATION * TICK);
		}
		break;
	case AUTO_YEL:
		if(timer2Flag == 1){
			traffic_light_remain_time_col--;
			if(traffic_light_remain_time_col == 0){
				FSM_Traffic_Light_State_Col = AUTO_RED;
				traffic_light_remain_time_col = red_time;
			}
			setTimer2(TIMER1_SECOND_DURATION * TICK);
		}
		break;
	case BLACK_HOLE:
		/* This is trap state to force Col stop */
		if(To_Default_State == 1){
			To_Default_State = 0;
			FSM_Traffic_Light_State_Col = AUTO_GREEN;
			traffic_light_remain_time_col = green_time;
			setTimer2(TIMER1_SECOND_DURATION * TICK);
		}
		break;
	default:
		FSM_Traffic_Light_State_Col = AUTO_GREEN;
	}
}
