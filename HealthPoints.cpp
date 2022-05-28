//
// Created by User on 20/05/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(int max_hp) : m_healthPoints(max_hp), m_maxHealthPoints(max_hp)
{
    if(max_hp <= DEFAULT_MIN_HP){
        throw InvalidArgument();
    }
}

HealthPoints HealthPoints::operator-(int healthPointsChange)
{
    HealthPoints result(*this);
    return (result -= healthPointsChange);
}

HealthPoints operator+(const HealthPoints& healthPoints1, int healthPointsChange)
{
    HealthPoints result(healthPoints1);
    return (result += healthPointsChange);
}

HealthPoints operator+(int healthPointsChange, const HealthPoints& healthPoints1)
{
    return (healthPoints1 + healthPointsChange);
}

HealthPoints& HealthPoints::operator-=(int healthPointsChange)
{
    m_healthPoints -= healthPointsChange;
    if (m_healthPoints<DEFAULT_MIN_HP){
        m_healthPoints = DEFAULT_MIN_HP;
    }
    return *this;
}

HealthPoints& HealthPoints::operator+=(int healthPointsChange)
{
    m_healthPoints += healthPointsChange;
    if (m_healthPoints>m_maxHealthPoints){
        m_healthPoints = m_maxHealthPoints;
    }
    return *this;
}

bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return ((healthPoints1 >= healthPoints2) && (healthPoints1 <= healthPoints2));
}

bool operator==(int numberOfHealthPoints, const HealthPoints& healthPoints2)
{
    HealthPoints healthPoints1(numberOfHealthPoints);
    return healthPoints1 == healthPoints2;
}

bool operator==(const HealthPoints& healthPoints2, int numberOfHealthPoints)
{
    return (numberOfHealthPoints == healthPoints2);
}

bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_healthPoints < healthPoints2.m_healthPoints;
}

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1==healthPoints2);
}

bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints2 < healthPoints1);
}

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints2 < healthPoints1;
}

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints2 <= healthPoints1;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints &healthPoints)
{
    os << healthPoints.m_healthPoints;
    os << "(";
    os << healthPoints.m_maxHealthPoints;
    os << ")";

    return os;
}



