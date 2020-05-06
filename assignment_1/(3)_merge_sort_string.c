// Sort in increasing order strings  -
//   (a) Polynomial
//   (b) Test Case
//   Using merge sort

#include <stdio.h>
#include <limits.h>   // for INT_MAX
#include <ctype.h>    // for tolower()
#include <string.h>   // for string related functions

// funciton to copy one stray to another
void copy_str(char *src, char *dest, int start, int s, int include_sentinal)
{
  int i = start;
  int j = 0;
  for(i=start, j=0; j<s-include_sentinal; i++, j++)
  {
    dest[j] = src[i];
  }
  if(include_sentinal)
  {
    dest[j] = '\0';
  }
}

void merge(char *str, int low, int mid, int high)
{
  int l = mid - low + 2;    // size for left half stray + 1 extra for sentinal
  int r = high - mid + 1;   // size for right half stray + 1 extra for sentinal
  char L[l], R[r];

  // copy stray in L and R stray respectively
  copy_str(str, L, low, l, 1);
  copy_str(str, R, mid+1, r, 1);

  int i = low;
  int j = 0;
  int k = 0;
  while(i <= high)
  {
    if((L[j] != '\0')&&(((int)tolower(L[j]) < (int)tolower(R[k]))||(R[k] == '\0')))
    {
      str[i] = L[j++];
    }
    else if((R[k] != '\0')&&(((int)tolower(L[j]) >= (int)tolower(R[k]))||(L[j] == '\0')))
    {
      str[i] = R[k++];
    }
    i += 1;
  }
}

// Function to perform merge sort recursively
void merge_sort(char *str, int low, int high)
{
  if(low < high)
  {
    int mid = (int)((low + high) / 2);    // find mid idx
    merge_sort(str, low, mid);      // divide until 1 element is found
    merge_sort(str, mid+1, high);   // divide until 1 element is found
    merge(str, low, mid, high);     // merge while sorting from left and right half
  }
}

int main()
{
  char str_1[] = "Polynomial";
  char str_2[] = "Test Case";

  // sort strings using merge sort
  merge_sort(str_1, 0, strlen(str_1)-1);
  merge_sort(str_2, 0, strlen(str_2)-1);

  printf("\n");
  printf("NOTE: This sorting is not case sensitive");
  printf("\n\n");

  // print sorted string
  printf("Sorted string for \"Polynomial\": %s", str_1);
  printf("\n");
  printf("Sorted string for \"Test Case\": %s", str_2);
  printf("\n");

  return 0;
}
