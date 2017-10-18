#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;
typedef struct head
{
  NODE *head,*rear;
}LIST;
void create(LIST *l)
{
  NODE *tmp;
  tmp = (NODE*)malloc(sizeof(NODE));
  l->head = NULL;
  l->rear = NULL;
  
}
void Enq(LIST *l,int ele)
{
  NODE *tmp,*p;
  tmp = (NODE*)malloc(sizeof(NODE));
  tmp->data = ele;
  tmp->next = NULL;
  p = l->head;
  if(p == NULL)
  {
   l->head = tmp;
   tmp->next = l->head;
  }
  else
    l->rear->next = tmp;
  l->rear = tmp;
  l->rear->next = l->head;
}
void rem(LIST *l)
{ 
  int d;
  if(l->head == NULL){
    printf("Q is empty\n");
    return;}
  if(l->head == l->rear)
  {
    d = l->head->data;
    free(l->head);
    l->head = NULL;
    l->rear = NULL;
  }
  else{
  NODE *tmp;
  tmp = l->head;
  l->head = l->head->next;
  l->rear->next = l->head;
  free(tmp);
 }
}

void disp(LIST *l)
{
  NODE *p = l->head;
  printf("\nThe list is\n");
  if(l->head == NULL)
    printf("Empty\n");
  else
  {
    while(p->next!=l->head)
    {
       printf("%d ",p->data);
       p=p->next;
    }
    printf("%d\n",p->data);
  }
}

int main()
{
  LIST *l;
  l->head;
  create(&l);
  int ch,ele,res,n,n1;
  
  do
  {
    printf("1.Add\n2.Remove\n3.Disp\n");
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
           rem(&l);
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
