#include "state.h"

char state::transit(std::string p)
{
	int i;
	for(i = 0; i < tCount; i++)
	{
		if(transitionTable[i].ip == p[0])
		{
			next = transitionTable[i].t;
			return transitionTable[i].op;
		}
	}
	return '~';
}

void populate(std::ifstream &file)
{

}