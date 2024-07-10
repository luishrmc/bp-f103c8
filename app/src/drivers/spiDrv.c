/**
 * @file spiDrv.c
 * @author Luis Maciel (luishenrique.8804@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-08
 *
 * @copyright Copyright (c) 2024
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "mainCtrl.h"
#include "spiDrv.h"
#include <stdlib.h>
#include "stm32f1xx_hal.h"
#include "stm32f103xb.h"
#include <string.h>

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define SPI2_MOSI GPIO_PIN_15
#define SPI2_MISO GPIO_PIN_14
#define SPI2_CLK GPIO_PIN_13
#define SPI2_NSS1 GPIO_PIN_12
#define SPI2_PORT GPIOB

/* Private macro -------------------------------------------------------------*/
// declaração da macro OFFSETOF
#define OFFSETOF(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

// declaração da macro CONTAINER_OF
#define CONTAINER_OF(ptr, type, member) ({            \
 const __typeof( ((type *)0)->member ) *__mptr = (ptr);    \
 (type *)( (char *)__mptr - OFFSETOF(type,member) ); })

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;
sInst *sInst1;
sInst *sInst2;
/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

void sdInit(spiDrv_t *self, sInst instance)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    memset(self, 0, sizeof(spiDrv_t));
    initQueue(&self->rxQueue);
    self->inst = instance;
    sdDefConf(self);

    switch (instance)
    {

    case DRV_SPI2:
    {
        __HAL_RCC_SPI2_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI2_NSS1 | SPI2_CLK | SPI2_MOSI;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(SPI2_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI2_MISO;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(SPI2_PORT, &GPIO_InitStruct);

        hspi2.Instance = SPI2;
        hspi2.Init.Mode = SPI_MODE_SLAVE;
        hspi2.Init.Direction = SPI_DIRECTION_2LINES;
        hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
        hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
        hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
        hspi2.Init.NSS = SPI_NSS_HARD_INPUT;
        hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
        hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
        hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
        hspi2.Init.CRCPolynomial = 10;
        if (HAL_SPI_Init(&hspi2) != HAL_OK)
        {
            Error_Handler();
        }

        /* SPI2 interrupt Init */
        HAL_NVIC_SetPriority(SPI2_IRQn, 6, 0);
        HAL_NVIC_EnableIRQ(SPI2_IRQn);
        sInst2 = &self->inst;
        sdInIT(self);
        break;
    }

    default:
        break;
    }
}

void sdDefConf(spiDrv_t *self)
{
    self->txTimeout = HAL_MAX_DELAY;
    self->rxTimeout = HAL_MAX_DELAY;
    self->rxSize = 3;
    self->txSize = 3;
}

uint8_t sdInOut(spiDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_SPI2:
    {
        return HAL_SPI_TransmitReceive(&hspi2, self->txBuff, self->rxBuff, self->rxSize, self->rxTimeout);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

uint8_t sdInOutIT(spiDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_SPI2:
    {
        return HAL_SPI_TransmitReceive_IT(&hspi2, self->txBuff, self->rxBuff, self->rxSize);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

uint8_t sdInBlck(spiDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_SPI2:
    {
        return HAL_SPI_Receive(&hspi2, self->rxBuff, self->rxSize, self->rxTimeout);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

uint8_t sdInIT(spiDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_SPI2:
    {
        return HAL_SPI_Receive_IT(&hspi2, self->rxBuff, self->rxSize);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

uint8_t sdOutBlck(spiDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_SPI2:
    {
        return HAL_SPI_Transmit(&hspi2, self->txBuff, self->txSize, self->txTimeout);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

uint8_t sdOutIT(spiDrv_t *self)
{
    switch (self->inst)
    {
    case DRV_SPI2:
    {
        return HAL_SPI_Transmit_IT(&hspi2, self->txBuff, self->txSize);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

uint8_t sdNss(sNss_t slave)
{
    switch (slave)
    {

    case SLAVE1_SET:
    {
        HAL_GPIO_WritePin(SPI2_PORT, SPI2_NSS1, GPIO_PIN_SET);
        break;
    }

    case SLAVE1_RESET:
    {
        HAL_GPIO_WritePin(SPI2_PORT, SPI2_NSS1, GPIO_PIN_RESET);
        break;
    }

    default:
        return HAL_ERROR;
        break;
    }
    return HAL_OK;
}

/**
 * @brief  Tx Transfer completed callback.
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @retval None
 */
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(hspi);
}

/**
 * @brief  Rx Transfer completed callback.
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @retval None
 */
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(hspi);
    spiDrv_t *spi;
    if (hspi->Instance == SPI1)
    {
        spi = CONTAINER_OF(sInst1, spiDrv_t, inst);
        for (uint8_t idx = 0; idx < spi->rxSize; idx++)
            enqueue(&spi->rxQueue, spi->rxBuff[idx]);
    }
    else if (hspi->Instance == SPI2)
    {
        spi = CONTAINER_OF(sInst2, spiDrv_t, inst);
        for (uint8_t idx = 0; idx < spi->rxSize; idx++)
            enqueue(&spi->rxQueue, spi->rxBuff[idx]);
    }
    // sdInIT(spi);
}

/**
 * @brief  Tx and Rx Transfer completed callback.
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @retval None
 */
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(hspi);
}
