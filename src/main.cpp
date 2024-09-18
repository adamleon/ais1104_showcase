#include <iostream>
#include "ais1104/time.h"
#include "ais1104/motor.h"
#include "ais1104/wheel.h"


int main() {
    Time time(0.1);

    Motor motor("Motor", 5, 0, 1, 0.5);
    motor.init();
    Wheel wheel("Wheel", 0.04, 0.03);
    wheel.init();

    std::cout << "Starting simulator\n";

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            motor.update();
            time.update();
            std::cout << "Motor velocity: " << wheel.getAngularVelocity() << "\n";
        }
        std::cout << "Time elapsed: " << time.toString() << "\n";
    }
    
    std::cout << "End simulator\n";
    
    return 0;
}
