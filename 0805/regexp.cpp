#include "regexp.h"

regexp::regexp()
{
}

regexp::regexp(std::string p)
{
	r = p;
}

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

	while((i = t.find('+', i)) < 4294967294)
	{
		if(isalpha(t[i - 1]))
		{
			t.insert(i, 1, t[i - 1]);
			t.replace(i+1, 1, 1, '*');
		}
		else
		{
			int parcount = 1;
			for(j = i - 1; j > 0 && parcount!= 0; j--)
			{
				if(t[j] == '(')
					parcount--;
				else if(t[j] == ')')
					parcount++;
			}
			t.replace(i, 1, 1, '*');
			t.insert(i, t.substr(j, i));
		}
	}
	i = 0;
	while(i < t.length())
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
							{
								if(checkAlternate(t, i))
								{
									if(t[i+1] == '+' || t[i+1] == '*' || t[i+1] == '|')
										i += 2;
									else
									{
										int parcount = 1;
										for(; parcount != 0; i++)
										{
											if(t[i] == '(')
												parcount++;
											else if(t[i] == ')')
												parcount--;
										}
									}
									break;
								}
							}
							return false;

			case OPARA:		i++;
							break;

			case CPARA:		i++;
							break;

			case BOOLOR:	i++;
							i = skipBlock(t, i);
							break;

			case QMARK:		j++;
							break;

			case KSTAR:		if(t.length() == (i + 1) && j == p.length())
							{
								i++;
								break;
							}
							i = goBlockBeg(t, i);
							break;

			default:		return false;
		}
	}

	return true;
}

bool regexp::checkAlternate(std::string p, unsigned int j)
{
	if(p[j+1] == '+' || p[j+1] == '*' || p[j+1] == '|')
		return true;
	if(j == 0)
		return false;
	if(p[j-1] == '(')
		return true;
	return false;
}

unsigned int regexp::skipBlock(std::string p, unsigned int i)
{
	if(p[i] == '(')
	{
		int parcount = 1;
		i++;
		for(; parcount != 0; i++)
		{
			if(p[i] == '(')
				parcount++;
			else if(p[i] == ')')
				parcount--;
		}
		return i;
	}
	i++;
	while(!isalpha(p[i]))
		i++;
	return i;
}

unsigned int regexp::goBlockBeg(std::string p, unsigned int i)
{
	if(p[i - 1] == ')')
	{
		int parcount = -1;
		i -= 2;
		for(; parcount != 0; i--)
		{
			if(p[i] == '(')
				parcount++;
			else if(p[i] == ')')
				parcount--;
		}
		return i;
	}
	i--;
	return i;
}
