#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("parent pid=%d\n", getpid());
  fork();
  printf("after 1st fork,curr pid=%d\n", getpid());
  fork();
  printf("after 2nd fork,curr pid=%d\n", getpid());

  return EXIT_SUCCESS;
}
