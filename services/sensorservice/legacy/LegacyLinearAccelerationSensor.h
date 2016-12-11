/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_LEGACY_LINEAR_ACCELERATION_SENSOR_H
#define ANDROID_LEGACY_LINEAR_ACCELERATION_SENSOR_H

#include <stdint.h>
#include <sys/types.h>

#include <gui/Sensor.h>

#include "../SensorInterface.h"
#include "LegacyGravitySensor.h"

// ---------------------------------------------------------------------------
namespace android {
// ---------------------------------------------------------------------------

class SensorDevice;
class SensorFusion;

class LegacyLinearAccelerationSensor : public VirtualSensor {
    LegacyGravitySensor mGravitySensor;
    float mData[3];

    virtual bool process(sensors_event_t* outEvent,
            const sensors_event_t& event);
public:
    LegacyLinearAccelerationSensor(sensor_t const* list, size_t count);
    virtual status_t activate(void* ident, bool enabled) override;
    virtual status_t setDelay(void* ident, int handle, int64_t ns) override;
};

// ---------------------------------------------------------------------------
}; // namespace android

#endif // ANDROID_LEGACY_LINEAR_ACCELERATION_SENSOR_H
