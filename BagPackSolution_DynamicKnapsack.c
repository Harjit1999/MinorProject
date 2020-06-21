#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct bag
{ int id;
  char items[13];
  int price;
  int weight;
   }b2[MAX],b[MAX],b3[MAX];
void fracknap(int n);
void dynaknap(int W,struct bag b[],int n);
int max(int a,int b);
void Maximum(int,int);
int rec=0,size=0;
int main()
 {
     int C,d,n,n_items=0;
 FILE *fp;
 char s[1200];
 fp=fopen("test.txt","r");
 int i=1,j=0,k=0,l=0,m=0;
 if(fp==NULL)
 {
 printf("cant open it");

 exit(1);}
while(fgets(s,1200,fp)!=NULL)
{
    char *token=strtok(s,",");
    while(token!=NULL)
 {
     if(i%4==1)
     {
         b2[j].id=atoi(token);
         j++;
     }
     else if(i%4==2)
     {
         strcpy(b2[k].items,token);

         k++;
     }
     else if(i%4==3)
     {
         b2[l].price=atoi(token);
         l++;
     }
     else if(i%4==0)
     {
         b2[m].weight=atoi(token);
         m++;
         n_items++;
     }

     token=strtok(NULL,",");
     i++;
 }

}
printf("Total Items Are: ");
for(int i=0;i<n_items;i++)
 {
  printf("\n%d %s %d %d",b2[i].id,b2[i].items,b2[i].price,b2[i].weight);//
 }

fclose(fp);
printf("\n\nThe Number of Items are : ");
printf("\n%d",n_items);
 printf("\nEnter The Capacity of Bag\n");
  scanf("%d",&C);
  printf("\nIf Items are Repeated then:\n  Press 1 for YES\n    otherwise\n  Press 2 for NO\n");
  scanf("%d",&d);
  switch(d)
  {
   case 1:

     {
        fracknap(n_items);
        dynaknap(C,b3,size);
     }

          break;
   case 2:

          dynaknap(C,b2,n_items);

               break;
    default:
         printf("Sorry Invalid!!\nEnter  1 or 2 only.");
         break;
     }
 return 0;
}
void fracknap(int n)
 {  int k;
   k=rec;
    while(rec<n)
    {
        if(b2[rec].id==b2[rec+1].id)
        {
            rec++;
        }
        else{
            Maximum(k,rec);
            rec++;
            k=rec;

        }
    }
    for(int j=0;j<size;j++)
    {
       printf("\nValue:\n%d %s %d %d\n",b3[j].id,b3[j].items,b3[j].price,b3[j].weight);
    }
 }
 void Maximum(int k,int rec)
 {
     int j,max=0,value,c;
     max=b2[k].price/b2[k].weight;
     for(j=k;j<=rec;j++)
    {
           value=b2[j].price/b2[j].weight;
           if(value>=max)
        {
           max=value;
           c=j;
       }
        }
               b3[size].id=b2[c].id;
               strcpy(b3[size].items,b2[c].items);
               b3[size].price=b2[c].price;
               b3[size].weight=b2[c].weight;

               size++;
 }

void dynaknap(int W,struct bag b[],int n)
 {
     int i,w;
     int k[n+1][W+1];

    for (w=0;w<=W;w++)
    {
     k[0][w]=0;
     }

   for (i=0;i<=n;i++){
     k[i][0]=0;
    }

     for(i=1; i<=n; i++)
     {
        for (w=0;w<=W;w++)
       {
        if(b[i-1].weight>w)
        {
           k[i][w]=k[i-1][w];
      }
     else
       {
       k[i][w]=max(b[i-1].price+k[i-1][w-b[i-1].weight],k[i-1][w]);

       }

}
}
  w=W;
  printf("\nn=%d W=%d\n",n,W);
  printf("\n%d",k[n][W]);
  printf("\nitems are\n");
  while(n>0 && w>0)
  {
    if(k[n][w]==k[n-1][w])
     {
        n--;
        continue;
    }
   else

    {
      printf("%s\n",b[n-1].items);
      w=W-b[n-1].weight;
      W=w;
      n--;
      }
}
 }


int max(int a,int b)
 {
  return (a>b)?a:b;
  }

