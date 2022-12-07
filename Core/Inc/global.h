/*
 * global.h
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"


//////////////BUTTON///////////////////
#define NO_OF_BUTTONS		4
uint16_t INPUT_BUTTON[NO_OF_BUTTONS];
uint8_t buttonPressed_flag[NO_OF_BUTTONS];

#define NORMAL_BUTTON 		0
#define PRESS_BUTTON 		1
#define LONG_PRESS_BUTTON 	2

//////////////FSM//////////////////////
int FSM_Button_State;
int FSM_Traffic_Light_State_Row;
int FSM_Traffic_Light_State_Col;
int FSM_Pedestrian_State;
#define AUTO_RED		0
#define AUTO_GREEN		1
#define AUTO_YEL		2
#define MANUAL_RED		3
#define MANUAL_GREEN 	4
#define MANUAL_YEL 		5
#define BLACK_HOLE		6
#define IDLE			0
#define WORK			1
////////////////Timer//////////////////
#define TICK	1
int timer1Counter;
int timer1Flag;
int timer2Counter;
int timer2Flag;
int timer3Counter;
int timer3Flag;
///////////////Light time////////////////

int red_time;
int green_time;
int yellow_time;

int traffic_light_remain_time_row;
int traffic_light_remain_time_col;

#define TIMER1_SECOND_DURATION 		100  // 1s
#define TIMER1_10SECOND_DURATION 	1000 // 10s
#define TIMER3_PEDESTRIAN_CYCLE 	1000 // 10s
int Set_TL_Time;
#endif /* INC_GLOBAL_H_ */
