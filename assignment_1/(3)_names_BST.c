// Construct a BST consisting of following names -
//    Arthi, Christy, Dorothy, Fraser, Eliza
// Insert name David in the BST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for a node of BST
typedef struct node
{
  char *key;
  struct node *left;
  struct node *right;
}node;

// function to create a node of BST
node *create_node(char *key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = (char *)malloc(sizeof(key));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// function to insert a node in created BST
node *insert(node *root, char *key)
{
  if(!root)
  {
    root = create_node(key);
  }
  else
  {
    if(strcmp(key, root->key) < 0)
    {
      if(!root->left)
      {
        root->left = create_node(key);
        return NULL;
      }
      insert(root->left, key);
    }
    else
    {
      if(!root->right)
      {
        root->right = create_node(key);
        return NULL;
      }
      insert(root->right, key);
    }
  }
  return root;
}

// function to perform inorder traversal for the created BST
void inorder_traversal(node *root)
{
  if(root)
  {
    inorder_traversal(root->left);
    printf("%s, ", root->key);
    inorder_traversal(root->right);
  }
}

int main()
{
  // initialize char * for given names
  char *names[] = {"Arthi", "Christy", "Dorothy", "Fraser", "Eliza"};
  char *ins_nme = "David";    // name to be inserted after createing the BST

  node *root = NULL;

  // create BST
  for(int i=0; i<5; i++)
  {
    if(i == 0)
    {
      root = insert(root, names[i]);
    }
    else
    {
      insert(root, names[i]);
    }
  }
  printf("Inorder traverser of BST before inserting \"David\" - \n");
  inorder_traversal(root);
  printf("\n\n");

  insert(root, ins_nme);
  printf("Inorder traverser of BST after inserting \"David\" - \n");
  inorder_traversal(root);
  printf("\n");
}
