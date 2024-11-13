#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    pid_t pid = fork();  // Create a new child process

    int sleeptime = 30;

    if(argc > 1){
        sleeptime = atoi(argv[1]);
    }

    if(sleeptime == 0){
        sleeptime = 30;
    }

    if (pid > 0) {
        // Parent process: Just sleep, don't call wait().
        printf("Parent process (PID: %d) is running, child (PID: %d) will become a zombie.\n", getpid(), pid);
        printf("Sleep %d seconds...\n", sleeptime);
        sleep(sleeptime);  // Keep the parent alive to allow time for observing the zombie process
    } else if (pid == 0) {
        // Child process: Exit immediately, becomes a zombie
        printf("Child process (PID: %d) is exiting.\n", getpid());
        exit(0);
    } else {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
