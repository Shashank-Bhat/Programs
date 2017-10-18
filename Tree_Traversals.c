#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
}NODE;
typedef struct tree
{
  NODE *root;
}TREE;
NODE *makenode()
{
  NODE *tmp;
  int n;
  tmp = (NODE*)malloc(sizeof(NODE));
  printf("Enter data\n");
  scanf("%d",&n);
  tmp->data = n;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
void BST(TREE *t)
{
  t->root = NULL;
  NODE *tmp,*p,*q;
  int n;
  t->root = makenode();
  do
  {
    tmp = makenode();
    p = t->root;
    q=NULL;
    while(p!=NULL && p->data!=tmp->data)
    {
      q = p;
      if(tmp->data < p->data)
        p=p->left;
      else
        p=p->right;
    }
    if(p==NULL)
    {
      if(tmp->data<q->data)
         q->left=tmp;
       else
         q->right=tmp;
    }
    printf("Continue\n");
    scanf("%d",&n);
  }while(n==1);
}
void inord(TREE *t)
{
  printf("Inorder traversal is\n");
  inord_t(t->root);
}
void inord_t(NODE *r)
{
   if(r==NULL)
     return;
   inord_t(r->left);
   printf("%d  ",r->data);
   inord_t(r->right);
}
void preord(TREE *t)
{
  printf("Preorder traversal is\n");
  preord_t(t->root);
}
void preord_t(NODE *r)
{
   if(r==NULL)
     return;
   printf("%d  ",r->data);
   preord_t(r->left);
   preord_t(r->right);
}
void postord(TREE *t)
{
  printf("Postorder traversal is\n");
  postord_t(t->root);
}
void postord_t(NODE *r)
{
   if(r==NULL)
     return;

   postord_t(r->left);
   postord_t(r->right);
   printf("%d  ",r->data);
}

int main()
{
  int n;
  TREE tree;
  BST(&tree);
  inord(&tree);
  printf("\n");
  preord(&tree);
  printf("\n");
  postord(&tree);
  printf("\n");
  return 0;
}
