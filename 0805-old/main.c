#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEBUG

enum TOKENTYPE {OPERAND, PARANBEG, PARANEND, BOOLOR, QUESTM, KSTAR, KPLUS};

int main()
{
	char re[20], test[50], *r, *t;
	int i;
	printf("Please enter the Regular Expression: ");
	fgets(re, sizeof(char)*20, stdin);
	if(!strlen(re))
		return -1;
	re[strlen(re) - 1] = '\0';
	for(i = 0; i < strlen(re); i++)
	{
#ifdef DEBUG
		printf("-%c", re[i]);
#endif
/*
		switch(re[i])
		{
			case '+': //  i++;
						break;

			case '*': //  i++;
						break;

			case '.': //  i++;
						break;

			case '|': //  i++;
						break;

			case '(': //  i++;
						break;

			case ')': //  i++;
						break;

			default:    if(isalpha(re[i]))
						{
						//	i++;
							break;
						}
						else
							printf("Invalid Regular Expression!\n");
						return -1;
		}
*/
		if()
	}

	return 0;
}