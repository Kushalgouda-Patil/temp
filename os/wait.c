#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t p;
  printf("before fork\n");
  p = fork();
  if (p == 0) // child
  {
    printf("I am child having id %d\n", getpid());
    printf("My parent's id is %d\n", getppid());
  } else // parent
  {
    wait(NULL);
    printf("My child's id is %d\n", p);
    printf("I am parent having id %d\n", getpid());
  }
  printf("Common\n");
}
