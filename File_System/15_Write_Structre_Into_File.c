#include"header.h"
struct employee
{
    char name[256];
    int id;
    int salary;
};
int main(int argc,char **argv)
{

       assert(argc==5);
    struct employee EMP,EMP1;
    strcpy(EMP.name,argv[1]);
    EMP.id=atoi(argv[2]);
    EMP.salary=atoi(argv[3]);
    int fd=open(argv[4],O_RDWR|O_CREAT|O_APPEND,0777);
    size_t wb=write(fd,&EMP,sizeof(EMP)),rb;
    if(wb=-1)
        printf("%s",strerror(errno));
    lseek(fd,0,SEEK_SET);
    rb=read(fd,&EMP1,sizeof(EMP1));
    
    printf("%s\t%d\t%d\n",EMP1.name,EMP1.id,EMP1.salary);
    
    close(fd);
    return 0;
}