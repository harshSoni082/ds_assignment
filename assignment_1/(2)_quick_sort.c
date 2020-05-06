// Quick sort program

#include <stdio.h>

// Function to swap two numbers in an array
void swap(int arr[], int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

// Function to perform partitioning.
int partition(int arr[], int low, int high)
{
  int i = low - 1;
  int x = arr[high];   // select the pivot to partition

  for(int j=low; j<high; j++)
  {
    if(arr[j] < x)
    {
      swap(arr, ++i, j);
    }
  }
  swap(arr, ++i, high);

  return i;
}

// Function to perform quick sort recursively
void quick_sort(int arr[], int low, int high)
{
  if(low < high)
  {
    int partitioning = partition(arr, low, high);
    quick_sort(arr, low, partitioning-1);
    quick_sort(arr, partitioning+1, high);
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

  // perform quick sort
  quick_sort(arr, 0, size-1);

  // print sorted array
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
