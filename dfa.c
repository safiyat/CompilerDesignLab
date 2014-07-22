#include <stdio.h>
#include <alloc.h>
#include <stdlib.h>


int main()
{
    FILE *fp;
    int init, *FS, **FA, i, col, row;
    char *str, temp[50];
    
    fp = FS = FA = str = NULL;
    
    if(fp = fopen("input", "r"))
    {
        printf("Error opening file!!!\n");
        return -1;
    }
    
    fscanf(fp, "%d", &init);
    fgets(temp, sizeof(char)*50, fp);
    str = temp;
    i = 0;
    while(str != '\0')
    {
        FS = (int *) realloc(FS, sizeof(int)*(i+1));
        sscanf(str, "%d", &FS[i++]);
        while(isdigit(*str))
            str++;
    }
    
    fgets(temp, sizeof(char)*50, fp);
    str = temp;
    FA = (int **) malloc(sizeof(int *)*1);
    i= 0;
    while(str != '\0')
    {
        FA[0] = (int *) realloc(FA[0], sizeof(int)*(i+1));
        sscanf(str, "%d", &FA[0][i++]);
        while(isdigit(*str))
            str++;
    }
    row = 1;
    col = i;
    while(!feof(fp))
    {
        fgets(temp, sizeof(char)*50, fp);
        str = temp;
        FA = (int **) realloc(FA, sizeof(int *)*(row+1));
        i= 0;
        while(str != '\0')
        {
            FA[row] = (int *) realloc(FA[row], sizeof(int)*(i+1));
            sscanf(str, "%d", &FA[row][i++]);
            while(isdigit(*str))
                str++;
        }
        row++;
    }
    
}