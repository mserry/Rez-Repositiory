#pragma once
#include "TechTreeBase/TechTreeBase.h"

//---------------------------------------------------------------------------------------------------------------------
// INSTRUCTIONS:
// 
// Important: Read ALL of these instructions.
// 
// You are working on a strategy game that has a rather complex tech tree.  You can see the tech tree in figure 15.1.
// The majority of the tree is defined in TechTreeBase.h and the techs themselves are in Tech.h, both of which reside 
// in the lib folder.  You are not allowed to touch these files in any way.  In fact, they aren't even technically 
// part of this project.  They are the header files for TechTreeBase.lib, which is statically linked in, which means 
// you couldn't make changes even if you wanted to.
// 
// Each tech has a name, a cost to buy that tech, a boolean saying whether or not the player has the tech already, 
// and a list of 0 to N techs that are available for purchase when the player buys this tech.
// 
// There are three categories of tech in Tactigo: Social, Military, and Science.  Each of the three starts with a 
// basic tech that the player must purchase before purchasing more advanced techs.  These basic techs are special 
// because they are always available for purchase.
// 
// Looking at figure 15.1, you will note that a few techs are unlocked by multiple techs.  Remember that techs are 
// unlocked as soon as ANY tech unlocks them.  In other words, you need either "Being Nice to Animals" OR "Being a 
// Dick to People" in order to buy "Attack Animal Training".  You don't need both, just one.
// 
// Your task is to find the cheapest way to get any given technology.  The player might own any set of techs already, 
// so you must account for that.  For example, if the player already owns "Being Nice to People" and wants to find 
// the cheapest way to get "Making Friends", the path returned should just be "Making Friends".  They don't need to 
// purchase anything else.
// 
// You MUST write a big comment below explaining your approach.  Why did you make each decision?  Why did you choose 
// a particular strategy over another?
// 
// This is a fairly difficult and involved task.  I finished the whole thing in 1 hour and 5 minutes, so I expect 
// you to spend at least 2/3 of the test time on it.  I'm not expecting everyone to get every little piece of this 
// working perfect, so here is a list of things I care about sorted by how much I care (with the most important 
// things at the top):
//      -You were able to correct ascertain how to solve the problem.  If your code doesn't work but you have a big 
//       comment explaining how to solve it and the code is moving in that direction, you'll get partial credit.
//      -You were able to correctly solve the problem when the player has no purchased techs.  This is the C-level.
//      -You were able to solve the problem when the player has purchased techs, correctly returning the appropriate 
//       set of techs.  This is approaching B territory.
//      -Your code is beautiful and well commented.  You have a great description of what you did in the space below.
//       This is firmly in B land, assuming all the previous things on this list are done well.
//      -You were able to solve the problem elegantly and optimally.  This is definitely the least important since 
//       the Paired Sums problem is more about writing an optimal algorithm, but if you manage this and everything 
//       else on the list, you have a solid chance at an A.
// 
// This section of the test is worth 60 points.
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// Your comments go here:
// 
//---------------------------------------------------------------------------------------------------------------------

class TechTree : public TechTreeBase
{
public:
    typedef std::vector<const Tech*> Path;

    void FindBestPath(int goalTech, Path& bestPath);
};
