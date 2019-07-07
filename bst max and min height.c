//binary search tree max and min height
#include<stdio.h>
#include<stdlib.h>
static int count=0;
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
insertverification(root);
return root;
}
void insertverification(node root)
{
    node rc,lc;
    root->llink=lc;
    root->rlink=rc;
    if((root->info)>(rc->info)|(root->info)<(lc->info))
      {

        printf("tree not satisfied\n");
        exit(0);
      }
    else
        insertverification(lc);
        insertverification(rc);

}
 int height(node root)
 {
     node lnode,rnode;
     int lcount=0,rcount=0;
     while(root->rlink!=NULL&&root->llink!=NULL)
     lnode=root->llink;
     rnode=root->rlink;

     rcount++;
     rcount+=height(rnode);
     lcount++;
     lcount+=height(lnode);

     if(lcount>rcount)
        printf("max height is %d,min height is %d",lcount,rcount);
     else
        printf("max height is %d,min height is %d",rcount,lcount);
 }




void inorder(node root)
{
    if(root==NULL)return;
    inorder(root->llink);
    printf("%d",root->info);
    inorder(root->rlink);

}

void main()
{
    node root,temp;
    int choice,item;
    root=NULL;
    for(;;)
    {
        printf("1 insert 2 inorder 3 height 4 exit\n");
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
                       inorder(root);
                       printf("\n");
                   }
                   break;
            case 3:item=height(root);
                   break;
            default: exit(0);
        }
    }
}
