/*
 * joystick.c
 *
 *  Created on: Jan 13, 2025
 *      Author: Dora
 */


#include "joystick.h"

extern uint16_t XY[4];
extern uint8_t reSizeXY[4];
extern uint8_t txData[8];



void joysticXY_resize()
{
  for(uint8_t i = 0; i < 4; i++)
  {
    if(XY[i] > 1500 && XY[i] < 2500)         // N
    {
      reSizeXY[i] = '0';
    }
    else
    {
      if(XY[i] >= 4000)                     // D4
      {
        reSizeXY[i] = '4';
      }
      else if(XY[i] >= 3500 && XY[i] < 4000) // D2
      {
        reSizeXY[i] = '3';
      }
      else if(XY[i] >= 3000 && XY[i] < 3500) // D2
      {
        reSizeXY[i] = '2';
      }
      else if(XY[i] >= 2500 && XY[i] < 3000) // D1
      {
        reSizeXY[i] = '1';
      }
      else if(XY[i] <= 96)                  // R4 - R = D + 5
      {
        reSizeXY[i] = '9';
      }
      else if(XY[i] >= 96 && XY[i] < 500)    // R3
      {
        reSizeXY[i] = '8';
      }
      else if(XY[i] >= 500 && XY[i] < 1000)  // D2
      {
        reSizeXY[i] = '7';
      }
      else if(XY[i] >= 1000 && XY[i] < 1500) // R1
      {
        reSizeXY[i] = '6';
      }
    }

    txData[0] = reSizeXY[0];
    txData[1] = reSizeXY[1];
    txData[2] = reSizeXY[2];
    txData[3] = reSizeXY[3];

  }



  // The division operation shows very serious performance degradation.
//  for(uint8_t i = 0; i < 4; i++)
//  {
//    uint16_t XYTemp = XY[i];
//    txData[i] = (XYTemp / 500);        // 4090 / 500 = 8, 96 == DeadZone
//  }
}


void btnStatus()
{
  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2))
  {
    txData[4] = 1;
  }
  else
  {
    txData[4] = 0;
  }

  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
  {
    txData[5] = 1;
  }
  else
  {
    txData[5] = 0;
  }

  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4))
  {
    txData[6] = 1;
  }
  else
  {
    txData[6] = 0;
  }

  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7))
  {
    txData[7] = 1;
  }
  else
  {
    txData[7] = 0;
  }

//  btnState[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
//  btnState[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
//  btnState[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
//  btnState[3] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
}

