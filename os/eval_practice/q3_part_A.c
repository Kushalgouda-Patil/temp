#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct s1 {
  int *arr;
  int end;
  int key;
};
void *sorting(void *arg) {
  struct s1 *ptr = (struct s1 *)arg;
  int *arr = ptr->arr;
  int end = ptr->end;
  int i, key, j;
  /* insertion sort */
  for (i = 1; i < end; i++) {
    key = arr[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
void *search(void *arg) {
  struct s1 *ptr = (struct s1 *)arg;
  int *arr = ptr->arr;
  int end = ptr->end;
  int key = ptr->key;
  int i;
  /* linear search */
  for (i = 0; i < end; i++) {
    if (arr[i] == key) {
      printf("Found at index=%d\n", i);
    } else {
      continue;
    }
  }
}
void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
int main(int argc, char *argv[]) {
  pthread_t t1, t2;
  int arr[] = {2, 3, 1, 4};
  struct s1 argument;
  argument.arr = arr;
  argument.end = 4;
  argument.key = 3;
  pthread_create(&t1, NULL, sorting, &argument);
  pthread_join(t1, NULL);
  printArray(arr, 4);
  pthread_create(&t2, NULL, search, &argument);
  pthread_join(t2, NULL);
  return EXIT_SUCCESS;
}
