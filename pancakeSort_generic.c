#include <stdio.h>

#define sizeof_array(array) sizeof(array) / sizeof(array[0])

static int reverse_times = 0;

// todo: use generic for c
int reverse_array(int *array, int start, int end) {
  size_t i, j;
  int temp;
  for (i = start, j = end; i < j; i++, j--) {
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
  return 0;
}

int find_max_elem(int *array, int start, int end) {
  int i;
  int max_elem = start;
  for (i = start + 1; i <= end; i++) {
    if (array[max_elem] < array[i]) {
      max_elem = i;
    }
  }
  return max_elem;
}

#if defined no_rec_imp

int pancakeSort(int *unsorted_array, int sort_start, int sort_end) { return 0; }
#else

int pancakeSort(int *unsorted_array, int start, int end) {
  int max_elem = find_max_elem(unsorted_array, start, end);
  if (start == end) {
    return 0;
  }
  reverse_array(unsorted_array, start, max_elem);
  /*
  reverse_times++;
  printf("the %d times reverse:",reverse_times);
  for(int i = start;i<=end;i++)
    printf("%d ",unsorted_array[i]);
  printf("\n");
  */
  reverse_array(unsorted_array, start, end);
  pancakeSort(unsorted_array, start, end - 1);
  /*
  reverse_times++;
  printf("the %d times reverse:",reverse_times);
  for(int i = start;i<=end;i++)
    printf("%d ",unsorted_array[i]);
  printf("\n");
  */
  return 0;
}

#endif

int main() {
  int array1[] = {5, 2, 1, 0, 3, 2, 9}; // {5,2,1,0,3,2*,9} => {0,1,2,2*,3,5,9}
  int i;

  printf("before sort: ");
  for (i = 0; i < sizeof_array(array1); i++)
    printf("%d ", array1[i]);
  printf("\n");

  pancakeSort(array1, 0, sizeof_array(array1) - 1);

  printf("after sort:  ");
  for (i = 0; i < sizeof_array(array1); i++)
    printf("%d ", array1[i]);
  printf("\n");
}
