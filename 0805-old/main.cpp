#include <iostream>
#include <string.h>
#include <ctype.h>

class regexp
{
	private:
		char re[21];
		enum TOKENTYPE {OPERAND, PARANBEG, PARANEND, BOOLOR, QUESTM, KSTAR, KPLUS, ERROR};
		TOKENTYPE ttype(char ch)
		{

		}

	public:
		regexp() {}
		regexp(char *p) {strcpy(re, p);}
		void set(char *);
		char *regexstring();
		int len();
		bool isvalid();
		bool validate(char *);
};

void regexp::set(char *p)
{
	strncpy(re, p, 20);
}

char *regexp::regexstring()
{
	return re;
}

int regexp::len()
{
	return strlen(re);
}

bool regexp::isvalid()
{
	int i = 0;
	while (i < this->len())
	{

	}
}

bool regexp::validate(char *)
{

}

int main()
{

}
