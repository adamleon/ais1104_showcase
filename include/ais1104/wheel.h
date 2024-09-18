//
// Created by adamk on 18.09.2024.
//

#ifndef WHEEL_H
#define WHEEL_H


#include "module.h"


class Wheel : Module {
public:
    Wheel(const std::string& name, const double diameter, const double inertia) : Module(name), diameter(diameter), inertia(inertia) {}
private:
    double diameter;
    double velocity{};
    double acceleration{};
    double angle{};
    double angular_velocity{};
    double inertia;
};



#endif //WHEEL_H
