#include "regexp.h"

regexp::TTYPE regexp::ttype(char p)
{
	if(isalpha(p))
		return OPERAND;
	if(p == '(')
		return OPARA;
	if(p == ')')
		return CPARA;
	if(p == '|')
		return BOOLOR;
	if(p == '?')
		return QMARK;
	if(p == '*')
		return KSTAR;
	if(p == '+')
		return KPLUS;
	return ERROR;
}

regexp::regexp()
{
}

regexp::regexp(char *p)
{
	r = p;
}

std::string regexp::text()
{
	return r;
}

unsigned int regexp::len()
{
	return r.length();
}

bool regexp::isvalid()
{
	if(strstr(r.data(), "()"))
		return false;
	if(strstr(r.data(), "+*"))
		return false;
	if(strstr(r.data(), "*+"))
		return false;
	if(strstr(r.data(), "(+"))
		return false;
	if(strstr(r.data(), "(*"))
		return false;
	return true;
}

bool regexp::validate(char *p)
{
	std::string a;
	a.copy(p, strlen(p));
	return validate(a);
}

bool regexp::validate(std::string p)
{
	std::string t = r;
	unsigned int i = 0, j = 0;
	while(i < r.length())
	{
		switch(ttype(t[i]))
		{
			case OPERAND:	if(t[i] == p[j])
							{
								i++;
								j++;
								break;
							}
							else
								return false;

			case OPARA:		i++;
							break;

			case CPARA:		i++;
							break;

			default:		return false;
		}
	}
	return true;
}