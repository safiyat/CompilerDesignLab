#include <iostream>

using namespace std;

struct globalRef
{
    char stateName;
    state *addr;
}*refTable = NULL;

class state;

state *current = NULL, *next = NULL;

struct transition
{
    char ip, op;
    state *t;
};

class state
{
    int tCount;
    struct transition *transitionTable;
public:
    char transit(string);
    void populate(ifstream &);
};

char state::transit(string p)
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

void populate(ifstream &file)
{
    
}

int main()
{
    
    return 0;
}