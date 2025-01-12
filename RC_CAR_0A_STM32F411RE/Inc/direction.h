/*
 * direction.h
 *
 *  Created on: Jan 11, 2025
 *      Author: Dora
 */

#ifndef INC_DIRECTION_H_
#define INC_DIRECTION_H_

#include "def.h"


typedef struct
{
 GPIO_TypeDef   *port;
 uint16_t       number;
 uint8_t        state;
}DIRECTION;


typedef enum
{
  STOP,
  FORWARD,
  BACKWORD,
  LEFT,
  RIGHT
}STATE;


void directionState(uint8_t ch);


#endif /* INC_DIRECTION_H_ */
