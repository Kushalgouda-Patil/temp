#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int fd[2];
  if (pipe(fd) == 0) {
    printf("Pipe created successfully\n");
  } else {
    printf("Unsuccessfull creation of pipe\n");
    return EXIT_FAILURE;
  }
  if (fork() == 0) {
    close(fd[1]);
    int *y = malloc(sizeof(int) * 3);
    read(fd[0], y, sizeof(int) * 3);
    close(fd[0]);
    printf("average=%d\n",(y[0]+y[1]+y[2])/3);
  } else {
    close(fd[0]);
    int x[] = {4,2,1};
    write(fd[1], x, sizeof(int) * 3);
    close(fd[1]);
  }
  return EXIT_SUCCESS;
}
