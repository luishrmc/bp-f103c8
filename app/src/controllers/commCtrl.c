/**
 * @file commCtrl.c
 * @author your name (you@domain.com)
 * @brief
 * @version 1.0
 * @date 2024-07-07
 *
 * @copyright Copyright (c) 2024
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "commCtrl.h"
#include <string.h>
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define START_BYTE '#'
#define END_BYTE '$'

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
comm_t comm;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

void commCtrlRunUSART(void)
{
    while (dequeue(&comm.u1.rxQueue, &comm.cmd[comm.idx]))
    {
        if (comm.idx > 0)
        {
            if (comm.cmd[comm.idx] == END_BYTE)
            {
                commCtrlCmdUSART(&comm, comm.cmd[1], &comm.cmd[2]);
                memset(&comm.cmd, 0, sizeof(comm.cmd));
                comm.idx = 0;
            }
            else
            {
                comm.idx++;
            }
        }
        else if (comm.cmd[comm.idx] == START_BYTE)
        {
            comm.idx++;
            continue;
        }
    }
}

void commCtrlCmdUSART(comm_t *self, opCode_t cmd, uint8_t *data)
{
    switch (cmd)
    {
    case CMD_PING:
    {
        self->u1.txBuff[0] = START_BYTE;
        self->u1.txBuff[1] = CMD_PONG;
        self->u1.txBuff[2] = END_BYTE;
        self->u1.txSize = 3;
        // udTxBlck(&self->u1);
        udTxIT(&self->u1);
        printf("PONG\n");
        break;
    }

    case CMD_PONG:
    {
        self->u1.txBuff[0] = START_BYTE;
        self->u1.txBuff[1] = CMD_PING;
        self->u1.txBuff[2] = END_BYTE;
        self->u1.txSize = 3;
        // udTxBlck(&self->u1);
        udTxIT(&self->u1);
        break;
    }

    default:
        break;
    }
}

void commCtrlRunSPI(void)
{
    while (dequeue(&comm.s2.rxQueue, &comm.cmd[comm.idx]))
    {
        if (comm.idx > 0)
        {
            if (comm.cmd[comm.idx] == END_BYTE)
            {
                commCtrlCmdSPI(&comm, comm.cmd[1], &comm.cmd[2]);
                memset(&comm.cmd, 0, sizeof(comm.cmd));
                comm.idx = 0;
            }
            else
            {
                comm.idx++;
            }
        }
        else if (comm.cmd[comm.idx] == START_BYTE)
        {
            comm.idx++;
            continue;
        }
    }
}

void commCtrlCmdSPI(comm_t *self, opCode_t cmd, uint8_t *data)
{
    switch (cmd)
    {
    case CMD_PING:
    {
        self->s2.txBuff[0] = START_BYTE;
        self->s2.txBuff[1] = CMD_PONG;
        self->s2.txBuff[2] = END_BYTE;
        self->s2.txSize = 3;
        printf("PONG\n");
        sdOutBlck(&self->s2);
        // sdOutIT(&self->s2);
        break;
    }

    case CMD_PONG:
    {
        self->s2.txBuff[0] = START_BYTE;
        self->s2.txBuff[1] = CMD_PING;
        self->s2.txBuff[2] = END_BYTE;
        self->s2.txSize = 3;
        printf("PING\n");
        sdOutBlck(&self->s2);
        // sdOutIT(&self->s2);
        break;
    }

    default:
        break;
    }
}

void commCtrlInit(void)
{
    memset(&comm, 0, sizeof(comm_t));
    // udInit(&comm.u1, DRV_USART1);
    sdInit(&comm.s2, DRV_SPI2);

    // comm.s2.txBuff[0] = START_BYTE;
    // comm.s2.txBuff[1] = CMD_PING;
    // comm.s2.txBuff[2] = END_BYTE;
    // comm.s2.txSize = 3;
    // comm.s2.rxSize = 3;
    // sdOutIT(&comm.s2);
}
