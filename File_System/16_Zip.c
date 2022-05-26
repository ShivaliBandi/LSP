#include"header.h"
struct file
{
    char filename[256];
    size_t fileSize;
};
/*
function:Zip
Input:Filename(const character array)
Output:integer which defines true of false
Description:zip function takes input filename and copies its data nd filename and filesize into a 
destination file and deletes source file 
*/
int Zip(const char *fileName);
int main(int argc,char **argv)
{
    assert(argc==2);
    struct dirent *de;
    DIR *dr;
    int ret=0;
    dr=opendir(argv[1]);
    char path[256]={'\0'};
    while((de=readdir(dr))!=NULL)
    {
        if(de->d_type==8)
        {
            strcat(path,argv[1]);
            strcat(path,"/");
            strcat(path,de->d_name);
            int ret=Zip(path);
            if(ret==false)
            {
                printf("ERROR(1):%s\n",strerror(errno));
                break;
            }
            memset(path,'\0',256);

        }
    }
    closedir(dr);
    return 0;
}
int Zip(const char *fileName)
{
    size_t fdSrc,fdDes,wb,rb;
    char buffer[4096]={'\0'};
    fdSrc=open(fileName,O_RDONLY);
    if(fdSrc==-1)
    {
        printf("ERROR(2):%s",strerror(errno));
        return false;
    }
    fdDes=open("allcombine.txt",O_CREAT | O_APPEND | O_RDWR,0777);
    if(fdDes==-1)
    {
        printf("ERROR(3):%s",strerror(errno));
        return false;
    }
    struct stat stats;
    stat(fileName,&stats);
    struct file FILE;
    strcpy(FILE.filename,fileName);
    FILE.fileSize=stats.st_size;
    wb=write(fdDes,&FILE,sizeof(FILE));
    while((rb=read(fdSrc,buffer,4096)))
    {
        wb=write(fdDes,buffer,rb);
        if(rb!=wb)
        {
            printf("ERROR(3)%s\n",strerror(errno));
            return false;
        }
        
    }
    close(fdSrc);
    unlink(fileName);
    close(fdDes);
    return true;
}
