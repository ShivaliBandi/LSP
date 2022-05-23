#include"header.h"
int main(int argc,char **argv)
{
    assert(argc==3);
    struct dirent *de;
    DIR *dr=opendir(argv[1]);
    int flag=0;
    while((de=readdir(dr))!=NULL)
        if((de->d_type==8) && (strcmp(de->d_name,argv[2])==0))
            flag=1;
    (flag==1)?printf("File Exists\n"):printf("File Doesn't Exists\n");
    closedir(dr);
    return 0;
}