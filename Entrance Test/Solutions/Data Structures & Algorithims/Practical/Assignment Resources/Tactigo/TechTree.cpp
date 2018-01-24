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
	auto targetTech = GetTechByIndex(goalTech);
	
	//
}
