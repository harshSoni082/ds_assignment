// Insertion sort using doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *next;
  struct node *prev;
}node;

node *head = NULL;

// Function to create a node
node *create_node(int key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

// Function to traverse
void traverse()
{
  node *curr_node = head;
  while(curr_node)
  {
    printf("%d<->", curr_node->key);
    curr_node = curr_node->next;
  }
  printf("\n");
}

// function to perform insertion sort using doubly linked list
void dll_insertion_sort()
{
  node *curr_node = head->next;
  node *next_state = curr_node;
  node *tmp = NULL;
  while(curr_node)
  {
    next_state = curr_node->next;

    // remove the node to be correctly placed
    tmp = curr_node->prev;
    tmp->next = curr_node->next;
    if(curr_node->next)
    {
      curr_node->next->prev = tmp;
    }

    // find the correct position of the removed node
    while((tmp)&&(tmp->key > curr_node->key))
    {
      tmp = tmp->prev;
    }
    if(tmp)
    {
      tmp->next->prev = curr_node;
      curr_node->next = tmp->next;
      tmp->next = curr_node;
      curr_node->prev = tmp;
    }
    else
    {
      curr_node->next = head;
      curr_node->prev = NULL;
      head->prev = curr_node;
      head = curr_node;
    }
    curr_node = next_state;
  }
  // free the allocated memory
  free(tmp);
  free(curr_node);
  free(next_state);
}

int main()
{
  int size, key;
  // input array size
  printf("Enter size of array: ");
  scanf("%d", &size);

  node *curr_node = NULL;
  printf("Enter array: ");
  for(int i=0; i<size; i++)
  {
    scanf("%d", &key);
    node *new_node = create_node(key);
    if(!head)
    {
      head = new_node;
      curr_node = head;
    }
    else
    {
      curr_node->next = new_node;
      new_node->prev = curr_node;
      curr_node = curr_node->next;
    }
  }

  // perform insertion sort using doubly linked list
  dll_insertion_sort();

  // print sorted array
  printf("Sorted array: ");
  traverse();
}
