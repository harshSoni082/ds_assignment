// Merge sort program

#include <stdio.h>
#include <limits.h>   // for INT_MAX

// funciton to copy one array to another
void copy_arr(int src[], int dest[], int start, int s, int include_sentinal)
{
  int i = start;
  int j = 0;
  for(i=start, j=0; j<s-include_sentinal; i++, j++)
  {
    dest[j] = src[i];
  }
  if(include_sentinal)
  {
    dest[j] = INT_MAX;
  }
}

void merge(int arr[], int low, int mid, int high)
{
  int l = mid - low + 2;    // size for left half array + 1 extra for sentinal
  int r = high - mid + 1;       // size for right half array + 1 extra for sentinal
  int L[l], R[r];

  // copy array in L and R array respectively
  copy_arr(arr, L, low, l, 1);
  copy_arr(arr, R, mid+1, r, 1);

  int i = low;
  int j = 0;
  int k = 0;
  while(i <= high)
  {
    if((j < l)&&(L[j] < R[k]))
    {
      arr[i] = L[j++];
    }
    else if((k < r)&&(L[j] >= R[k]))
    {
      arr[i] = R[k++];
    }
    i += 1;
  }
}

// Function to perform merge sort recursively
void merge_sort(int arr[], int low, int high)
{
  if(low < high)
  {
    int mid = (int)((low + high) / 2);    // find mid idx
    merge_sort(arr, low, mid);      // divide until 1 element is found
    merge_sort(arr, mid+1, high);   // divide until 1 element is found
    merge(arr, low, mid, high);     // merge while sorting from left and right half
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

  // perform merge sort
  merge_sort(arr, 0, size-1);

  // print sorted array
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
