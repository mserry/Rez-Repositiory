// TechTreeBase.cpp
#include "TechTreeBase.h"
#include "Tech.h"
#include <iostream>

TechTreeBase::TechTreeBase()
{
    m_techs.reserve(13);

    // social
    m_techs.push_back(new Tech("Being Nice to People", 1));     // 0
    m_techs.push_back(new Tech("Making Friends", 6));           // 1
    m_techs.push_back(new Tech("Throwing Parties", 10));        // 2
    m_techs.push_back(new Tech("Being Nice to Animals", 5));    // 3

    // military
    m_techs.push_back(new Tech("Being a Dick to People", 10));      // 4
    m_techs.push_back(new Tech("Attack Animal Training", 5));       // 5
    m_techs.push_back(new Tech("Being a Dick to Animals", 2));      // 6
    m_techs.push_back(new Tech("Inhumane Animal Experiments", 10)); // 7

    // science
    m_techs.push_back(new Tech("Being Nice to Books", 5));          // 8
    m_techs.push_back(new Tech("Being Alone", 1));                  // 9
    m_techs.push_back(new Tech("Drug Experimentation", 4));         // 10
    m_techs.push_back(new Tech("Mysteries of the Human Mind", 15)); // 11
    m_techs.push_back(new Tech("Inhumane Human Experiments", 15));  // 12

    // link the social tree
    m_techs[0]->AddUnlock(m_techs[1]);
    m_techs[0]->AddUnlock(m_techs[2]);
    m_techs[0]->AddUnlock(m_techs[3]);
    m_techs[3]->AddUnlock(m_techs[5]);

    // link the military tree
    m_techs[4]->AddUnlock(m_techs[5]);
    m_techs[4]->AddUnlock(m_techs[6]);
    m_techs[6]->AddUnlock(m_techs[7]);

    // link the science tree
    m_techs[8]->AddUnlock(m_techs[9]);
    m_techs[9]->AddUnlock(m_techs[10]);
    m_techs[9]->AddUnlock(m_techs[11]);
    m_techs[10]->AddUnlock(m_techs[7]);
    m_techs[10]->AddUnlock(m_techs[12]);
    m_techs[11]->AddUnlock(m_techs[12]);
}

TechTreeBase::~TechTreeBase()
{
    for (Tech* pTech : m_techs)
    {
        delete pTech;
    }
}

void TechTreeBase::SetupForTest1()
{
    ResetTest();
}

void TechTreeBase::SetupForTest2()
{
    ResetTest();

    // we know military already, so shortest path to 5 should be through military
    m_techs[4]->LearnTech();
}

void TechTreeBase::ResetTest()
{
    for (Tech* pTech : m_techs)
    {
        pTech->m_hasTech = false;
    }
}

void TechTreeBase::PrintAllTechs()
{
    for (unsigned int i = 0; i < m_techs.size(); ++i)
    {
        std::cout << i << ") " << (i < 10 ? " " : "") << m_techs[i]->GetTechName() << "\n";
    }
}
