//
// Created by adamleon on 13.09.2024.
//

#include "ais1104/motor.h"

#include <ostream>

void Motor::update() {
    Module::update();

    const double di_dt = ((voltage - (resistance * current) - (k_emf * angular_velocity))/inductance) * getDeltaTime();
    const double domega_dt = ((k_torque * current) - (damping * angular_velocity) / inertia ) * getDeltaTime();

    current += di_dt;
    angular_velocity += domega_dt;
    angle += angular_velocity;
}

void Motor::attach(const std::shared_ptr<Wheel>& wheel) {
    if(!wheel) { return; }
    inertia = wheel->getInertia();
    wheel->setMotor(shared_from_this());
}
