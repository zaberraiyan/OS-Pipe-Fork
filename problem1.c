#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char** cmd;
    cmd = argv + 1; // command line input
    int cid = fork();// new process
    if (cid == 0)
    {
        execvp(cmd[0],cmd);
        exit(0);
    }
    else
    {
        printf("Process executed\n");
        wait(NULL);
        printf("+++++++++++\n");
    }

    return 0;
}
