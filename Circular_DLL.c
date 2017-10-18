#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
   struct node *prev;
}NODE;
typedef struct list
{
  NODE *head;
  NODE *tail;
}LIST;
void create(LIST *l)
{
  l->head=NULL;
  l->tail=NULL;
}
void Enq(LIST *l,int ele)
{
  NODE *tmp;
  tmp = (NODE*)malloc(sizeof(NODE));
  tmp->data = ele;
  tmp->prev = NULL;
  tmp->next = NULL;
  if(l->head==NULL)
  {
    l->head=tmp;
    l->tail=tmp;
    tmp->next=l->head;
  }
  else
  {
    tmp->prev = l->tail;
    tmp->next=l->tail->next;
  }
  l->tail->next = tmp;
  l->tail = tmp;
}
void Deq(LIST *l)
{
  NODE *tmp = l->head;
  if(l->head == NULL)
  {
    printf("Underflow\n");
    return;
  }
  if(l->head == l->tail)
  {
    free(tmp);
    l->head = NULL;
    l->tail = NULL;
    return;
  }

  l->head = l->head->next;
  free(tmp);
  l->head->prev=NULL;
  l->tail->next = l->head;
}
void disp(LIST *l)
{
  printf("The list is: \n");
  NODE *tmp = l->head;
  if(l->head == NULL)
  {
    printf("Empty\n");
    return;
  }
  while(tmp->next!=l->head)
  {
     printf("%d ",tmp->data);
     tmp = tmp->next;
  }
  printf("%d",tmp->data);
  printf("\n");
}

int main()
{
  LIST *l;
  create(&l);
  int ch,ele,n,n1;
  do
  {
    printf("1.Enq\n2.Deq\n3.Disp\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
            printf("Enter ele\n");
            scanf("%d",&ele);
            Enq(&l,ele);
            break;
       case 2:
           Deq(&l);
           break;
      case 3:
          disp(&l);
          break;
     default:
         exit(0);
   }
 }while(ch<4);
return 0;
}

  

