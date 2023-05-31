#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int fd[2];
  char x[1];
  if (pipe(fd) == 0) {
    printf("Pipe Created Successfully\n");
  } else {
    return EXIT_FAILURE;
  }
  if (fork() == 0) {
    char n[1];
    close(fd[1]);
    read(fd[0], n, 1);
    close(fd[0]);
    printf("y=%d\n", (atoi(n) * 3) + 1);
  } else {
    close(fd[0]);
    /* x[0] = '8'; */
    /* write(fd[1], x, 1); */
    write(fd[1], argv[1], 1); // passing the value of x in cmd line
    close(fd[1]);
  }
  return EXIT_SUCCESS;
}
