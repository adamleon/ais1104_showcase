//
// Created by adamleon on 13.09.2024.
//

#ifndef MOTOR_H
#define MOTOR_H

#include "ais1104/wheel.h"
#include "ais1104/module.h"

class Wheel;

class Motor : public std::enable_shared_from_this<Motor>, public Module {
public:
    Motor(
        const std::string &name,
        const double voltage,
        const double current,
        const double resistance,
        const double inductance)
    : Module(name), voltage(voltage), current(current), resistance(resistance), inductance(inductance) {
    }

    explicit Motor(const std::string &name) : Motor(name, 0, 0, 0, 0) {}

    void applyVoltage(const double voltage) {
        this->voltage = voltage;
    }

    void update() override;

    double getAngle() const { return angle; };
    double getAngularVelocity() const { return angular_velocity; }

    void attach(const std::shared_ptr<Wheel>& wheel);

private:
    double voltage;
    double current;
    double resistance;
    double inductance;
    double k_emf = 0.01;
    double k_torque = 0.01;
    double angular_velocity = 0;
    double angle = 0;
    double damping = 0.001;
    double inertia = 0.01;
};


#endif //MOTOR_H
