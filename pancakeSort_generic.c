#include <stdio.h>

#define length_of_array(array) sizeof(array) / sizeof(array[0])

static int reverse_times = 0;

// todo: use generic for c
int reverse_array(void *array, size_t len, size_t elem_byte_size,
                  int (*swap_function)(const void *a, const void *b)) {
  size_t i;
  for (i = 0; i < len / 2; i++) {
    swap_function(((char *)array + i * elem_byte_size),
                  ((char *)array + (len - i - 1) * elem_byte_size));
  }
  return 0;
}

int find_max_elem(void *array, size_t len, size_t elem_byte_size,
                  int (*compare_function)(const void *a, const void *b)) {
  size_t max_elem = 0;
  size_t i;
  for (i = 0; i < len; i++) {
    if (compare_function((char *)array + max_elem * elem_byte_size,
                         (char *)array + i * elem_byte_size) < 0) {
      max_elem = i;
    }
  }
  return max_elem;
}

int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int swap_int(const void *a, const void *b) {
  int temp = *(int *)a;
  *(int *)a = *(int *)b;
  *(int *)b = temp;
  return 0;
}

#if defined no_rec_imp

int pancakeSort(int *unsorted_array, int sort_start, int sort_end) { return 0; }
#else

int pancakeSort(void *unsorted_array, size_t len, size_t elem_byte_size,
                int (*compare_function)(const void *a, const void *b)) {
  return 0;
}

#endif

int main() {
  int array1[] = {5, 2, 1, 0, 3, 2, 9}; // {5,2,1,0,3,2*,9} => {0,1,2,2*,3,5,9}
  int i;

  printf("before sort: ");
  for (i = 0; i < length_of_array(array1); i++)
    printf("%d ", array1[i]);
  printf("\n");

  printf("max_elem:%d\n",
         find_max_elem(array1, length_of_array(array1), sizeof(int) / sizeof(char),
                       compare_int));

  reverse_array(array1, length_of_array(array1), sizeof(int) / sizeof(char),
                swap_int);

  printf("after sort:  ");
  for (i = 0; i < length_of_array(array1); i++)
    printf("%d ", array1[i]);
  printf("\n");
  printf("max_elem:%d\n",
         find_max_elem(array1, length_of_array(array1), sizeof(int) / sizeof(char),
                       compare_int));
}
