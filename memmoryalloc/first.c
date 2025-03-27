#include<stdio.h>
int main()
{
int bno,pno,bs[20],ps[20],i,j;
printf("Enter no of Blocks.\n");
scanf("%d",&bno);
for(i=0;i<bno;i++)
{
printf("Enter the %dst Block size:",i);
scanf("%d",&bs[i]);
}
printf("Enter no of Process.\n");
scanf("%d",&pno);
for(i=0;i<pno;i++)
{
printf("Enter the size of %dst Process:",i);
scanf("%d",&ps[i]);
}
for(i=0;i<bno;i++)
{
for(j=0;j<pno;j++)
{
if(ps[j]<=bs[i])
{
printf("The Process %d allocated to %d\n",j,bs[i]);
ps[j]=10000;
break;
}
}
}
for(j=0;j<pno;j++)
{
if(ps[j]!=10000)
{
printf("The Process %d is not allocated\n",j);
}
}
return 0;
}
