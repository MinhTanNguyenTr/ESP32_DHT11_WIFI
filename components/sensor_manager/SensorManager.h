#ifndef COMPONENTS_SENSOR_MANAGER_H_
#define COMPONENTS_SENSOR_MANAGER_H_

#include <vector>
#include "../dht11/ISensor_Interface.h"

class SensorManager {
public:
    void addSensor(ISensor_Interface* s) {
        sensors.push_back(s);
    }

    void readAll();

private:
    std::vector<ISensor_Interface*> sensors;
};

#endif
