#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,k,n,m,t;
    char str[100001];
    scanf("%s",str);
    t=strlen(str);
    scanf("%d",&m);
    char arr[26],ch,ky,ki;
    for(i=0;i<26;i++)
    {
        arr[i]='A';
    }
    for(i=0;i<m;i++){
        scanf(" %c %c",&ch,&ky);
        //scanf(" %c",&ki);
       // scanf(" %c",&ky);
        arr[ch-97]=ky;
    }
    for(i=0;i<t;i++)
    {
        if(arr[str[i]-97]=='A')
        {
            printf("%c",str[i]);
        }
        else
        {
            while(arr[str[i]-97]!='A')
            {
                str[i]=arr[str[i]-97];
            }
            printf("%c",str[i]);
        }
    }
    return 0;
}
