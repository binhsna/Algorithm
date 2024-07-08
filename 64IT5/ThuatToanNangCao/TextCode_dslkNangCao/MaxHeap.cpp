#include <stdio.h>
int size = 0;
void swap_node(int *a, int *b)
{
  int c = *b;
  *b = *a;
  *a = c;
}
void heapify_tree(int arr[], int size, int i)
{
  if (size == 1)
  {
    printf("Có 1 phan tu trong cây!");
  }
  else
  {
    int biggest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[biggest])
      biggest = l;
    if (r < size && arr[r] > arr[biggest])
      biggest = r;
    if (biggest != i)
    {
      swap_node(&arr[i], &arr[biggest]);
      heapify_tree(arr, size, biggest);
    }
  }
}
void add_node(int arr[], int new_data)
{
  if (size == 0)
  {
    arr[0] = new_data;
    size += 1;
  }
  else
  {
    arr[size] = new_data;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify_tree(arr, size, i);
    }
  }
}
void remove_node(int arr[], int data)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (data == arr[i])
      break;
  }
  swap_node(&arr[i], &arr[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify_tree(arr, size, i);
  }
}
void print(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}
int main()
{
  int arr[10];
  add_node(arr, 4);
  add_node(arr, 6);
  add_node(arr, 10);
  add_node(arr, 7);
  add_node(arr, 3);
  printf("Max-Heap: ");
  print(arr, size);
  remove_node(arr, 4);
  printf("\n");
  print(arr, size);
}
