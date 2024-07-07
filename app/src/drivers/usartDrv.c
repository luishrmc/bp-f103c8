/**
 * @file uartDriver.c
 * @author luis (luishenrique.8804@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-07-07
 *
 * @copyright Copyright (c) 2024
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "mainCtrl.h"
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
// declaração da macro OFFSETOF
#define OFFSETOF(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

// declaração da macro CONTAINER_OF
#define CONTAINER_OF(ptr, type, member) ({            \
 const __typeof( ((type *)0)->member ) *__mptr = (ptr);    \
 (type *)( (char *)__mptr - OFFSETOF(type,member) ); })

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
uInst *uInst1;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

void udInit(usartDrv_t *self, uInst instance)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    memset(self, 0, sizeof(usartDrv_t));
    initQueue(&self->rxQueue);
    self->inst = instance;
    udDefConf(self);

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
        uInst1 = &self->inst;
        udRxIT(self);
        break;
    }

    default:
        break;
    }
}

void udDefConf(usartDrv_t *self)
{
    self->txTimeout = HAL_MAX_DELAY;
    self->rxTimeout = HAL_MAX_DELAY;
    self->rxSize = 1;
    self->txSize = 1;
}

uint8_t udRxIT(usartDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_USART1:
    {
        return HAL_UART_Receive_IT(&huart1, self->rxBuff, self->rxSize);
        break;
    }

    default:
        break;
    }
    return HAL_ERROR;
}

uint8_t udRxBlck(usartDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_USART1:
    {
        return HAL_UART_Receive(&huart1, self->rxBuff, self->rxSize, self->rxTimeout);
        break;
    }

    default:
        break;
    }
    return HAL_ERROR;
}

uint8_t udTxIT(usartDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_USART1:
    {
        return HAL_UART_Transmit_IT(&huart1, self->txBuff, self->txSize);
        break;
    }

    default:
        break;
    }
    return HAL_ERROR;
}

uint8_t udTxBlck(usartDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_USART1:
    {
        return HAL_UART_Transmit(&huart1, self->txBuff, self->txSize, self->txTimeout);
        break;
    }

    default:
        break;
    }
    return HAL_ERROR;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(huart);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(huart);
    usartDrv_t *uart;
    if (huart->Instance == USART1)
    {
        uart = CONTAINER_OF(uInst1, usartDrv_t, inst);
        for (uint8_t idx = 0; idx < uart->rxSize; idx++)
            enqueue(&uart->rxQueue, uart->rxBuff[idx]);
    }
    udRxIT(uart);
}
