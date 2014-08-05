#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char re[20], test[50], *r, *t;
    int i;
    printf("Please enter the Regular Expression: ");
    fgets(re, sizeof(char)*20, stdin);
    re[strlen(re) - 1] = '\0';
    for(i = 0; i < strlen(re); )
    {
        printf("-%c", re[i]);
        switch(re[i])
        {
            case '+':   i++;
                        break;
                
            case '*':   i++;
                        break;
                
            case '.':   i++;
                        break;
            
            case '|':   i++;
                        break;
            
            case '(':   i++;
                        break;
            
            case ')':   i++;
                        break;
            
            default:    if(isalpha(re[i]))
                        {
                            i++;
                            break;
                        }
                        else
                            printf("Invalid Regular Expression!\n");
                        return -1;
        }
    }
    
    return 0;
}