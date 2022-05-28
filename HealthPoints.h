#ifndef EX3_MTM_HEALTHPOINTS_H
#define EX3_MTM_HEALTHPOINTS_H

#include <iostream>

class HealthPoints{
public:
    /**
     * C'tor of HealthPoints.
     * in case of negative or zero value, throw the exception HealthPoints::InvalidArgument
     * @param max_hp maximum value of hp points
     */
    HealthPoints(int max_hp = DEFAULT_MAX_HP);

    /**
     * Assignment operator of HealthPoints
     * @return
     */
    HealthPoints& operator=(const HealthPoints& healthPoints) = default;

    /**
     * Copy C'tor of HealthPoints class
     * @return
     */
    HealthPoints(const HealthPoints& healthPoints) = default;

    /**
     * D'tor of HealthPoints
     * @return
     */
    ~HealthPoints() = default;

    /**
     * the operator decreases the number of health points by healthPointsChange
     * until the minimum hp that defined(0)
     * @param healthPointsChange health points to subtract
     * @return a new updated HealthPoints object
     */
    HealthPoints operator-(int healthPointsChange);


    /**
     * the operator decreases the number of health points by healthPointsChange
     * until the minimum hp that defined(0)
     * @param healthPointsChange health points to subtract
     * @return the updated HealthPoints object
     */
    HealthPoints& operator-=(int healthPointsChange);

    /**
     * the operator increases the number of health points by healthPointsChange
     * until the maximum hp that defined
     * @param healthPointsChange health points to add
     * @return the updated HealthPoints object
     */
    HealthPoints& operator+=(int healthPointsChange);

    /**
     * Compare between two instances of HealthPoints class, by their current health points
     * @param healthPoints1  reference to an instance to compare
     * @param healthPoints2  reference to an instance to compare
     * @return true if healthPoints1 has less current health points than healthPoints2 ,
     * otherwise false
     */
    friend bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

    /**
     * printing operator in the foramt: <maxValue>(<currentValue)
     * @param healthPoints1
     * @return the ostream (to allow chaining)
     */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints1);

    class InvalidArgument {};

private:
    int m_healthPoints;
    int m_maxHealthPoints;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_MIN_HP = 0;
};

/**
 * Compare between a number and instances of HealthPoints class - they are equal only if their
 * current health points is equal.
 * @param numberOfHealthPoints number to compare
 * @param healthPoints reference to an instance to compare
 * @return true if healthPoints1 and healthPoints2 has the same current health points, otherwise false
 */
bool operator==(int numberOfHealthPoints, const HealthPoints& healthPoints2);

/**
 * Compare between instances of HealthPoints class and a number- they are equal only if their
 * current health points is equal.
 * @param numberOfHealthPoints number to compare
 * @param healthPoints reference to an instance to compare
 * @return true if healthPoints1 and healthPoints2 has the same current health points, otherwise false
 */
bool operator==(const HealthPoints& healthPoints2, int numberOfHealthPoints);

/**
 * Compare between two instances of HealthPoints class - they are equal only if their current
 * health points is equal.
 * @param healthPoints1 reference to an instance to compare
 * @param healthPoints2 reference to an instance to compare
 * @return true if healthPoints1 and healthPoints2 has the same current health points, otherwise false
 */
bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

/**
 * Compare between two instances of HealthPoints class, by their current health points
 * @param healthPoints1  reference to an instance to compare
 * @param healthPoints2  reference to an instance to compare
 * @return true if healthPoints1 has more current health points than healthPoints2 has the same ,
 * otherwise false
 */

/**
 * Compare between two instances of HealthPoints class, by their current health points
 * @param healthPoints1  reference to an instance to compare
 * @param healthPoints2  reference to an instance to compare
 * @return true if healthPoints1 has less or as healthPoints2 current health points,
 * otherwise false
 */
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

/**
 * Compare between two instances of HealthPoints class, by their current health points
 * @param healthPoints1  reference to an instance to compare
 * @param healthPoints2  reference to an instance to compare
 * @return true if healthPoints1 has more or as healthPoints2 current health points,
 * otherwise false
 */
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

//TODO: Try!!!
/**
     * the operator decreases healthPointsChange by the number of health points (in the instance of HealthPoints)
     * until the minimum hp that defined(0)
     * @param healthPointsChange health points to subtract from
     * @param healthPoints health points to subtract
     * @return a new updated HealthPoints object
     */
//HealthPoints operator-(int healthPointsChange, const HealthPoints& healthPoints);


/**
 * the operator increases the number of health points by healthPointsChange,
 * until the maximum hp that defined
 * @param healthPointsChange health points to add
 * receives HealthPoints in the left and int in the right
 * @return a new updated HealthPoints object
 */
HealthPoints operator+(const HealthPoints& healthPoints1, int healthPointsChange);


/**
 * the operator increases the number of health points by healthPointsChange,
 * until the maximum hp that defined
 * @param healthPointsChange health points to add
 * recieves int in the left and HealthPoints in the right
 * @return a new updated HealthPoints object
 */
HealthPoints operator+(int healthPointsChange, const HealthPoints& healthPoints1);

#endif //EX3_MTM_HEALTHPOINTS_H
