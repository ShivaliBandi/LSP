#include "header.h"

int main(int argc,char **argv)
{
    assert(argc==3);
    char buffer[1024]={'\0'};
    int fdSourceFile,fdDestinationfile,icount=0;
    fdSourceFile=open(argv[1],O_RDONLY);
    fdDestinationfile=open(argv[2],O_RDWR | O_CREAT,0777);
    if(fdSourceFile==-1 || fdDestinationfile==-1)
    {
        printf("ERROR:Unable to open or create file");
        exit(0);
    }
    while((icount=read(fdSourceFile,buffer,sizeof(buffer)))!=0)
    {
        if(strlen(buffer)==1024)
        {
            write(fdDestinationfile,buffer,strlen(buffer));
            memset(buffer,'\0',strlen(buffer));
        }
    }
    write(fdDestinationfile,buffer,strlen(buffer));
    close(fdDestinationfile);
    close(fdSourceFile);


    return 0;
}