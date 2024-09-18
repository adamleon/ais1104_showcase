//
// Created by adamk on 18.09.2024.
//

#include "ais1104/wheel.h"

void Wheel::update() {
    if(motor) {
        angular_velocity = motor->getAngularVelocity();
    }

    angle += angular_velocity;
}

void Wheel::setMotor(Motor *motor) {
    this->motor = motor;
}

