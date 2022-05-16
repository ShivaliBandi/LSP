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
    
    assert(argc==2);
    int fd=0;
    /*
    #include <sys/stat.h>
    #include <fcntl.h>
    open() system call is used to open an existing file or create a new file and open it for read or writing or for both
    Syntex:open(const char  *path,int flags,/ mode_t mode/);
    it return file descriptor on success and -1 on failure
    O_RDONLY | Open the file for reading only
    O_WRONLY | Open the file for writing only
    O_RDWR   | Open the file for both reading and writing
    
    
    */
    fd=open(argv[1],O_RDONLY);
    if(fd!=-1)
    
        printf("File Opened succesfully with file descriptor %d",fd);
    
    else
    
        printf("%s",strerror(errno));
    

    /*
    #include<unistd.h>
    close() sys call closes opened file 
    Syntax:close(int fd);
    
    */
    close(fd);
    return 0;
}