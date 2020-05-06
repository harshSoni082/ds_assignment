// Bubble sort program

#include <stdio.h>

// Function to swap two numbers in an array
void swap(int arr[], int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

// Function to perform bubble sort iteratively
void bubble_sort(int arr[], int s)
{
  for(int i=0; i<s; i++)
  {
    for(int j=0; j<s-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap(arr, j , j+1);   // swap numbers to put them in order
      }
    }
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

  // perform bubble sort
  bubble_sort(arr, size);

  // print sorted array
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
