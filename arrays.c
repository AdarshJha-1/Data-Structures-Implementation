#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 100

struct Array {
  int arr[CAPACITY];
  int size;
  bool is_full;
  int first_val;
  int last_val;
};

// Function to print array values
void print_array(struct Array array) {
  printf("Array's values.\n");
  for(int i = 0; i < array.size; i++) {
    printf("%d ", array.arr[i]);
  }
  printf("\n");
}

// Function to set array values
void set_array_value(struct Array *array) {
  printf("Enter array's values.\n");
  for(int i = 0; i < array->size; i++) {
    scanf("%d", &array->arr[i]);
  }
}

void insert_at_beginning(struct Array *array) {
  for(int i = array->size; i >= 0; i--) {
    array->arr[i] = array->arr[i-1];
  }
}

int main() {
  int size;
  printf("Enter the number of values you want to put in array.\n");
  scanf("%d", &size);
  struct Array array;
  array.size = size;

  set_array_value(&array);
  print_array(array);
  return 0;
}
