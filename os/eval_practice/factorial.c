#include <stdio.h>
#include <stdlib.h>
int fact(int n) {
  if (n == 1) {
    return 1;
  } else {
    return fact(n - 1) * n;
  }
}
int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  printf("factorial of %d =%d\n", n, fact(n));
  return EXIT_SUCCESS;
}
