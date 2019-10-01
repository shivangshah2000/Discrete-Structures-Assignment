#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,k,ref=0,sym=0,trans=0,n,m,flag=0;
    int arr[501][501];
    for(i=0;i<501;i++)
    {
        for(j=0;j<501;j++)
        {
            arr[i][j]=0;
        }
    }
    scanf("%d%d",&n,&m);
    int a[m],b[m];
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        arr[a[i]][b[i]]=1;
    }
    for(i=0;i<m;i++)
    {
        if(a[i]==b[i])
        {
            ref++;
        }
        if(arr[b[i]][a[i]]==1)
        {
            sym++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i+1][j+1]==1)
            {
                for(k=0;k<n;k++)
                {
                    if(arr[j+1][k+1]==1)
                    {
                        if(arr[i+1][k+1]!=1)
                        {
                            trans++;
                        }
                    }
                }
            }
        }
    }
    if(ref==n)
    {
        flag++;
        printf("reflexive\n");
    }
    if(sym==m)
    {
        flag++;
        printf("symmetric\n");
    }
    if(trans==0)
    {
        flag++;
        printf("transitive\n");
    }
    if(flag==3)
    {
        printf("equivalence");
    }
    if(flag==0)
    {
        printf("-1");
    }

    return 0;
}
