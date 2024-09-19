//
// Created by adamk on 18.09.2024.
//

#include <utility>

#include "ais1104/wheel.h"

void Wheel::update() {
    if(motor) {
        angular_velocity = motor->getAngularVelocity();
    }

    angle += angular_velocity;
}

void Wheel::setMotor(std::shared_ptr<Motor> motor) {
    this->motor = std::move(motor);
}

