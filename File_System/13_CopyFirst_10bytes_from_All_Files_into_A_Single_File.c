#include"header.h"
int copyFirst10Bytes(const char *fileName);
int main(int argc,char **argv)
{
    assert(argc==2);
    struct dirent *de;
    DIR *dr;
    char FileName[256]={'\0'};
    dr=opendir(argv[1]);
    if(dr==NULL)
    {
        printf("ERROR(1):%s\n",strerror(errno));
        exit(1);
    }
    while((de=readdir(dr))!=NULL)
    {
        int result;
        if(de->d_type==8)
        {
            strcat(FileName,argv[1]);
            strcat(FileName,"/");
            strcat(FileName,de->d_name);
           // printf("FileName %s\n",FileName);
            result=copyFirst10Bytes(FileName);

        }
            
        if(result==false)
        {
            printf("ERROR(2):%s\n",strerror(errno));
            break;
        }
        else
            printf("10Bytes copied Succesfully from %s\n",FileName);
        memset(FileName,'\0',strlen(FileName));
        
      
    }
    return 0;
}
int copyFirst10Bytes(const char *fileName)
{
    size_t fdwrite,rb,wb,fdread;
    char buffer[11]={'\0'};
    fdread=open(fileName,O_RDONLY);
    fdwrite=open("demo.txt",O_CREAT | O_APPEND |O_RDWR,0777);
    if(fdwrite==-1)
    {
        printf("ERROR(3):%s\n",strerror(errno));
        return false;
    }
    if(fdread==-1)
    {
        printf("ERROR(4):%s\n",strerror(errno));
        return false;
    }
    rb=read(fdread,buffer,10);
    wb=write(fdwrite,buffer,rb);
    if(rb!=wb)
    {
        printf("ERROR:Unable to write all bytes sucssfully\n");
        return false;
    }
    close(fdread);
    close(fdwrite);
    return true;
}