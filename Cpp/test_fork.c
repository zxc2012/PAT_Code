#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    pid_t cpid,tcpid;
    cpid = fork();
    int status;
    pid_t mypid=getpid();
    if (cpid > 0) {               /* Parent Process */
        tcpid = wait(&status);
        printf("%d wait%d(%d)",mypid,tcpid,status);
    } else if (cpid == 0) {      /* Child Process */
        mypid = getpid();
        char *myargs[3];
        myargs[0] = strdup("wc");   // program: "wc" (word count)
        myargs[1] = strdup("test.cpp"); // argument: file to count
        myargs[2] = NULL;           // marks end of array
        execvp(myargs[0], myargs);  // runs word count
        printf("this shouldn't print out.\n");
    }
}