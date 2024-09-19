#include <iostream>
#include "ais1104/time.h"
#include "ais1104/motor.h"
#include "ais1104/wheel.h"


int main() {
    Time::Init(0.1);

    Time time = Time::Instance();

    std::shared_ptr<Motor> motor = std::make_shared<Motor>("Motor", 5, 0, 1, 0.5);
    motor->init();
    std::shared_ptr<Wheel> wheel = std::make_shared<Wheel>("Wheel", 0.04, 0.03);
    wheel->init();
    motor->attach(wheel);

    std::cout << "Starting simulator\n";

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            motor->update();
            wheel->update();
            time.update();
            std::cout << "Motor velocity: " << motor->getAngularVelocity() << "\n";
            std::cout << "Travelled Distance: " << wheel->travelledDistance() << "\n";
        }
        std::cout << "Time elapsed: " << time.toString() << "\n";
    }
    
    std::cout << "End simulator\n";
    
    return 0;
}
