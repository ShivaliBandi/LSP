#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>
#include<ctype.h>
#include <time.h>
#include <sys/types.h>
void DisplayInfo(struct stat stats);
int main(int argc,char ** argv)
{
    
    assert(argc==2);
    struct stat stats;
    stat(argv[1],&stats);
    DisplayInfo(stats);
    return 0;
}
void DisplayInfo(struct stat stats)
{
    printf("File type:");
    if(__S_ISTYPE(stats.st_mode,S_IFBLK)!=0)
        printf("Block Special File\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFCHR)!=0)
        printf("Character Special File\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFDIR)!=0)
        printf("Directory\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFBLK)!=0)
        printf("Block File\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFIFO)!=0)
        printf("PIPES AND FIFO Special File\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFREG)!=0)
        printf("Regular File\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFLNK)!=0)
        printf("Symbolic Link\n");
    else if(__S_ISTYPE(stats.st_mode,S_IFSOCK)!=0)
        printf("Local Sockets\n");
    printf("Inode Number:%ld\n",stats.st_ino);
    printf("Block Size:%ld\n",stats.st_blksize);
    printf("File Size:%ld\n",stats.st_size);    
    printf("Device:%ld\n",stats.st_dev);
    printf("Link Count:%ld\n",stats.st_nlink);
    printf("Last status change:       %s", ctime(&stats.st_ctime));
    printf("Last file access:         %s",ctime(&stats.st_atime));
    printf("Last file modification:   %s", ctime(&stats.st_mtime));

}