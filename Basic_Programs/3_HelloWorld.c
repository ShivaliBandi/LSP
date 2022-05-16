#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    
    char* chr=(char *)malloc(11*sizeof(char));
    strcpy(chr,"HelloWorld");
    printf("%s\n",chr);
    free(chr);
    return 0;
}