#include <stdio.h>
#include <stdlib.h>

//doubly linked list
//Node
struct Node
{
    int info;
    struct Node* right;
    struct Node*left;
};

typedef struct Node * nodeptr;


//return a dynamically allocated pointer-O(1)
nodeptr getnode()
{
    nodeptr p=(nodeptr) malloc (sizeof(struct Node));
    return p;
}

//free the pointer memory-O(1)
void freenode(nodeptr p)
{
    free(p);
}

//display-O(n)
void display(nodeptr p)
{
    printf("{ ");
    while(p)
    {
        printf("%d ",p->info);
        p=p->right;
    }
    printf("}\n");
}

//inserting at beginning of an empty or non empty list-O(1)
void insert_begin(nodeptr * list,int data)
{
    nodeptr p=getnode();
    p->info=data;
    p->left=0;
    p->right=0;
    if(*list==0)
    {
        *list=p;
        return;
    }

    p->right=*list;
    (*list)->left=p;
    *list=p;
}

//inserting at end of empty or non empty list-O(n)
void insert_end(nodeptr * list,int data)
{
     nodeptr p=getnode();
    p->info=data;
    p->left=0;
    p->right=0;
    if(*list==0)
    {
        *list=p;
        return;
    }

    nodeptr q=*list;
    while(q->right!=0)
        q=q->right;
    p->left=q;
    q->right=p;
}

//inserting at right-O(1) since pointer is provided
//not on empty list
void insert_right(nodeptr p,int data)
{
    nodeptr q=getnode();
    q->info=data;
    q->right=q->left=0;
    q->left=p;
    q->right=p->right;
    if(p->right)//not valid for last node
        p->right->left=q;
    p->right=q;

}

//inserting at left-O(1)..pointer is provided
//not for an empty list
void insert_left(nodeptr* list,int data)
{
    nodeptr p=*list;
    nodeptr q=getnode();
    q->info=data;
    q->left=q->right=0;

    q->right=p;
    q->left = p->left;
    if(p->left)//take care when inserting before first node
    p->left->right=q;
    p->left=q;
//if insertion before first node..then you have to change list head
    if(q->left==0)
        *list=q;
}

//deleting at beginning -O(1)
void delete_begin(nodeptr *list)
{
    //not valid for empty list
    if(*list==0)
    {
        printf("Void deletion\n");
        return;
    }
    nodeptr p=*list;
    *list=(*list)->right;
    if(*list)//in case only one node in list
    (*list)->left=0;
    freenode(p);
}

//deleting last node-O(n)
void delete_end(nodeptr * list)
{
    //not valid for empty list
    if(*list==0)
    {
        printf("Void deletion\n");
        return;
    }
    nodeptr p=*list;
    while(p->right!=0)
        p=p->right;
    if(p==*list)
    {
        *list=0;
    }
    else

    p->left->right=0;
    freenode(p);

}

//deleting a given node
void delete (nodeptr * p)
{
    nodeptr q=*p;
    nodeptr prev=q->left;
    nodeptr next=q->right;
    if(prev)
        prev->right=next;
    if(next)
        next->left=prev;
    if(q->left==0)
        *p=(*p)->right;
    freenode(q);
}

int main()
{
    return 0;
}
