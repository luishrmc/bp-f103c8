/**
 * @file tf10120Service.c
 * @author Luis Maciel (luishenrique.8804@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "TF1012Srvc.h"
#include "usartDrv.h"
#include "concatNum.h"
#include <stdio.h>

usartDrv_t disSensor;

void tfsInit(void)
{
    udInit(&disSensor, UART1);
}

void tfsSet(setCommands_t cmd, uint16_t data)
{
    char str[8];
    sprintf(str, "%d", data);

    enqueue(&disSensor.tx, 's');
    if (cmd == sPOS_DEV)
    {
        enqueue(&disSensor.tx, (cmd + 48));
        enqueue(&disSensor.tx, '+');
    }
    else
    {
        enqueue(&disSensor.tx, (cmd + 47));
        enqueue(&disSensor.tx, '-');
    }

    for (uint8_t i = 0; str[i] != '\0'; i++)
    {
        enqueue(&disSensor.tx, str[i]);
    }
    enqueue(&disSensor.tx, '#');

    while (udTx(&disSensor))
    {
    }
}

uint16_t tfsRead(readCommands_t cmd)
{
    enqueue(&disSensor.tx, 'r');
    enqueue(&disSensor.tx, (cmd + 48));
    enqueue(&disSensor.tx, '#');

    while (udTx(&disSensor))
    {
    }
}

uint16_t tfsGetDist(void)
{
    char strDist[8];
    uint16_t dist = 0;
    uint16_t tempDist[2];
    uint8_t data;
    int8_t flag = -1;

    while (udRx(&disSensor, &data))
    {
        if (flag >= 0)
        {
            if (data != 'm')
            {
                if (dist == 0)
                {
                    dist = data - 0x30;
                    strDist[flag++] = data;
                }
                else
                {
                    tempDist[0] = dist;
                    tempDist[1] = data - 0x30;
                    dist = concatenateNumbers(tempDist[0], tempDist[1]);
                    strDist[flag++] = data;
                }
            }
            else
            {
                flag = -1;
                printf("%s\n", strDist);
                return dist;
            }
        }
        else
        {
            if (data == '\n')
            {
                flag = 0;
            }
        }
    }
}