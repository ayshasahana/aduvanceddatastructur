#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *sp=(struct node*)0; //empty stack

void push(int item)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
t->data=item;
t->next=sp;
sp=t;
return;
}

int pop(int *status)
{
struct node *t;
int item;
if(sp==(struct node *)0)
{ 
*status=0;
printf("empty stack");
}
else
{
item=sp->data;
t=sp;
sp=sp->next;
free(t);
*status=1;
return item;
}
}

int search (int item)
{
struct node *t=sp;
int count=0;
while(t!=(struct node *)0)
{
++count;
if(t->data==item)
return count;
t=t->next;
}
return 0;
}


void main ()
{
int item,optn,ans,status;
do
{
printf("\n 1.push\n ");
printf("\n 2.pop \n ");
printf("\n 3.Search \n ");
printf("\n 4.Exit \n ");
printf("\n enter your option :");
scanf("%d",&optn);
switch(optn)
{
case 1:printf("\n Data :");
scanf("%d",&item);
push(item);
printf("inserted %d",item);
break;
case 2: item=pop(&status);
if(status!=0)
printf("Deleted = %d",item);
break;
case 3: printf("Enter the number to search :");
scanf("%d",&item);
ans=search(item);
if(ans==0)
printf("not found");
else
printf("item found at %d node",ans);
break;
case 4: exit(0);
}
}
while(1);
}

