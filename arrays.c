#include <stdbool.h>
#include <stdio.h>

#define CAPACITY 10

struct Array {
  int arr[CAPACITY];
  int size;
  bool is_full;
  bool is_empty;
  int first_val;
  int last_val;
};

void print_array(const struct Array *array) {
  printf("Array's values.\n");
  for (int i = 0; i < array->size; i++) {
    printf("%d ", array->arr[i]);
  }
  printf("\n");
}

void update_array_status(struct Array *array) {
  array->is_empty = (array->size == 0);
  array->is_full = (array->size == CAPACITY);
  if (array->size > 0) {
    array->first_val = array->arr[0];
    array->last_val = array->arr[array->size - 1];
  }
}

void create_array(struct Array *array) {
  int size;
  printf("Enter the number of values you want to put in array.\n");
  scanf("%d", &size);

  if (size < 0 || size > CAPACITY) {
    printf("invalid size, must be between 0 and %d\n", CAPACITY);
    return;
  }
  array->size = size;
  printf("Enter array's values.\n");
  for (int i = 0; i < array->size; i++) {
    scanf("%d", &array->arr[i]);
  }
  update_array_status(array);
}

void insert_at_beginning(struct Array *array, int value) {
  if (array->is_full) {
    printf("Array is full!\n");
    return;
  }
  for (int i = array->size; i > 0; i--) {
    array->arr[i] = array->arr[i - 1];
  }
  array->arr[0] = value;
  array->size++;

  update_array_status(array);
}

void insert_at_end(struct Array *array, int value) {
  if (array->is_full) {
    printf("array is full!\n");
    return;
  }
  array->arr[array->size++] = value;
  update_array_status(array);
}

void insert_at_mid(struct Array *array, int value, int index) {
  if (index > array->size || index < 0) {
    printf("invalid index\n");
    return;
  }
  if (array->is_full) {
    printf("array is full!\n");
    return;
  }
  if (index == array->size) {
    insert_at_end(array, value);
    return;
  }
  if (index == 0) {
    insert_at_beginning(array, value);
    return;
  }
  for (int i = array->size; i > index; i--) {
    array->arr[i] = array->arr[i - 1];
  }
  array->arr[index] = value;
  array->size++;
  update_array_status(array);
}

int main() {
  struct Array array = {.size = 0, .is_full = false, .is_empty = true};
  create_array(&array);
  print_array(&array);
  insert_at_beginning(&array, 6969);
  print_array(&array);
  printf("%d\n", array.size);
  insert_at_mid(&array, 33, 6);
  print_array(&array);
  return 0;
}
