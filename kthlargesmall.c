#include<stdio.h>
int main()
{
    int r,c,k,i,e,j,nl=0,ct=0,f=0,kl,ks;
    printf("Enter no. of rows you want : ");
    scanf("%d",&r);
    printf("Enter no. of columns you want : ");
    scanf("%d",&c);
    int a[r][c],m[r*c],n[r*c];
    printf("Enter array : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&e);
            a[i][j]=e;
            m[ct]=e;
            ct+=1;
        }
    }
    ct=0;
    for(i=0;i<r*c;i++)
    {
        e=m[i];
        ct=0;
        for(j=i;j<r*c;j++)
        {
            if(c==m[j])
            ct+=1;
        }
        if(ct==1)
        {
            n[f]=c;
            f+=1;
            nl+=1;
        }
    }
    for(i=0;i<nl;i++)
    {
        for(j=0;j<nl-1-i;j++)
        {
            if(n[j]>n[j+1])
            {
                e=n[j];
                n[j]=n[j+1];
                n[j+1]=e;
            }
        }
    }
    printf("Enter the value of K : ");
    scanf("%d",&k);
    kl=m[nl-k];
    ks=n[k-1];
    printf("The Kth largest element = %d \n",kl);
    printf("The Kth smallest element = %d \n",ks);
    return 0;
}
