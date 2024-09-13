//
// Created by adamleon on 13.09.2024.
//

#ifndef MODULE_H
#define MODULE_H
#include <stdexcept>
#include <string>
#include <utility>
#include "ais1104/time.h"

class Module {
public:
    virtual ~Module() = default;

    Module(Time time, std::string name): time(time), name(std::move(name)) {}

    virtual  void init() {
        if(!isInitialized) isInitialized = true;
    };

    virtual  void update() {
        if(!isInitialized) throw std::runtime_error(this->name + " is not initialized");
    };

private:
    bool isInitialized = false;
    std::string name;
    Time time;
};

#endif //MODULE_H
