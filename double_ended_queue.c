#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;
typedef struct list
{
   NODE* head;
}LIST;
void create(LIST *l)
{
  l->head = NULL;
  return;
}
void EnQ(LIST *l)
{
  NODE *tmp;
  int n;
  tmp = (NODE*)malloc(sizeof(NODE));
  printf("Enter data\n");
  scanf("%d",&n);
  tmp->data = n;
  tmp->next = NULL;
  NODE *p = l->head;
  if(l->head == NULL)
    l->head = tmp;
  else
  {
     while(p->next!=NULL)
       p = p->next;
     p->next = tmp;
  }
  return;
}
void Append(LIST *l)
{
  NODE *tmp;
  int n;
  tmp = (NODE*)malloc(sizeof(NODE));
  printf("Enter data\n");
  scanf("%d",&n);
  tmp->data = n;
  tmp->next = NULL;
  if(l->head == NULL)
    l->head = tmp;
  else
  {
    tmp->next = l->head;
    l->head = tmp;
  }
}
void Rem1(LIST *l)
{
  NODE *tmp = l->head;
  NODE *p = l->head;
  if(tmp == NULL)
  {
    return;
  }
  while(tmp->next!=NULL)
  {
    p = tmp;
    tmp = tmp->next;
  }
  p->next = NULL;
  free(tmp);
}
void Rem2(LIST *l)
{
  NODE *tmp = l->head;
  if(l->head == NULL)
   {
     printf("Underflow\n");
     return;
   }
   else if(l->head->next == NULL)
   {
     free(tmp->next);
     l->head = NULL;
   }
   else
   {
     l->head = l->head->next;
     free(tmp);
   }
}
void display(LIST *l)
{
  NODE *tmp = l->head;
  while(tmp!=NULL) 
  {
     printf("%d ",tmp->data);
     tmp = tmp->next;
  }
  printf("\n");
}
int main()
{
  int ch;
  LIST l;
  create(&l);
do{
  printf("1.EnQ\n2.Append\n3.Delete last element\n4.Delete first element\n5.Display\nEnter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
          EnQ(&l);
          break;
    case 2:
          Append(&l);
          break;
    case 3:
          Rem1(&l);
          break;
    case 4: 
          Rem2(&l);
          break;
    case 5:
          display(&l);
          break;
    default:
          exit(0);
  }
 }while(ch<=5);
}

  
    


