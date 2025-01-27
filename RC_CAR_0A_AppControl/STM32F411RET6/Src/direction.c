/*
 * direction.c
 *
 *  Created on: Jan 11, 2025
 *      Author: Dora
 */


#include "direction.h"


DIRECTION motor[4] =
    {
        {GPIOA, GPIO_PIN_8 ,0},
        {GPIOB, GPIO_PIN_10 ,0},
        {GPIOB, GPIO_PIN_4 ,0},
        {GPIOB, GPIO_PIN_5 ,0},
    };


void directionState(uint8_t direction_state)
{
  switch(direction_state)
  {
    case STOP:
      HAL_GPIO_WritePin(motor[0].port, motor[0].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[1].port, motor[1].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[2].port, motor[2].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[3].port, motor[3].number, GPIO_PIN_RESET);
      break;

    case FORWARD:
      HAL_GPIO_WritePin(motor[0].port, motor[0].number, GPIO_PIN_SET);
      HAL_GPIO_WritePin(motor[1].port, motor[1].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[2].port, motor[2].number, GPIO_PIN_SET);
      HAL_GPIO_WritePin(motor[3].port, motor[3].number, GPIO_PIN_RESET);
      break;

    case BACKWORD:
      HAL_GPIO_WritePin(motor[0].port, motor[0].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[1].port, motor[1].number, GPIO_PIN_SET);
      HAL_GPIO_WritePin(motor[2].port, motor[2].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[3].port, motor[3].number, GPIO_PIN_SET);
      break;

    case LEFT:
      HAL_GPIO_WritePin(motor[0].port, motor[0].number, GPIO_PIN_SET);
      HAL_GPIO_WritePin(motor[1].port, motor[1].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[2].port, motor[2].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[3].port, motor[3].number, GPIO_PIN_SET);
      break;

    case RIGHT:
      HAL_GPIO_WritePin(motor[0].port, motor[0].number, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(motor[1].port, motor[1].number, GPIO_PIN_SET);
      HAL_GPIO_WritePin(motor[2].port, motor[2].number, GPIO_PIN_SET);
      HAL_GPIO_WritePin(motor[3].port, motor[3].number, GPIO_PIN_RESET);
      break;
  }
}


//void directionState(uint8_t directon_state)
//{
//  uint8_t ary[4];
//
//  switch(directon_state)
//  {
//    case STOP:
//      ary[0] = 0;
//      ary[1] = 0;
//      ary[2] = 0;
//      ary[3] = 0;
//      break;
//
//    case FORWARD:
//      ary[0] = 1;
//      ary[1] = 0;
//      ary[2] = 1;
//      ary[3] = 0;
//      break;
//
//    case BACKWORD:
//      ary[0] = 0;
//      ary[1] = 1;
//      ary[2] = 0;
//      ary[3] = 1;
//      break;
//
//    case LEFT:
//      ary[0] = 1;
//      ary[1] = 0;
//      ary[2] = 0;
//      ary[3] = 1;
//      break;
//
//    case RIGHT:
//      ary[0] = 0;
//      ary[1] = 1;
//      ary[2] = 1;
//      ary[3] = 0;
//      break;
//
//  }
//
//  for(uint8_t i = 0; i < 4; i++)
//  {
//    HAL_GPIO_WritePin(motor[i].port, motor[i].number, ary[i]);
//  }
//}

