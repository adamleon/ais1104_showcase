#include <iostream>
#include "ais1104/time.hpp"


int main() {
    Time time(100);
    std::cout << "Starting simulator\n";

    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < 10; i++) {
            time.update();
        }
        std::cout << "Time elapsed: " << time.toString() << "\n";
    }
    
    std::cout << "End simulator\n";
    
    return 0;
}