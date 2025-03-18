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

void traverse_array(const struct Array *array) {
  printf("Array's values.\n");
  for (int i = 0; i < array->size; i++) {
    printf("%d ", array->arr[i]);
  }
  printf("\n");
}

void update_array_status(struct Array *array) {
  array->is_empty = (array->size == 0);
  array->is_full = (array->size == CAPACITY);
  if (array->is_empty) {
    array->first_val = 0;
    array->last_val = 0;
    return;
  }
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
  if (index == 0) {
    insert_at_beginning(array, value);
    return;
  }
  if (index == array->size) {
    insert_at_end(array, value);
    return;
  }
  for (int i = array->size; i > index; i--) {
    array->arr[i] = array->arr[i - 1];
  }
  array->arr[index] = value;
  array->size++;
  update_array_status(array);
}

void delete_at_beginning(struct Array *array) {
  if (array->is_empty) {
    printf("Array is empty\n");
    return;
  }
  for (int i = 0; i < array->size - 1; i++) {
    array->arr[i] = array->arr[i + 1];
  }
  array->size--;
  update_array_status(array);
}

void delete_at_end(struct Array *array) {
  if (array->is_empty) {
    printf("Array is empty\n");
    return;
  }
  array->size--;
  update_array_status(array);
}

void delete_at_mid(struct Array *array, int index) {
  if (array->is_empty) {
    printf("Array is empty\n");
    return;
  }

  if (index >= array->size || index < 0) {
    printf("invalid index\n");
    return;
  }
  if (index == 0) {
    delete_at_beginning(array);
    return;
  }
  if (index == array->size - 1) {
    delete_at_end(array);
    return;
  }
  for (int i = index; i < array->size - 1; i++) {
    array->arr[i] = array->arr[i + 1];
  }
  array->size--;
  update_array_status(array);
}

int linearSearch(struct Array *array, int target) {
  for (int i = 0; i < array->size; i++) {
    if (array->arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int binarySearch(struct Array *array, int target) {
  int start = 0;
  int end = array->size - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (array->arr[mid] == target) {
      return mid;
    } else if (array->arr[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

void bubble_sort(struct Array *array) {
  for (int i = 0; i < array->size - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < array->size - i - 1; j++) {
      if (array->arr[j] > array->arr[j + 1]) {
        int temp = array->arr[j];
        array->arr[j] = array->arr[j + 1];
        array->arr[j + 1] = temp;
        swapped = true;
      }
      if (swapped == false)
        break;
    }
  }
}

int main() {
  struct Array array = {.size = 0, .is_full = false, .is_empty = true};
  create_array(&array);
  traverse_array(&array);
  //  insert_at_beginning(&array, 6969);
  // traverse_array(&array);
  // printf("%d\n", array.size);
  // insert_at_mid(&array, 33, 6);
  bubble_sort(&array);
  traverse_array(&array);
  return 0;
}
