//binary search tree inoreder traversal using stack
#include<stdio.h>
#include<stdlib.h>

#define stacksize 25
int top,s[25];
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *node;

node getnode()
{
    node x;
    x=(node)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("out of memory\n");
        exit(0);
    }
    return x;
}
node insert (int item,node root)
{
    node temp,cur,prev;
    temp=getnode();
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;

    if(root==NULL)
        return temp;
    prev=NULL;
    cur=root;

    while(cur!=NULL)
    {
        prev=cur;
        if(item>=cur->info)
            cur=cur->rlink;
        else
            cur=cur->llink;
    }
    if(item>prev->info)
            prev->rlink=temp;
        else
            prev->llink=temp;
//insertverification(root);
return root;
}
//void insertverification(node root)
//{
    //node rc,lc;
    //root->llink=lc;
   // root->rlink=rc;
    //if((root->info)>(rc->info)|(root->info)<(lc->info))
      //{

        //printf("tree not satisfied\n");
        //exit(0);
     // }
   // else
     //   insertverification(lc);
       // insertverification(rc);

//}

void inorder(node root,int top)
{
    node prev,cur;
    prev=NULL;
    cur=root;
    while(cur!=NULL)
    {
        push(cur->info,s);
        cur=cur->llink;

    }
    if(cur==NULL&&top!=-1)
    {
        pop(s);
        cur=cur->rlink;
        inorder( root, top);
    }
    if(cur==NULL&&top==-1)
    {
        printf("\ndone");
    }
}
void push(int item,int s[])
{
    if(top==stacksize-1)
    {
        printf("stack overflow");
        return;
    }
    top=top+1;
    s[top]=item;
}
void pop(int s[])
{
    int deleteditem;
    if(top==-1)
        return 0;
    deleteditem=s[top--];
    printf("%d",deleteditem);

}


void main()
{
    node root,temp;
    int choice,item;
    root=NULL;
    for(;;)
    {
        printf("1 insert 2 inorder 3 exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the item to be inserted\n");
                    scanf("%d",&item);
                    root=insert(item,root);
                    break;
            case 2:if(root==NULL)
                    printf("tree is empty");
                   else
                   {
                       printf("the given tree in inorder form is\n");
                       inorder(root,top);
                       printf("\n");
                   }
                   break;

            default: exit(0);
        }
    }
}
