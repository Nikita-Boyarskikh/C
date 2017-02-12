#include <iostream>
#include <sys/types>
#include <unistd.h>

static void sigchildHandler(int sig);

int main(int argc, char **argv) {
    pid_t pid = fork();

    if (pid < 0) exit 1;

    else if (pid > 0)
        // Parent fork
        signal(SIGCHILD, &sigchildHandler);

    else {
        // Child fork
        int childPID = getpid();
