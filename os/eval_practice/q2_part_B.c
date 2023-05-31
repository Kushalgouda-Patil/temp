#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  if (fork() == 0) {
    execlp("./factorial", "arg0", "4", NULL);
  } else {
    sleep(1);
  }
  return EXIT_SUCCESS;
}
