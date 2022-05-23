#include"header.h"
int main(int argc,char **argv)
{
    char destinationFileName[1024]={'\0'},sourceFileName[1024]={'\0'},buffer[10]={'\0'};
    int fdSrc=-1,fdDes=-1,icount=0;
    struct dirent *deSrc;
    struct dirent *deDes; //dirent structure's pointer
    DIR *drSrc=opendir(argv[1]);
    assert(drSrc!=NULL);
    DIR *drDes;
    mkdir(argv[2],S_IRWXU);
    drDes=opendir(argv[2]);
    while((deSrc=readdir(drSrc))!=NULL)
    {
        if((strcmp(deSrc->d_name,".")!=0) && (strcmp(deSrc->d_name,"..")!=0))
        {
            memset(buffer,'\0',strlen(buffer));
            memset(destinationFileName,'\0',sizeof(destinationFileName));
            memset(sourceFileName,'\0',sizeof(sourceFileName));
            sprintf(destinationFileName,"%s/%s",argv[2],deSrc->d_name);
            sprintf(sourceFileName,"%s/%s",argv[1],deSrc->d_name);
            fdDes=open(destinationFileName,O_CREAT | O_RDWR,0777);
            printf("Destination file name %s \n",destinationFileName);
            if(fdDes==-1)
            exit(0);

            fdSrc=open(sourceFileName,O_RDONLY);
            printf("Source file name %s \n",sourceFileName);
            if(fdSrc==-1)
            exit(0);
            while(icount=read(fdSrc,buffer,sizeof(buffer))!=0)
            {
                
                
                     write(fdDes,buffer,strlen(buffer));
                     memset(buffer,'\0',strlen(buffer));
                
            }
           //l write(fdDes,buffer,strlen(buffer));
            close(fdDes);
            close(fdSrc);
            
           
        }
       
       

    }
  
    

    return 0;
}
#include"header.h"
int main(int argc,char **argv)
{
    char destinationFileName[1024]={'\0'},sourceFileName[1024]={'\0'},buffer[10]={'\0'};
    int fdSrc=-1,fdDes=-1,icount=0;
    struct dirent *deSrc;
    struct dirent *deDes; //dirent structure's pointer
    DIR *drSrc=opendir(argv[1]);
    assert(drSrc!=NULL);
    DIR *drDes;
    mkdir(argv[2],S_IRWXU);
    drDes=opendir(argv[2]);
    while((deSrc=readdir(drSrc))!=NULL)
    {
        if((strcmp(deSrc->d_name,".")!=0) && (strcmp(deSrc->d_name,"..")!=0))
        {
            memset(buffer,'\0',strlen(buffer));
            memset(destinationFileName,'\0',sizeof(destinationFileName));
            memset(sourceFileName,'\0',sizeof(sourceFileName));
            sprintf(destinationFileName,"%s/%s",argv[2],deSrc->d_name);
            sprintf(sourceFileName,"%s/%s",argv[1],deSrc->d_name);
            fdDes=open(destinationFileName,O_CREAT | O_RDWR,0777);
            printf("Destination file name %s \n",destinationFileName);
            if(fdDes==-1)
            exit(0);

            fdSrc=open(sourceFileName,O_RDONLY);
            printf("Source file name %s \n",sourceFileName);
            if(fdSrc==-1)
            exit(0);
            while(icount=read(fdSrc,buffer,sizeof(buffer))!=0)
            {
                
                
                     write(fdDes,buffer,strlen(buffer));
                     memset(buffer,'\0',strlen(buffer));
                
            }
           //l write(fdDes,buffer,strlen(buffer));
            close(fdDes);
            close(fdSrc);
            
           
        }
       
       

    }
  
    

    return 0;
}
#include"header.h"
int main(int argc,char **argv)
{
    char destinationFileName[1024]={'\0'},sourceFileName[1024]={'\0'},buffer[10]={'\0'};
    int fdSrc=-1,fdDes=-1,icount=0;
    struct dirent *deSrc;
    struct dirent *deDes; //dirent structure's pointer
    DIR *drSrc=opendir(argv[1]);
    assert(drSrc!=NULL);
    DIR *drDes;
    mkdir(argv[2],S_IRWXU);
    drDes=opendir(argv[2]);
    while((deSrc=readdir(drSrc))!=NULL)
    {
        if((strcmp(deSrc->d_name,".")!=0) && (strcmp(deSrc->d_name,"..")!=0))
        {
            memset(buffer,'\0',strlen(buffer));
            memset(destinationFileName,'\0',sizeof(destinationFileName));
            memset(sourceFileName,'\0',sizeof(sourceFileName));
            sprintf(destinationFileName,"%s/%s",argv[2],deSrc->d_name);
            sprintf(sourceFileName,"%s/%s",argv[1],deSrc->d_name);
            fdDes=open(destinationFileName,O_CREAT | O_RDWR,0777);
            printf("Destination file name %s \n",destinationFileName);
            if(fdDes==-1)
            exit(0);

            fdSrc=open(sourceFileName,O_RDONLY);
            printf("Source file name %s \n",sourceFileName);
            if(fdSrc==-1)
            exit(0);
            while(icount=read(fdSrc,buffer,sizeof(buffer))!=0)
            {
                
                
                     write(fdDes,buffer,strlen(buffer));
                     memset(buffer,'\0',strlen(buffer));
                
            }
           //l write(fdDes,buffer,strlen(buffer));
            close(fdDes);
            close(fdSrc);
            
           
        }
       
       

    }
  
    

    return 0;
}
#include"header.h"
int main(int argc,char **argv)
{
    char destinationFileName[1024]={'\0'},sourceFileName[1024]={'\0'},buffer[10]={'\0'};
    int fdSrc=-1,fdDes=-1,icount=0;
    struct dirent *deSrc;
    struct dirent *deDes; //dirent structure's pointer
    DIR *drSrc=opendir(argv[1]);
    assert(drSrc!=NULL);
    DIR *drDes;
    mkdir(argv[2],S_IRWXU);
    drDes=opendir(argv[2]);
    while((deSrc=readdir(drSrc))!=NULL)
    {
        if((strcmp(deSrc->d_name,".")!=0) && (strcmp(deSrc->d_name,"..")!=0))
        {
            memset(buffer,'\0',strlen(buffer));
            memset(destinationFileName,'\0',sizeof(destinationFileName));
            memset(sourceFileName,'\0',sizeof(sourceFileName));
            sprintf(destinationFileName,"%s/%s",argv[2],deSrc->d_name);
            sprintf(sourceFileName,"%s/%s",argv[1],deSrc->d_name);
            fdDes=open(destinationFileName,O_CREAT | O_RDWR,0777);
            printf("Destination file name %s \n",destinationFileName);
            if(fdDes==-1)
            exit(0);

            fdSrc=open(sourceFileName,O_RDONLY);
            printf("Source file name %s \n",sourceFileName);
            if(fdSrc==-1)
            exit(0);
            while(icount=read(fdSrc,buffer,sizeof(buffer))!=0)
            {
                
                
                     write(fdDes,buffer,strlen(buffer));
                     memset(buffer,'\0',strlen(buffer));
                
            }
           //l write(fdDes,buffer,strlen(buffer));
            close(fdDes);
            close(fdSrc);
            
           
        }
       
       

    }
  
    

    return 0;
}