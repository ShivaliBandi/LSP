#include"header.h"
#define  true 1
#define false 0
int checkContents(const char *filename1,const char *filename2);
int main(int argc,char **argv)
{
    assert(argc==3);
    int result=checkContents(argv[1],argv[2]);
    if(result==true)
        printf("Contents of %s and %s files are same\n",argv[1],argv[2]);
    else
        printf("Contents of %s and %s files are  not same\n",argv[1],argv[2]);

}
int checkContents(const char *filename1,const char *filename2)
{
    int fd1,fd2;
    char buffer1,buffer2;
    struct stat stats1,stats2;
    stat(filename1,&stats1);
    stat(filename2,&stats2);
    if(stats1.st_size!=stats2.st_size)
    {
        printf("ERROR:As Size of Two files are not same hence two files are not identical\n");
        return false;
    }
    else
    {
        fd1=open(filename1,O_RDONLY);
        fd2=open(filename2,O_RDONLY);
        if(fd1==-1)
        {
            printf("%s",strerror(errno));
            return false;
        }
        if(fd2==-1)
        {
            printf("%s",strerror(errno));
            return false;
        }
        while(buffer1!=EOF && buffer2!=EOF)
        {
            buffer1=getc(fd1);
            buffer2=getc(fd2);
            if(strcmp(buffer1,buffer2)!=0)
                break;
        }
        return false;
    }
   
    return true;
}