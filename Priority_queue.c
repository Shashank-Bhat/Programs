#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct heap
{
  int a[10];
  int n;
}HEAP;
void EnQ(HEAP *h)
{
  int ele;
  int s,f;
  if(h->n == MAX-1)
  {
    printf("Overflow\n");
    return;
  }
  else
  {
    printf("Enter an element\n");
    scanf("%d",&ele);
    s = h->n;
    f = (s-1)/2;
    while(s>0 && h->a[f] > ele)
    {
      h->a[s] = h->a[f];
      s = f;
      f = (s-1)/2;
    }
    h->a[s] = ele;
    h->n++;
   } 
}
void DeQ(HEAP *h)
{
  int s,f;
  if(h->n == 0)
  {
    printf("Underflow\n");
    return;
  }
  int ele = h->a[h->n-1];
  f = 0;
  if(h->n == 1)
    s = -1;
  else
    s = 1;
  if(h->n >2 && h->a[2]<h->a[1])
    s = s+1;
  while(s>=0 && h->a[s] <ele)
  {
    h->a[f] = h->a[s];
    f  = s;
    s = 2*f +1;
    if(s <=h->n-2&& h->a[s+1] > h->a[s])
        s=s+1;
    if(s>h->n-2)
      s = -1;
  }
  h->a[f] = ele;
  h->n--;
}
void display(HEAP *h)
{
  for(int i=0;i<h->n;i++)
     printf("%d ",h->a[i]);
  printf("\n");
}
int main()
{
  HEAP h;
  int n;
do{
  printf("1.Enq\n2.DeQ\n3.Display\nEnter your choice\n");
  scanf("%d",&n);
  switch(n)
  {
    case 1:
          EnQ(&h);
          break;
    case 2:
          DeQ(&h);
          break;
    case 3:
          display(&h);
          break;
    default:
          exit(0);
  }
  }while(n<=3);
}
