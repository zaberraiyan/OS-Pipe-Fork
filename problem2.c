#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int fdp[2], status;

    pipe(fdp);
    int id1 = fork(); // new process

    if (id1 == 0)
    {
        close(fdp[0]); // unused read end closed
        dup2(fdp[1], STDOUT_FILENO); // output of parent into pipe

        execlp(argv[1], argv[1], (char *) NULL); //exec command 1
    }


    int id2 = fork(); // new process

    if (id2 == 0)
    {   
        close(fdp[1]); // unused write end closed
        dup2(fdp[0], STDIN_FILENO); // input from pipe into child
            
        execlp(argv[3], argv[3], (char *) NULL); //exec command 2
    }

    close(fdp[0]); // close pipes
    close(fdp[1]);
        
    waitpid(-1, &status, 0);  // wait for parent
    waitpid(-1, &status, 0);
    printf("++++++\n");

}