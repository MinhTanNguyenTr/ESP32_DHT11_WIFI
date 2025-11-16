#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "dht11.h"
#include "ISensor_Interface.h"
#include "../sensor_manager/SensorManager.h"
#include "freertos/projdefs.h"
#include "soc/gpio_num.h"

extern "C" void app_main(void)
{
    SensorManager sm;

    auto* dht = new DHT11(GPIO_NUM_17);
    sm.addSensor(dht);

    while (true) {
        sm.readAll();
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
