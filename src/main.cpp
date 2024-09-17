#include <iostream>
#include "ais1104/time.h"
#include "ais1104/motor.h"


int main() {
    Time time(0.1);

    Motor motor(time, "Motor", 5, 0, 1, 0.5);
    motor.init();
    std::cout << "Starting simulator\n";

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            motor.update();
            time.update();
            std::cout << "Motor velocity: " << motor.getAngularVelocity() << "\n";
        }
        std::cout << "Time elapsed: " << time.toString() << "\n";
    }
    
    std::cout << "End simulator\n";
    
    return 0;
}