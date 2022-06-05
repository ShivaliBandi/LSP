/*
Accept direcotry name and display all files name who size if greater then 10bytes
*/
#include"header.h"
status_t checkSizeOfFile(const char *filename);
int main(int argc,char **argv)
{
    assert(argc==2);
    struct dirent *de;
    DIR *dr;
    dr=opendir(argv[1]);
    while((de=readdir(dr))!=NULL)
    {
        if(de->d_type==8)
        {
            status_t result;
            char filename[256]={'\0'};
            strcat(filename,argv[1]);
            strcat(filename,"/");
            strcat(filename,de->d_name);

            result=checkSizeOfFile(filename);
            printf("%d result\n",result);
            if(result==true)
            {
                printf("%s",de->d_name);
            }
        }
    }
    return 0;
}

status_t checkSizeOfFile(const char *filename)
{
    struct stat stats;
    printf("%s\n",filename);
    int result=stat(filename,&stats);
    if(result==-1)
    {
       printf("ERROR(2):Size of File is not greater then 10bytes\n");
         return false;
    }
       
    else
    {
        if(stats.st_size>=10)
            return true;
        else    
            return false;
    }
}