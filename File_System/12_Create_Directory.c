#include"header.h"
int createDirectory(const char *dirName);
int main(int argc,char **argv)
{
    assert(argc==2);
    int result;
    result=createDirectory(argv[1]);
    if(result==true)
        printf("Directory Created successfully");
    else
        printf("ERROR:%s",strerror(errno));
    return 0;
}
int createDirectory(const char *dirName)
{
    int result;
    result=mkdir(dirName,0777);
    if(result==0)
        return true;
    else
        return false;
}