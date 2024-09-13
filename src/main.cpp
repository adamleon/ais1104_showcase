#include <iostream>
#include "ais1104/time.h"
#include "ais1104/motor.h"


int main() {
    Time time(100);

    Motor motor(time, "Motor");
    motor.init();
    std::cout << "Starting simulator\n";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            motor.update();
            time.update();
        }
        std::cout << "Time elapsed: " << time.toString() << "\n";
    }
    
    std::cout << "End simulator\n";
    
    return 0;
}