#ifndef STATE_H
#define STATE_H

#include <iostream>

struct transition;

class state
{
		int tCount;
		struct transition *transitionTable;
	public:
		char transit(std::string);
		void populate(std::ifstream &);
};

struct globalRef
{
	char stateName;
	state *addr;
}*refTable = NULL;

state *current = NULL, *next = NULL;

struct transition
{
	char ip, op;
	state *t;
};

#endif // STATE_H
