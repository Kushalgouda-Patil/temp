#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int glob = 6;
int main(void) {
  int var;
  pid_t pid;
  var = 88;
  pid = vfork();

  if (pid == 0) {
    glob++;
    var++;
    _exit(0);
  }
  printf("pid=%d,glob=%d,var=%d\nchildpid=%d", getpid(), glob, var, pid);
  exit(0);
  return EXIT_SUCCESS;
}
