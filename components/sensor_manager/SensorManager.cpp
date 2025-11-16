#include "SensorManager.h"
#include "esp_log.h"

static const char* TAG = "SensorManager";

void SensorManager::readAll() {
    for (auto& s : sensors) {
        if (s->read()) {
            ESP_LOGI(TAG, "Temp = %.1f°C, Hum = %.1f%%",
                     s->getTemperature(),
                     s->getHumidity());
        } else {
            ESP_LOGW(TAG, "Failed to read sensor");
        }
    }
}
