#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,q,n,x,sum=0,max1,cnt=0;
    scanf("%d%d",&n,&x);
    max1=x;
    int a[n],b[n],c[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<1<<n;i++)
    {
        k = i;
        sum=0;
        int b[n];
            for(j=0;j<n;j++)
            {
                if(k&1)
                {
                    sum+=a[n-1-j];
                    b[n-1-j]=1;
                }
                else
                {
                   b[n-1-j]=0;
                }
                k=k/2;
            }
                if(x-sum<=max1&&x-sum>=0)
                {
                    for(j=0;j<n;j++)
                    {
                        c[j]=0;
                    }
                    for(j=0;j<n;j++)
                    {
                        if(b[j]==1)
                        {
                            c[j]=1;
                        }
                        else
                        {
                            c[j]=0;
                        }
                    }
                    max1=x-sum;
                }
    }
    for(i=0;i<n;i++)
    {
        if(c[n-1-i]==1)
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for(i=0;i<n;i++)
    {
        if(c[i]==1)
        {
            printf("%d ",i+1);
        }
    }
    return 0;
}
