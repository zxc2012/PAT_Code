#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    pid_t cpid,tcpid;
    cpid = fork();
    int status;
    if (cpid > 0) {               /* Parent Process */
        tcpid = wait(&status);
    } else if (cpid == 0) {      /* Child Process */
    char *args[] = {"ls", "-l", NULL};
    execv("/bin/ls", args);

    /* execv doesn’t return when it works.
        So, if we got here, it failed! */

    perror("execv");
    exit(1);
    }

}