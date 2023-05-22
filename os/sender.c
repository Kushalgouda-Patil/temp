#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  int res, n;
  res = open("fifo1", O_WRONLY);
  write(res, "", 7);
  printf("Sender Process %d sent the data\n", getpid());
}
