#include<stdio.h>
#include<dirent.h>
int main()
{
    DIR *d;
    struct dirent *dir;
    // d = opendir("."); // open current directory
    // d = opendir("C:\\"); // open C drive
    d = opendir("."); // open Users folder
    if(d)
    {
        while((dir = readdir(d)) != NULL)
        {
            printf("Name : %s\n", dir->d_name);
            printf("Type : %d\n", dir->d_type);
        }
        closedir(d);
    }
    return 0;
}