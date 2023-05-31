#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *thread_function(void *arg);
int num[2] = {3, 5};
int main() {
  pthread_t a_thread;
  void *result;
  pthread_create(&a_thread, NULL, thread_function, (void *)num);
  pthread_join(a_thread, &result);
  printf("Inside Main Program\n");
  printf("thread returned: %s", (char *)result);
}
void *thread_function(void *arg) {
  printf("Inside Thread\n");
  int *x = arg;
  int sum = x[0] + x[1];
  printf("sum is %d\n", sum);
  pthread_exit("sum calculated");
}
