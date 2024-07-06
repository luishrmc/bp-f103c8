/**
 * @file uartDriver.c
 * @author luis (luishenrique.8804@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-06
 *
 * @copyright Copyright (c) 2024
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "usartDrv.h"
#include <stdlib.h>
#include "stm32f1xx_hal.h"
#include "stm32f103xb.h"
#include <string.h>

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define USART1_RX GPIO_PIN_10
#define USART1_TX GPIO_PIN_9
#define USART1_PORT GPIOA

/* Private macro -------------------------------------------------------------*/
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({            \
 const __typeof( ((type *)0)->member ) *__mptr = (ptr);    \
 (type *)( (char *)__mptr - offsetof(type,member) ); })

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
uint8_t *uRxData1;

/* Private user code ---------------------------------------------------------*/

void udInit(usartDrv_t *self, uInst instance)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    memset(self, 0, sizeof(usartDrv_t));
    initQueue(&self->rx);
    initQueue(&self->tx);
    self->inst = instance;

    switch (instance)
    {
    case DRV_USART1:
    {
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitStruct.Pin = USART1_TX;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = USART1_RX;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        huart1.Instance = USART1;
        huart1.Init.BaudRate = 115200;
        huart1.Init.WordLength = UART_WORDLENGTH_8B;
        huart1.Init.StopBits = UART_STOPBITS_1;
        huart1.Init.Parity = UART_PARITY_NONE;
        huart1.Init.Mode = UART_MODE_TX_RX;
        huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
        huart1.Init.OverSampling = UART_OVERSAMPLING_16;
        if (HAL_UART_Init(&huart1) != HAL_OK)
        {
            Error_Handler();
        }

        HAL_NVIC_SetPriority(USART1_IRQn, 6, 0);
        HAL_NVIC_EnableIRQ(USART1_IRQn);

        uRxData1 = &self->rxData;
        HAL_UART_Receive_IT(&huart1, &self->rxData, 1);
        break;
    }

    default:
        break;
    }
}

uint8_t udTx(usartDrv_t *self)
{
    uint8_t data;
    switch (self->inst)
    {
    case DRV_USART1:
    {
        if (dequeue(&self->tx, &data))
            HAL_UART_Transmit(&huart1, (uint8_t *)&data, 1, 0xFFFF);
        else
            return 0;
        break;
    }

    default:
        break;
    }
    return 1;
}

uint8_t udRx(usartDrv_t *self, uint8_t *data)
{
    return dequeue(&self->rx, data);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(huart);
    usartDrv_t *uart;
    if (huart->Instance == USART1)
    {
        uart = container_of(uRxData1, usartDrv_t, rxData);
    }
    enqueue(&uart->rx, uart->rxData);
    HAL_UART_Receive_IT(huart, &uart->rxData, 1);
}