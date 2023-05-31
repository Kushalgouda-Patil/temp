#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (fork() == 0) {
    printf("child process\n");
    exit(0);
  } else {
    printf("parent process\n");
  }
  printf("parent_ process 1\n");

  return EXIT_SUCCESS;
}
