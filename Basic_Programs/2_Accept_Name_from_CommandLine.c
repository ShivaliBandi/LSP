#include<stdio.h>
#include<assert.h>
int main(int argc,char** argv)
{
    assert(argc==2);
    
    printf("Name From Command Line:%s\n",argv[1]);
    return 0;
}