#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;
typedef struct head
{
  NODE *head;
}LIST;
void create(LIST *l)
{
  NODE *tmp;
  tmp = (NODE*)malloc(sizeof(NODE));
  int el;
  printf("Enter the first element of the linked list\n");
  scanf("%d",&el);
  l->head->data = el;
  l->head->next=NULL;
}
void push(LIST *l,int ele)
{
  NODE *tmp,*p;
  tmp = (NODE*)malloc(sizeof(NODE));
  tmp->data = ele;
  tmp->next = l->head;
  l->head = tmp;
}
void pop(LIST *l)
{
  NODE *tmp;
  tmp = l->head;
  l->head = l->head->next;
  free(tmp);
}

void disp(LIST *l)
{
  NODE *p = l->head;
  printf("\nThe list is\n");
  if(l->head == NULL)
    printf("Empty\n");
  else
  {
    while(p!=NULL)
    {
       printf("%d ",p->data);
       p=p->next;
    }
    printf("\n\n");
  }
}
void rev(LIST *l)
{
  NODE *cur,*prev,*next;
  cur = l->head;
  prev = NULL;
  while(cur!=NULL)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  l->head = prev;
}
int main()
{
  LIST *l;
  l->head;
  create(&l);
  int ch,ele,res,n,n1;
  
  do
  {
    printf("1.Push\n2.Pop\n3.Disp\n4.Rev\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
            printf("Enter ele\n");
            scanf("%d",&ele);
            push(&l,ele);
            break;
       case 2:
           pop(&l);
           break;
      case 3:
          disp(&l);
          break;
      case 4:
          rev(&l);
          break;
   }
 }while(ch<5);
return 0;
}
