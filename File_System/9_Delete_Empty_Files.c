#include"header.h"
int deleteEmptyFiles(char *filename);
int main(int argc,char **argv)
{
    assert(argc==2);
    
    struct dirent *de;
    DIR *dr=opendir(argv[1]);
    char filename[256]={'\0'};
    while((de=readdir(dr))!=NULL)
    {
        strcat(filename,argv[1]);
        strcat(filename,"/");
        strcat(filename,de->d_name);
        deleteEmptyFiles(filename);
        memset(filename,'\0',strlen(filename));
    }
    closedir(dr);

    return 0;
}
int deleteEmptyFiles(char *filename)
{
   
    struct stat stats;
    stat(filename,&stats);
    if(stats.st_size==0)
        unlink(filename);  
                
    return 0;
        
}