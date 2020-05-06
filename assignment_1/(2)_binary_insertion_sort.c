// Insertion sort using binary search program

#include <stdio.h>

// function to implement binary search
int binary_search(int arr[], int low, int high, int value)
{
  int mid = (int)((low + high) / 2);
  if(high <= low)
  {
    return arr[high] > value ? high : high + 1;
  }
  if(arr[mid] == value)
  {
    return mid;
  }
  else if(arr[mid] > value)
  {
    return binary_search(arr, low, mid-1, value);
  }
  return binary_search(arr, mid+1, high, value);
}

// function to shift array by 1 to the right from start to end idx
void unit_right_shift_arr(int arr[], int start, int end)
{
  for(int i=end; i>start; i--)
  {
    arr[i] = arr[i-1];
  }
}

// Function to perform binary insertion sort iteratively
void binary_insertion_sort(int arr[], int s)
{
  for(int i=1; i<s; i++)
  {
    int key = arr[i];   // select current element and to place in its correct position
    int j = binary_search(arr, 0, i-1, key);
    unit_right_shift_arr(arr, j, i);
    arr[j] = key;     // place the key at its correct position
  }
}

int main()
{
  int size;
  // input array size
  printf("Enter size of array: ");
  scanf("%d", &size);

  // declare int array of giveen size
  int arr[size];

  // initialize declared int array to sort
  printf("Enter array: ");
  for(int i=0; i<size; i++)
  {
    scanf("%d", &arr[i]);
  }

  // perform insertion sort using binary search
  binary_insertion_sort(arr, size);

  // print sorted array
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
