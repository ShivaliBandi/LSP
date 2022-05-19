#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>
#include<ctype.h>
#include <time.h>
#include <sys/types.h>
#include<dirent.h>
int main(int argc,char ** argv)
{
    
    assert(argc==2);
    struct dirent *de;// Pointer for directory entry

    // opendir() returns a pointer of DIR type. 
    DIR *dr=opendir(argv[1]);
    if(dr==NULL)
    {
        printf("Unable to Open Directory\n%s",strerror(errno));
        exit(0);
    }
    while((de=readdir(dr))!=NULL)
    {
        printf("Directory Name:%s\n",de->d_name);
        printf("Directory number:%ld\n",de->d_ino);
        printf("Directory Offset:%ld\n",de->d_off);
        printf("Directory Type:%d\n",de->d_type);
        printf("Directory reclen:%d\n",de->d_reclen);

    }
    
    return 0;
}
