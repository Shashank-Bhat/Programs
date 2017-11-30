#include<stdio.h>
#include<stdlib.h>
typedef struct hash
{
  int ar[15];
}HASH;
void hash(HASH *h,int ar2[])
{
   for(int i=0;i<15;i++)
      h->ar[i] = -1;
   for(int i=0;i<10;i++)
   {
      if(h->ar[ar2[i]]!=-1)
      {
         printf("Collision detected\n");
         int i = ar2[i];
         for(;i<15;i++)
         {
           if(h->ar[i]==-1)
             h->ar[i] = ar2[i];
         }
      }
      else
        h->ar[ar2[i]] = ar2[i];
   }
   printf("Hash table is\n");
   for(int i=0;i<15;i++)
   {
    if(h->ar[i] == -1)
     continue;
    else
     printf("%d ",h->ar[i]);
   }
}
int main()
{
  HASH h;
  int ar[10] = {11,12,13,14,15,16,17,18,19,20};
  int ar2[10];
  int sum=0;
  int d;
  for(int i=0;i<10;i++)
  {
    while(ar[i]!=0)
    {
      d = ar[i]%10;
      sum+=d;
      ar[i]/=10;
    }
    ar2[i] = sum;
    sum=0;
  }
  hash(&h,ar2);
 return 0;
}
 

