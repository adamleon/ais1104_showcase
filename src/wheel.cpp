//
// Created by adamk on 18.09.2024.
//

#include "ais1104/wheel.h"

void Wheel::update() {
    angle += angular_velocity;
}
