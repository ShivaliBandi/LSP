#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
void lsFile(char *dirname)
{
    struct stat stats;
    stat(dirname,&stats);

    struct dirent *de;
    DIR *dr;
    char tmpdirname[255]={'\0'};

    dr=opendir(dirname);
    if(dr==NULL)
        return;
    while((de=readdir(dr))!=NULL)
    {
        if((de->d_type==4)&& (strcmp(de->d_name,".")!=0)&& (strcmp(de->d_name,"..")!=0))
        {
            memset(tmpdirname,'\0',255);
            strcat(tmpdirname,dirname);
            strcat(tmpdirname,"/");
            strcat(tmpdirname,de->d_name);
           // printf("dir->%s\n",tmpdirname);
            lsFile(tmpdirname);
        
        }
        else
        {
            printf("inside %s-> %s\n",dirname,de->d_name);
        }
    }
    closedir(dr);
}
int main(int argc ,char **argv)
{
  lsFile(argv[1]);
  return 0;
}