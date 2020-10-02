#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* nodeptr;

void display(nodeptr p)
{
    if(p->right==p)
    {
        printf("Empty list\n");
        return;
    }
    if(p->info==-1)
        printf("-");
    nodeptr q=p;
    p=p->right;
    while(p!=q)
    {
        int i=1;
        int a=10;
        int x=p->info;
        while(x/a)
        {
            i++;
            a*=10;
        }
        for(int k=0;k<5-i&&p!=q->right;k++)
            printf("0");
        printf("%d",p->info);
        p=p->right;
    }
    printf("\n");
}

void insert_end(nodeptr list,int data)
{
    nodeptr q=(nodeptr)malloc(sizeof(struct Node));
    q->info=data;
    nodeptr p=list->right;
    while(p->right!=list)
        p=p->right;
    q->left=p;
    p->right=q;
    q->right=list;
    list->left=q;

}
void insert_begin(nodeptr list,int data)
{
    nodeptr q=(nodeptr)malloc(sizeof(struct Node));
    q->info=data;
    nodeptr p=list->right;

    q->left=list;
   q->right=p;
   p->left=q;
   list->right=q;
   if(list->left==list)
    list->left=q;

}
int value(char * s,int i,int j)
{
    int val=0;
    while(i<=j)
    {
        val=val*10+s[i]-'0';
        i++;
    }
    return val;
}
void convert(char * s,nodeptr p)
{
    int stop;
    if(s[0]=='-')
        stop=1;
    else stop=0;
    int n=0,i=0,j,count=0;
    for(i=0;s[i]!='\0';i++)
        n++;
    i=n-1;
    j=i-4;
    while(j>=stop)
    {
        insert_end(p,value(s,j,i));
        count++;
        i=j-1;
        j=i-4;
    }
    if(i>=stop)
    {
        insert_end(p,value(s,stop,i));
        count++;
    }
    if(stop==0)
        p->info=count;
    else p->info=-count;

}

int compare(nodeptr p,nodeptr q)
{
    if(abs(p->info)>abs(q->info))
        return 1;
    if(abs(p->info)<abs(q->info))
        return -1;
    nodeptr pptr=p->left;
    nodeptr qptr=q->left;
    while(pptr!=p)
    {
        if(pptr->info>qptr->info)
            return 1;
        if(pptr->info<qptr->info)
            return -1;
        pptr=pptr->left;
        qptr=qptr->left;
    }
    return 0;
}
nodeptr add(nodeptr p,nodeptr q)
{
    nodeptr r=(nodeptr)malloc(sizeof(struct Node));
    r->right=r->left=r;
    nodeptr qptr=q->right;
    nodeptr pptr=p->right;
    int diff, borrow=0;
    while(qptr!=q)
    {
        diff=pptr->info-qptr->info-borrow;
        if(diff<0)
        {
            insert_begin(r,diff+100000);
            borrow=1;
        }
        else
        {
            insert_begin(r,diff);
            borrow=0;
        }
        qptr=qptr->right;
        pptr=pptr->right;
    }
    while(pptr!=p)
    {
        diff=pptr->info-borrow;
        if(diff<0)
        {
            insert_begin(r,diff+100000);
            borrow=1;
        }
        else
        {
            insert_begin(r,diff);
            borrow=0;
        }
        pptr=pptr->right;
    }
    if(p->info<0)
        r->info=-1;
    else r->info=1;
    return r;
}

int main()
{
    char a[100];
    char b[100];
    scanf("%s%s",&a,&b);
    nodeptr p=(nodeptr)malloc(sizeof(struct Node));
    p->right=p->left=p;
    nodeptr q=(nodeptr)malloc(sizeof(struct Node));
    q->right=q->left=q;
    nodeptr r=0;
    convert(a,p);
    convert(b,q);
    if(compare(p,q)==1)
        r=add(p,q);
    if(compare(p,q)==-1)
        r=add(q,p);
        display(r);

    return 0;
}
