#ifndef REGEXP_H
#define REGEXP_H

#include <string.h>
#include <iostream>

class regexp
{
		std::string r;
		enum TTYPE {OPERAND, OPARA, CPARA, BOOLOR, QMARK, KSTAR, KPLUS, ERROR};
		TTYPE ttype(char);
	public:
		regexp();
		regexp(char *);
		bool isvalid();
		std::string text();
		unsigned int len();
		bool validate(char *);
		bool validate(std::string);
};

#endif // REGEXP_H
