#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int info;
    struct Node *link;
} Node;
void Display();
void Ins(int,int);
void Del(int);
Node *start;
int main()
{
    start=NULL;
    int ch1,ch2,e,pos;
    while(1)
    {
        printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\nChoice : ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
            printf("Enter Value to be inserted : ");
            scanf("%d",&e);
            printf("\nEnter 1 to insert at the beginning\nEnter 2 to insert at the back\nEnter 3 to insert at a position\nChoice : ");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1:
                Ins(1,e);
                break;
                case 2:
                Ins(-1,e);
                break;
                case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                Ins(pos,e);
                break;
            }
            break;
            case 2:
            printf("\nEnter 1 to delete at the beginning\nEnter 2 to delete at the back\nEnter 3 to delete at a position\nChoice : ");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1:
                Del(1);
                break;
                case 2:
                Del(-1);
                break;
                case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                Del(pos);
                break;
            }
            break;

            case 3:
            Display();
            break;
            case 4:
            exit(0);
            break;

            default:
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}
void Ins(int pos,int val)
{
    int c=1;
    Node *tmp,*q,*p;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->info=val;
    tmp->link=NULL;
    if(start==NULL)
    start=tmp;
    else
    {
        q=start;
        if(pos==1)
        {
            tmp->link=start;
            start=tmp;
        }
        else if(pos==-1)
        {
            while(q->link!=NULL)
            q=q->link;
            q->link=tmp;
        }
        else
        {
            while(q->link!=NULL)
            {
                if(c==pos-1)
                break;
                c+=1;
                q=q->link;
            }
            p=q;
            q=q->link;
            p->link=tmp;
            tmp->link=q;
        }
    }
}
void Del(int pos)
{
    int c=1;
    Node *q,*tmp;
    q=start;
    if(q==NULL)
    printf("IT'S ALREADY EMPTY\n");
    else if(pos==1)
    {
        q=q->link;
        free(start);
        start=q;
    }
    else if(pos==-1)
    {
        while(q->link!=NULL)
        {
            tmp=q;
            q=q->link;
        }
        tmp->link=NULL;
        free(q);
    }
    else
    {
        while(q->link!=NULL)
        {
            if(c==pos-1)
            break;
            c+=1;
            q=q->link;
        }
        tmp=q;
        q=q->link;
        tmp->link=q->link;
        free(q);
    }
}
void Display()
{
    Node *q;
    q=start;
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->link;
    }
    printf("\n\n");
}
