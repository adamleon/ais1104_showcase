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

    /**
     * @brief Constructs a Time object with the specified time difference between updates.    static void Init(double deltaTime);
     * @param deltaTime The time difference between updates in milliseconds.
     *    static Time Instance();
     * If the Time class has not been initialized, the deltaTime value is set and the totalMilliseconds
     * and isInitialized variables are initialized.
     */
    explicit Time(double deltaTime) {
        this->deltaTime = deltaTime;
        this->totalSeconds = -1;
    }

public:

    static void Time::Init(double deltaTime);

    static Time Time::Instance();

    /** @brief Updates the total number of seconds elapse
     * This method should be called periodically to update the total number of seconds elapsed.
     * It adds the deltaTime value to the totalSeconds variable.
     */
    void update() {
        totalSeconds += deltaTime;
    }

    /**
     * @brief Gets the total number of milliseconds elapsed.
     * @return The total number of milliseconds elapsed.
     */
    [[nodiscard]] double getMilliseconds() const {
        return totalSeconds / 1000;
    }

    /**
     * @brief Gets the total number of seconds elapsed.
     * @return The total number of seconds elapsed.
     */
    [[nodiscard]] double getSeconds() const {
        return totalSeconds; // number of seconds elapsed.
    }
    /**
     * @brief Gets the total number of minutes elapsed.
     * @return The total number of minutes elapsed.
     */
    [[nodiscard]] double getMinutes() const {
        return totalSeconds / 60;
    }

    /**
     * @brief Gets the total number of hours elapsed.
     * @return The total number of hours elapsed.
     */
    [[nodiscard]] double getHours() const {
        return totalSeconds / 3600;
    }

    [[nodiscard]] double getDeltaTime() const {
      return deltaTime;
    }

    /**
     * @brief Converts the time measurement into a string representation.
     * @return The string representation of the time measurement.
     *
     * The string representation is in the format "hh h mm m ss s ms", where hh represents hours,
     * mm represents minutes, ss represents seconds, and ms represents milliseconds.
     */
    [[nodiscard]] std::string toString() const {
        std::string result;
        result += std::to_string(getHours()) + "h ";
        result += std::to_string(std::fmod(getMinutes(), 60)) + "m ";
        result += std::to_string(std::fmod(getSeconds(), 60)) + "s ";
        result += std::to_string(std::fmod(getMilliseconds(),1000)) + "ms";
        return result;
    }












};


#endif // TIME_HPP
