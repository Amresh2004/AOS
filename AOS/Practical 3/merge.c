#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int openf(char *filename);

int main() 
{
    DIR *dir;
    struct dirent *entry;
    int j, l, s, flag = 1, fd, fd1;
    char *ext = "txt.";
    char ch;
    fd1 = openf("new.txt");
    dir = opendir("./test");
    if (dir == NULL) 
    {
        perror("Failed to open directory");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL) 
    {
        flag = 1;
        l = strlen(entry->d_name);
        for (j = l - 1, s = 0; j >= l - 4 && s < 4; j--, s++) 
	{
            if (entry->d_name[j] != ext[s]) 
	    {
                flag = 0;
                break;
            }
        }
        if (flag == 1) 
	{
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "./test/%s", entry->d_name);
            fd = openf(filepath);
            while (read(fd, &ch, 1))
                write(fd1, &ch, 1);

            close(fd);
        }
    }

    printf("\nFile merge complete.\n");

    closedir(dir);
    close(fd1);

    return 0;
}

int openf(char *filename) 
{
    int fd;
    fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd < 0) 
    {
        perror("Open error");
    } 
    else 
    {
        printf("Opened: %s (fd = %d)\n", filename, fd);
    }
    return fd;
}

