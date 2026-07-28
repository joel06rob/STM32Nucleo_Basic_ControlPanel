#include <string.h>
#include <stdio.h>
#include "uart_manager.h"
#include "main.h"

//extern: don't redefine the global variable (don't reallocate memory)
extern UART_HandleTypeDef huart2;

const char *commandList[] = {
		"Control Panel Commands:\r\n",
		"----------------------\r\n",
		"help\r\n",
		"m1\r\n",
		"m2\r\n",
		"m3\r\n"
};

void UART_Manager_DisplayMode(char *modebuffer){

	//Note: UART Type, buffer loc, length of data, delay
	HAL_UART_Transmit(&huart2, (uint8_t *)modebuffer, strlen(modebuffer), HAL_MAX_DELAY);

}

void UART_Manager_DisplayCommands(){

	//Display all commands
	uint8_t numofcommandList = sizeof(commandList)/sizeof(commandList[0]);

	for(uint8_t i = 0; i < numofcommandList; i++){

		HAL_UART_Transmit(&huart2, (uint8_t *)commandList[i], strlen(commandList[i]), HAL_MAX_DELAY);

	}



}
