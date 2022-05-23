#include"header.h"
int main(int argc,char **argv)
{
    char destinationFileName[1024]={'\0'},sourceFileName[1024]={'\0'},buffer[4096]={'\0'};
    int fdSrc=-1,fdDes=-1;
    size_t rb=0,wb=0;
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
            
            memset(destinationFileName,'\0',sizeof(destinationFileName));
            memset(sourceFileName,'\0',sizeof(sourceFileName));
            // sprintf(destinationFileName,"%s/%s",argv[2],deSrc->d_name);
           // sprintf(sourceFileName,"%s/%s",argv[1],deSrc->d_name);
            strcat(destinationFileName,argv[2]);
            strcat(destinationFileName,"/");
            strcat(destinationFileName,deSrc->d_name);
            //----
            strcat(sourceFileName,argv[1]);
            strcat(sourceFileName,"/");
            strcat(sourceFileName,deSrc->d_name);
            fdDes=open(destinationFileName,O_CREAT | O_RDWR | O_APPEND,0777);
            printf("Destination file name %s \n",destinationFileName);
            if(fdDes==-1)
            {
                printf("%s \n",strerror(errno));
                exit(1);
            }
                
            fdSrc=open(sourceFileName,O_RDONLY);
            printf("Source file name %s \n",sourceFileName);
            if(fdSrc==-1)
            {
                printf("%s \n",strerror(errno));
                exit(1);
            }
            while((rb=read(fdSrc,buffer,4096))>0)
            {
               wb=write(fdDes,buffer,rb);
               if(wb!=rb)
               {
                   printf("ERROR:Unable to write complete block\n");
                   exit(1);
               }
                
            }
            if(rb==-1)
            {
                printf("%s \n",strerror(errno));
            }
            close(fdDes);
            close(fdSrc);
           unlink(sourceFileName);
        }
       
       

    }
  
    closedir(drDes);
    closedir(drSrc);

    return 0;
}