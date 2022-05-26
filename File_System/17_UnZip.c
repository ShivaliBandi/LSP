#include"header.h"
struct file
{
    char filename[256];
    size_t fileSize;
};
int UnZip(const char *fileName);
int main(int argc,char **argv)
{
    assert(argc==2);
    int ret=UnZip(argv[1]);
    if(ret==false)
        printf("ERROR:Unable to Unzip file\n");
    else
        printf("UnZipped Succesfully\n");
    return 0;
}
/*
function:UnZip
Input:Filename(const character array)
Output:integer which defines true of false
Description:Unzip function takes input filename  and reads filename creates that file and copies the data from source 
file to destination file and deletes source file 
*/
int UnZip(const char *fileName)
{
    struct file FILE;
    size_t fdSrc=open(fileName,O_RDONLY),wb,rb;
    while((rb=read(fdSrc,&FILE,sizeof(FILE)))!=0)
    {
        
        size_t fdDes=open(FILE.filename,O_CREAT | O_RDWR,0777);
        char *buffer=(char *)malloc(FILE.fileSize*sizeof(char));
        rb=read(fdSrc,buffer,FILE.fileSize);
        write(fdDes,buffer,FILE.fileSize);
        close(fdDes);        
    }
    close(fdSrc);
    unlink(fileName);
    return true;
}
