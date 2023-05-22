#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int x = 10;
  if (fork() == 0) {
    x += 10;
    printf("Value of x=%d\n", x); // by child
  } else {
    sleep(5);
    printf("Value of x=%d\n", x); // by parent
  }
  printf("printed by pid=%d\n", getpid()); // printed by both child and parent
  return EXIT_SUCCESS;
}
/* conclusion: value modified by child doesnt affect the parent process  */
