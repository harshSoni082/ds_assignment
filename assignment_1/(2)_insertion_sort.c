// Insertion sort program

#include <stdio.h>

// Function to perform insertion sort iteratively
void insertion_sort(int arr[], int s)
{
  for(int i=1; i<s; i++)
  {
    int j = i - 1;
    int key = arr[i];   // select current element and to place in its correct position
    while((j >= 0)&&(arr[j] > key))
    {
      arr[j+1] = arr[j];    // keep shifing until we find the correct position
      j -= 1;
    }
    arr[j+1] = key;   // place the key at its correct position
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

  // perform insertion sort
  insertion_sort(arr, size);

  // print sorted array
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
