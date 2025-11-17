#pragma once
#include "esp_bt.h"
#include "esp_gap_bt_api.h"
#include "esp_bt_main.h"
#include "esp_spp_api.h"
#include "esp_log.h"

class BluetoothManager {
public:
    BluetoothManager(const char* deviceName);

    bool init();
    void sendMessage(const char* msg);
    void onData(void (*callback)(const char* data)); // optional

private:
    static void sppCallback(esp_spp_cb_event_t event, esp_spp_cb_param_t* param);

private:
    const char* m_deviceName;
    static inline int m_sppHandle = 0;
    static inline void (*m_userCallback)(const char*) = nullptr;
};
