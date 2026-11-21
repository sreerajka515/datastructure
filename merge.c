#include<stdio.h>
int main()
{
int a[15],b[10],c[10];
int n,m,i;
printf("enter the size first array: ");
scanf("%d",&n);
printf("enter element of first array:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
c[i]=a[i];
}
printf("enter the second array: ");
scanf("%d",&m);
printf("enter element of second array:\n");
for(i=0;i<m;i++)
{
scanf("%d",&b[i]);
c[n+i]=b[i];
}
printf("merged array:\n");
for(i=0;i<n+m;i++)
{
printf("%d ", c[i]);
print("\n");
}
return 0;
}



