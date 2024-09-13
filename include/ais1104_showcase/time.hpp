#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>

/**
 * @class Time
 * @brief Represents a time measurement utility.
 *
 * The Time class provides functionality to measure time in milliseconds, seconds, minutes, and hours.
 * It also provides a method to convert the time measurement into a string representation.
 */
class Time {
private:
    static long long totalMiliseconds; /**< The total number of milliseconds elapsed. */
    static bool isInitialized; /**< Flag indicating whether the Time class has been initialized. */
    static long long deltaTime; /**< The time difference between updates. */
public:
    /**
     * @brief Constructs a Time object with the specified time difference between updates.
     * @param deltaTime The time difference between updates in milliseconds.
     *
     * If the Time class has not been initialized, the deltaTime value is set and the totalMiliseconds
     * and isInitialized variables are initialized.
     */
    Time(long long deltaTime) {
        if (!isInitialized) {
            deltaTime = deltaTime;
            totalMiliseconds = 0;
            isInitialized = true;
        }
    }

    /**
     * @brief Updates the total number of milliseconds elapsed.
     *
     * This method should be called periodically to update the total number of milliseconds elapsed.
     * It adds the deltaTime value to the totalMiliseconds variable.
     */
    void update() {
        totalMiliseconds += deltaTime;
    }

    /**
     * @brief Gets the total number of milliseconds elapsed.
     * @return The total number of milliseconds elapsed.
     */
    long long getMiliseconds() {
        return totalMiliseconds;
    }

    /**
     * @brief Gets the total number of seconds elapsed.
     * @return The total number of seconds elapsed.
     */
    long long getSeconds() {
        return totalMiliseconds / 1000;
    }

    /**
     * @brief Gets the total number of minutes elapsed.
     * @return The total number of minutes elapsed.
     */
    long long getMinutes() {
        return totalMiliseconds / 60000;
    }

    /**
     * @brief Gets the total number of hours elapsed.
     * @return The total number of hours elapsed.
     */
    long long getHours() {
        return totalMiliseconds / 3600000;
    }

    /**
     * @brief Converts the time measurement into a string representation.
     * @return The string representation of the time measurement.
     *
     * The string representation is in the format "hh h mm m ss s ms ms", where hh represents hours,
     * mm represents minutes, ss represents seconds, and ms represents milliseconds.
     */
    std::string toString() {
        std::string result = "";
        result += std::to_string(getHours()) + "h ";
        result += std::to_string(getMinutes() % 60) + "m ";
        result += std::to_string(getSeconds() % 60) + "s ";
        result += std::to_string(getMiliseconds() % 1000) + "ms";
        return result;
    }
};

#endif // TIME_HPP