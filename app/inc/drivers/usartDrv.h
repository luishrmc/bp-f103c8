/**
 * @file usartDrv.h
 * @author luis (luishenrique.8804@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "stdint.h"
#include "queue.h"

typedef enum
{
    UART1,
    UART2,
    UART3
} uInst;

typedef struct
{
    uInst inst;
    uint8_t rxData;
    Queue rx;
    Queue tx;
} usartDrv_t;

void udInit(usartDrv_t *self, uInst instance);
uint8_t udTx(usartDrv_t *self);
uint8_t udRx(usartDrv_t *self, uint8_t *data);
