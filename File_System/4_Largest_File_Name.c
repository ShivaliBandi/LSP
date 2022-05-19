#include "./header.h"
int main(int argc,char ** argv)
{
    
    assert(argc==2);
    struct dirent *de;// Pointer for directory entry
    struct stat stats;
    int max=-1;
    char buffer[100];
    // opendir() returns a pointer of DIR type. 
    DIR *dr=opendir(argv[1]);
    if(dr==NULL)
    {
        printf("Unable to Open Directory\n%s",strerror(errno));
        exit(0);
    }
    while((de=readdir(dr))!=NULL)
    {
       
        if(de->d_type==8)
        {
            stat(de->d_name,&stats);

            if(stats.st_size>max)
            {
                max=stats.st_size;
                memset(buffer,'\0',strlen(buffer));
                strcpy(buffer,de->d_name);
            }
        }
    }
    printf("Largest size filename:%s\nsize:%d\n",buffer,max);
    
    return 0;
}
