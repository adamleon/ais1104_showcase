//
// Created by adamk on 18.09.2024.
//

#ifndef WHEEL_H
#define WHEEL_H


#include "module.h"


class Wheel final : Module {
public:
    Wheel(const std::string& name, const double diameter, const double inertia) : Module(name), diameter(diameter), inertia(inertia) {}

    void update() override;

    [[nodiscard]] constexpr double getDiameter() const { return diameter; }
    [[nodiscard]] constexpr double getRadius() const { return diameter / 2; }
    [[nodiscard]] constexpr double travelledDistance() const { return diameter * angle; }
    [[nodiscard]] constexpr double getInertia() const { return inertia; }
    [[nodiscard]] constexpr double getAngle() const { return angle; }
    [[nodiscard]] constexpr  double getAcceleration() const { return angular_acceleration; }
private:
    double diameter;
    double velocity{};
    double acceleration{};
    double angle{};
    double angular_velocity{};
    double angular_acceleration{};
    double inertia;
};



#endif //WHEEL_H
