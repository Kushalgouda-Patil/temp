#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  printf("PID of example.c = %d\n", getpid());
  char *args[] = {"Hello", "C", "Programming", NULL};
  execv("./hello", args);
  printf("Back to example.c");
  return 0;
}
