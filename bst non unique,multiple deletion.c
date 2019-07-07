//binary search tree NON UNIQUE deletion of all keys
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
    if((root->info)!<(rc->info)|(root->info)!>(lc->info))
      {

        printf("tree not satisfied\n");
        exit(0);
      }
    else
        insertverification(lc);
        insertverification(rc);

}
node delet(int key,node root)
{   for(int i=0;i<=count;i++)
  {

    node cur,parent,suc,q;
    if(root==NULL)
    {
        printf("tree is empty\n");
        return root;
    }
    parent=NULL;
    cur=root;

    while(cur!=NULL)
    {
        if(key!=cur->info)
        parent=cur;
        cur=(key>cur->info)?cur->rlink:cur->llink;

    }

    if(cur->llink==NULL)
        suc=cur->rlink;
    else if(cur->rlink==NULL)
        suc=cur->llink;
    else
     {
        suc=cur->rlink;
        while(suc->llink!=NULL)
            suc=suc->llink;
        suc->llink=cur->llink;
        suc->rlink=cur->rlink;
    }
if(parent==NULL)
    return suc;
if(cur==parent->rlink)
    parent->rlink=suc;
else
    parent->llink=suc;
free(cur);

return root;
}
}

void search(int key,node root)
{
    node cur,next;
    cur=root;
    next=cur->rlink;
    if(cur->info==key)
        {count++;
        search(key,next);}
    else
        search(key,next);

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
        printf("1 insert 2 inorder 3 delete 4 exit\n");
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
            case 3:printf("enter the the item to be deleted\n");
                   scanf("%d",&item);
                   root=delet(item,root);
                   break;
            default: exit(0);
        }
    }
}
