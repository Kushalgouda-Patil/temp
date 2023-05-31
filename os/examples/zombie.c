#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;
  pid = fork();

  if (pid == 0) {
    printf("I am child and my PID is %d\n", getpid());
    printf("My parent PID is %d\n", getppid());
  } else {
    sleep(10);
    printf("I am parent and my PID is %d\n", getpid());
    printf("My child PID is %d\n", pid);
  }
  return 0;
}
