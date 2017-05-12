// Tech.cpp
#include "Tech.h"

Tech::Tech(const std::string& techName, int cost)
    : m_techName(techName)
    , m_cost(cost)
{
    //
}

void Tech::AddUnlock(Tech* pTech)
{
    m_unlocks.push_back(pTech);
}

void Tech::LearnTech()
{
    m_hasTech = true;
}
