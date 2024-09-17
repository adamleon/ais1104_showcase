//
// Created by adamleon on 13.09.2024.
//

#ifndef MOTOR_H
#define MOTOR_H

#include "ais1104/module.h"


class Motor : public Module {
public:
    Motor(
        const Time time,
        const std::string &name,
        const double voltage,
        const double current,
        const double resistance,
        const double inductance)
    : Module(time, name), current(current), resistance(resistance), inductance(inductance), voltage(voltage) {
    }

    Motor(const Time time, const std::string &name) : Motor(time, name, 0, 0, 0, 0) {}

    void applyVoltage(const double voltage) {
        this->voltage = voltage;
    }

    void update() override;

    double getAngle() const { return angle; };
    double getAngularVelocity() const { return angular_velocity; }

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
