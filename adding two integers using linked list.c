#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node* nodeptr;

void display(nodeptr p)
{
    nodeptr q=p;
    if(p==0)
        printf("Empty string\n");
    else
    {
        while(p)
        {
            int x=p->data;
            int i=1;
            int a=10;
            //calculating number of digits
            //if digit is 555..then 00555 has to be displayed
            while(x/a)
            {
                x;
                i++;
                a*=10;
            }
            int k=5-i;
            //for fisrst difit we need not display extra zeroes
            for(i=0;i<k&&p!=q;i++)
                printf("0");
            printf("%d",p->data);
            p=p->next;
        }
        printf("\n");
    }
}
//insert node at the end..if list is empty or non empty
void insert_end(nodeptr* list,int data)
{
    nodeptr p=(nodeptr)malloc(sizeof(struct Node));
    p->data=data;
    p->next=0;
    if(*list==0)
    {
        *list=p;
        return;
    }

    nodeptr q=*list;
    while(q->next !=0)
        q=q->next;
    q->next=p;

}

//reverses the list
void reverse(nodeptr * list)
{
    nodeptr p=*list,q=0,r=0;
    while(p)
    {
        q=p->next;
        p->next=r;
        r=p;
        p=q;
    }
    *list=r;
}

//converts a string literal into its numeric value
int value(char *s ,int i,int j)
{
    int val=0;
    while(i<=j)
    {
        val=val*10+(s[i]-'0');
        i++;
    }
    return val;
}

//returns size of string literal
int size(char *s)
{
    int n=0,i=0;
    while(s[i]!=0)
        {n++;
        i++;}
    return n;
}

//stores string in a linked list
//chunks of 5 digits are stored
void convert(nodeptr* list,char * s,int n)
{
    int i=n-1;
    int j=i-4;
    while(j>=0)
    {
        insert_end(list ,value(s,j,i));
        i=j-1;
        j=i-4;
    }
    if(i>=0)
        insert_end(list,value(s,0,i));
}

void add(nodeptr list1,nodeptr list2,nodeptr*list3)
{
    int carry=0;
    while(list1&&list2)
    {
        int x=list1->data+list2->data+carry;
        carry=x/100000;
        insert_end(list3,x%100000);
        list1=list1->next;
        list2=list2->next;
    }
    while(list1)
    {
        int x=list1->data+carry;
        carry=x/100000;
        insert_end(list3,x%100000);
        list1=list1->next;

    }

    while(list2)
    {
        int x=list2->data+carry;
        carry=x/100000;
        insert_end(list3,x%100000);
        list2=list2->next;

    }

    if(carry!=0)
        insert_end(&list3,carry);
}
int main()
{

    nodeptr list1=0;
    nodeptr list2=0;
    nodeptr list3=0;

    char a[100];
    char b[100];
    scanf("%s%s",&a,&b);
    int n1=size(a);
    int n2=size(b);

    convert(&list1,a,n1);
    convert(&list2,b,n2);

    add(list1,list2,&list3);

    reverse(&list3);

    display(list3);

}
