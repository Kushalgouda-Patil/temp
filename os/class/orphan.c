
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  pid = fork();

  if (pid == 0) {
    sleep(2);
    printf("I am child and my PID is %d\n", getpid());
    printf("My parent pid is%d\n", getppid());
  } else {
    printf("I am parent and my PID is%d\n", getpid());
    printf("My child PID is %d\n", pid);
  }

  return EXIT_SUCCESS;
}
