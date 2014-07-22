#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DEBUG
int main()
{
    FILE *fp;
    int init, *FS, FA[10][10], i, j, col, row, fs;
    char *str, temp[50];
    
    fp = FS = str = NULL;
    
    if(!(fp = fopen("input", "r")))
    {
        printf("Error opening file!!!\n");
        return -1;
    }
    
    fscanf(fp, "%d", &init);
    fgets(temp, sizeof(char)*50, fp);
    fgets(temp, sizeof(char)*50, fp);
#ifdef DEBUG
    printf("FS String: %s", temp);
#endif
    str = temp;
    i = 0;
    while(*str != '\0')
    {
        FS = (int *) realloc(FS, sizeof(int)*(i+1));
        sscanf(str, "%d", &FS[i++]);
#ifdef DEBUG
        printf("Here, i = %d, *str = %c\n", i, *str);
#endif
        str++;
        while(isdigit(*str))
        {
#ifdef DEBUG
            printf("He1");
#endif            
            str++;
        }
        while(isspace(*str))
            str++;
    }
    fs = i;
    
    fgets(temp, sizeof(char)*50, fp);
    str = temp;
    i= 0;
    while(*str != '\0')
    {
        sscanf(str, "%d", &FA[0][i++]);
#ifdef DEBUG
        printf("FA scanned: %s\n", temp);
        printf("Here1, i = %d, *str = %c\n", i, *str);
        getchar();
#endif
        str++;
        while(isdigit(*str))
            str++;
        while(isspace(*str))
            str++;
    }
    row = 1;
    col = i;
    while(!feof(fp))
    {
        fgets(temp, sizeof(char)*50, fp);
        printf("FA scanned: %s\n", temp);
        str = temp;
        i= 0;
        while(*str != '\0')
        {
            sscanf(str, "%d", &FA[row][i++]);
            str++;
            while(isdigit(*str))
                str++;
            while (isspace(*str))
                str++;
        }
        row++;
    }
    
    
    
#ifdef DEBUG
    printf("Initial State: %d\n", init);
    printf("Final states: ");
    for(i = 0; i < fs; i++)
        printf("%d, ", FS[i]);
    printf("\nInput Table:\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t", FA[row][col]);
        }
        printf("\n");
    }
#endif
    
    
    return 0;
}
