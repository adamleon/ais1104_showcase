//
// Created by adamleon on 13.09.2024.
//

#ifndef MOTOR_H
#define MOTOR_H

#include "ais1104/module.h"


class Motor : public Module {
public:
    Motor(Time time, const std::string &name) : Module(time, name) {

    }

    void update() override;

private:
    double voltage;
    double current;
    double resistance;
    double inductance;
};


#endif //MOTOR_H
