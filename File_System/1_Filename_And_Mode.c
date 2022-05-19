#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>
#include<ctype.h>
int main(int argc,char ** argv)
{
    
    assert(argc==3);
    int fd=0;
    for(int i=0;i<strlen(argv[2]);i++)
        argv[2][i]=tolower(argv[2][i]);
    if(strcmp(argv[2],"write")==0)
        fd=open(argv[1],O_WRONLY);
    else if(strcmp(argv[2],"read")==0)
        fd=open(argv[1],O_RDONLY);
    else if(strcmp(argv[2],"readwrite")==0 || strcmp(argv[2],"writeread")==0)
       fd=open(argv[1],O_RDWR);
    else
    {
        printf("Please Enter right Mode \n1)write\n2)read\n3)readwrite\n");
        exit(0);
    }
   
    if(fd!=-1)
    
        printf("File Opened succesfully with file descriptor %d\n",fd);
    
    else
    
        printf("%s\n",strerror(errno));
    close(fd);
    return 0;
}