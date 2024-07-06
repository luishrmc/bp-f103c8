/**
 * @file sensorCtrl.c
 * @author Luis Maciel (luishenrique.8804@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 *
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "TF1012Srvc.h"

void vDistSensor(void *pvParameters)
{
    tfsInit();
    uint16_t distance;
    while (1)
    {
        tfsGetDist();
        vTaskDelay(pdMS_TO_TICKS(300));
    }
}