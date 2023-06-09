/* Date : 7/06/23
   Title : Binary Search Tree operations in C
*/

#include <stdio.h>
#include <stdlib.h>

FILE *fpin, *fp_in, *fp_pre, *fp_post;

struct node
{
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root)
{
  if (root != NULL)
    {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);
    fprintf(fp_in,"%d ",root->key);

    // Traverse right
    inorder(root->right);
  }
}

// preorderTraversal traversal
void preorderTraversal(struct node* root)
{
  if (root == NULL) return;
  printf("%d ->", root->key);
  fprintf(fp_pre,"%d ",root->key);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// postorderTraversal traversal
void postorderTraversal(struct node* root)
{
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->key);
  fprintf(fp_post,"%d ",root->key);
}


// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void random(int n)            // to generate random numbers
{  int v;
    FILE *fp;
fp=fopen("input.txt","w");
for(int i=0;i<n;i++)
{
    v=rand()%(100-0);
    fprintf(fp,"%d ",v);
}
fclose(fp);
}


// Driver code
int main()
{
  fpin=fopen("input.txt","r");
  int n,choice,data, count=0;
  struct node *root = NULL;
  printf("Enter the number of random numbers to be generated\n");
  scanf("%d",&n);
  random(n);
  while(1)
  {
      printf("1.Insert\n2.Inorder Traverse\n3.Preorder Traverse\n4.Postorder Traverse\n5.Exit\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1 : count++;
                   if(count>n)
                   {
                       printf("\nNo elements at the input file to add on to the tree\n");
                       break;
                   }
                   else
                   {
                   fscanf(fpin,"%d ",&data);
                   root = insert(root,data);
                   }
          break;
          case 2 :fp_in=fopen("inorder.txt","w");
                  printf("Inorder traversal: ");
                   inorder(root);
                   fclose(fp_in);
                   printf("\n");
          break;
          case 3 :fp_pre=fopen("pre_order.txt","w");
                  printf("Pre order traversal: ");
                   preorderTraversal(root);
                   fclose(fp_pre);
                   printf("\n");
          break;
          case 4 :fp_post=fopen("post_order.txt","w");
                  printf("Post order traversal: ");
                   postorderTraversal(root);
                   fclose(fp_post);
                   printf("\n");
          break;
          case 5 : fclose(fpin);
                   exit(0);
          default : printf("Invalid choice\n");

      }
  }
  return 0;

}
