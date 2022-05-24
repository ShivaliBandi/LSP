#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>
int main(int argc,char ** argv)
{
    
    assert(argc==3);
    int fd=0;
    
    fd=open(argv[1],O_RDONLY);
    if(fd!=-1)
    
        printf("File Opened succesfully with file descriptor %d\n",fd);
    
    else
    
        printf("%s\n",strerror(errno));
    char buffer[100];
    int i=0;
    off_t offset=lseek(fd,atoi(argv[2]),SEEK_CUR);
    read(fd,buffer,20);
    while(buffer[i]!='\0')
    {
        printf("%c",buffer[i]);
        i++;
    }
    /*
    #include<unistd.h>
    close() sys call closes opened file 
    Syntax:close(int fd);
    
    */
    close(fd);
    return 0;
}