#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gVar = 10;
char buf[] = "Output to stdout";
void main() {

  int local_var = 20;
  int pid;
  write(1, buf, sizeof(buf) - 1);

  printf("before fork\n");
  if ((pid = fork()) == 0) {
    gVar++;
    local_var++;
  } else {
    sleep(2);
  }
  printf("Global var=%d local_var=%d pid=%d\n", gVar, local_var, pid);
}
