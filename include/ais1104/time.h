#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <cmath>

/**
 * @class Time
 * @brief Represents a time measurement utility.
 *
 * The Time class provides functionality to measure time in milliseconds, seconds, minutes, and hours.
 * It also provides a method to convert the time measurement into a string representation.
 */
class Time {
private:
    double totalSeconds; /**< The total number of milliseconds elapsed. */
    double deltaTime; /**< The time difference between updates. */
public:
    static void Init(double deltaTime);

    static Time Instance();
    /**
     * @brief Constructs a Time object with the specified time difference between updates.
     * @param deltaTime The time difference between updates in milliseconds.
     *
     * If the Time class has not been initialized, the deltaTime value is set and the totalMiliseconds
     * and isInitialized variables are initialized.
     */
    Time(double deltaTime) {
        this->deltaTime = deltaTime;
        this->totalSeconds = 0;
    }

    /**
     * @brief Updates the total number of milliseconds elapsed.
     *
     * This method should be called periodically to update the total number of milliseconds elapsed.
     * It adds the deltaTime value to the totalMiliseconds variable.
     */
    void update() {
        totalSeconds += deltaTime;
    }

    /**
     * @brief Gets the total number of milliseconds elapsed.
     * @return The total number of milliseconds elapsed.
     */
    double getMilliseconds() {
        return totalSeconds / 1000;
    }

    /**
     * @brief Gets the total number of seconds elapsed.
     * @return The total number of seconds elapsed.
     */
    double getSeconds() {
        return totalSeconds; // number of seconds elapsed.
    }
    /**
     * @brief Gets the total number of minutes elapsed.
     * @return The total number of minutes elapsed.
     */
    double getMinutes() {
        return totalSeconds / 60;
    }

    /**
     * @brief Gets the total number of hours elapsed.
     * @return The total number of hours elapsed.
     */
    double getHours() {
        return totalSeconds / 3600;
    }

    double getDeltaTime() {
      return deltaTime;
    }

    /**
     * @brief Converts the time measurement into a string representation.
     * @return The string representation of the time measurement.
     *
     * The string representation is in the format "hh h mm m ss s ms", where hh represents hours,
     * mm represents minutes, ss represents seconds, and ms represents milliseconds.
     */
    std::string toString() {
        std::string result = "";
        result += std::to_string(getHours()) + "h ";
        result += std::to_string(std::fmod(getMinutes(), 60)) + "m ";
        result += std::to_string(std::fmod(getSeconds(), 60)) + "s ";
        result += std::to_string(std::fmod(getMilliseconds(),1000)) + "ms";
        return result;
    }
};


#endif // TIME_HPP
