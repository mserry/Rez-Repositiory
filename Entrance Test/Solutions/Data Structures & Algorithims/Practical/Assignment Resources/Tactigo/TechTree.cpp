// TechTree.cpp
#include "TechTree.h"
#include "TechTreeBase/Tech.h"
#include <iostream>

//---------------------------------------------------------------------------------------------------------------------
// This function finds the best path to the tech we want.
//      * goalTech: The index of the tech we're looking for.  Call GetTechByIndex() to get the actual Tech instance.
//      * bestPath: The best path to the goal tech.  This is an array sorted in the order of the best path from the 
//                  start to the goal.  This is an output variable; it's what you need to populate with this function.
//---------------------------------------------------------------------------------------------------------------------
void TechTree::FindBestPath(int goalTech, Path& bestPath)
{
	const Tech* targetTech = GetTechByIndex(goalTech);
	std::string techName = targetTech->GetTechName();

	
}

//Step 1: Identify Search Starting Point (Existing Techs, Closest base tech).
//Step 2: Searching Algorithim (Best First Search / Greedy First Search, search from closest start point to find cheapest cost path to the target tech).

//Identifiying starting point:
// -> the best path takes two heurstics into it's account (our existing techs & the cheapest costs)
// -> optimially it starts from our purchases techs if the existing techs: have a way to reach our goal.