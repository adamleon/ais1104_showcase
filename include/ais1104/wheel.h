//
// Created by adamk on 18.09.2024.
//

#ifndef WHEEL_H
#define WHEEL_H

#include "ais1104/module.h"
#include "ais1104/motor.h"

class Motor;

class Wheel final : public Module {
public:
    Wheel(const std::string& name, const double diameter, const double inertia) : Module(name), diameter(diameter), inertia(inertia) {}

    void update() override;

    [[nodiscard]] constexpr double getDiameter() const { return diameter; }
    [[nodiscard]] constexpr double getRadius() const { return diameter / 2; }
    [[nodiscard]] constexpr double travelledDistance() const { return diameter * angle; }
    [[nodiscard]] constexpr double getInertia() const { return inertia; }
    [[nodiscard]] constexpr double getAngle() const { return angle; }
    [[nodiscard]] constexpr double getAngularVelocity() const { return angular_velocity; }
    [[nodiscard]] constexpr  double getVelocity() const { return angular_velocity * getRadius(); }

    void setMotor(Motor* motor);

private:
    double diameter;
    double acceleration{};
    double angle{};
    double angular_velocity{};
    double inertia;
    Motor* motor = nullptr;
};

#endif //WHEEL_H
