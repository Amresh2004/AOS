#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

int openf(char*);

int main()
{
    DIR *i;
    struct dirent *k;
    int j, l, s, flag = 1, fd, fd1;
    char *m = ".txt";
    char ch;

    fd1 = openf("new.txt");
    i = opendir("./test");
    if (i == NULL) {
        perror("opendir failed");
        return 1;
    }

    while ((k = readdir(i)) != NULL)
    {
        l = strlen(k->d_name);
        if (l >= 4 && strcmp(k->d_name + l - 4, m) == 0)
            flag = 1;
        else
            flag = 0;

        if (flag == 1)
        {
            char path[100];
            sprintf(path, "./test/%s", k->d_name);
            fd = openf(path);
            while (read(fd, &ch, 1))
                write(fd1, &ch, 1);
            close(fd);
        }
    }
    close(fd1);
    closedir(i);
    return 0;
}

int openf(char * s)
{
    int fd;
    fd = open(s, O_RDWR | O_CREAT, 0666);
    if (fd < 1)
        perror("open error");
    else
        printf("input file open successful fd = %d\n", fd);
    return fd;
}

