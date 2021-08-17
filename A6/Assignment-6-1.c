//Aditya Badayalya, 510819056, Assignment 6-1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f=1;

typedef struct binaryTree
{
  int data;
  struct binaryTree *R,*L;
}BT;

void appendComplete(BT **r,int k)
{
  if(*r==NULL)
  {
    *r= (BT*)malloc(sizeof(BT));
    (*r)->data=k;
    (*r)->R=(*r)->L=NULL;
  }
  else
  {
    if((*r)->L==NULL)
    appendComplete(&(*r)->L,k);
    else if((*r)->R==NULL)
    appendComplete(&(*r)->R,k);
    else if(((*r)->L->L!=NULL)&&((*r)->L->R==NULL))
    appendComplete(&(*r)->L->R,k);
    else if(((*r)->R->R==NULL)&&((*r)->L->R!=NULL))
    appendComplete(&(*r)->R,k);
    else appendComplete(&(*r)->L,k);
  }
}
void append(BT **r, int k)
{
  if(*r==NULL)
  {
    *r= (BT*)malloc(sizeof(BT));
    (*r)->data=k;
    (*r)->R=(*r)->L=NULL;
  }
  else if(*r!=NULL)
  {
    if((*r)->data<k)
    append(&((*r)->R),k);
    else if((*r)->data>k)
    append(&((*r)->L),k);
    else
    {
      printf("!!!ENTERED DATA ALREADY EXISTS!!!\n");
      f=0;
    }
  }
}

void inorder(BT *r)
{
    if(r->L!=NULL)
    inorder(r->L);
    printf("%d ",r->data);
    if(r->R!=NULL)
    inorder(r->R);
}

void preorder(BT *r)
{
    printf("%d ",r->data);
    if(r->L!=NULL)
    preorder(r->L);
    if(r->R!=NULL)
    preorder(r->R);
}

void postorder(BT *r)
{
    if(r->L!=NULL)
    postorder(r->L);
    if(r->R!=NULL)
    postorder(r->R);
    printf("%d ",r->data);
}

void search(BT *r,int k)
{
  if(r==NULL)
  {
    printf("!!!ERROR NO TREE FOUND!!!\n");
  }
  else
  {
    if(r->data==k)
    printf("Element Found!!!\n",r);
    else if(r->data<k&&r->R!=NULL)
    search(r->R,k);
    else if(r->data>k&&r->L!=NULL)
    search(r->L,k);
    else printf("!!!ELEMENT NOT FOUND IN THE TREE!!!\n");
  }
}

int main()
{
  BT *root=NULL;
  BT *rootTwo=NULL;
  int k,n=1;
  while(n!=0)
  {
    printf("Press 1 to enter a new value in the tree:\n");
    printf("Press 2 to traverse the tree in inorder fashion:\n");
    printf("Press 3 to traverse the tree in preorder fashion:\n");
    printf("Press 4 to traverse the tree in postorder fashion:\n");
    printf("Press 0 to exit:\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: printf("Enter the value to be added to the tree:\n");
              scanf("%d",&k);
              f=1;
              append(&root,k);
              if(f)
              appendComplete(&rootTwo,k);
              break;
      case 2: if(root==NULL)
              {
                printf("!!!ERROR NO TREE FOUND!!!\n");
                break;
              }
              printf("The inorder traversal of the complete binary tree is as follows:\n");
              inorder(rootTwo);
              printf("\n");
              printf("The inorder traversal of the binary search tree is as follows:\n");
              inorder(root);
              printf("\n");
              break;
      case 3: if(root==NULL)
              {
                printf("!!!ERROR NO TREE FOUND!!!\n");
                break;
              }
              printf("The preorder traversal of the complete binary tree is as follows:\n");
              preorder(rootTwo);
              printf("\n");
              printf("The preorder traversal of the binary tree is as follows:\n");
              preorder(root);
              printf("\n");
              break;
      case 4: if(root==NULL)
              {
                printf("!!!ERROR NO TREE FOUND!!!\n");
                break;
              }
              printf("The postorder traversal of the complete binary tree is as follows:\n");
              postorder(rootTwo);
              printf("\n");
              printf("The postorder traversal of the binary tree is as follows:\n");
              postorder(root);
              printf("\n");
              break;
    }
  }
  n=1;
  while(n!=0)
  {
    printf("Press 1 to check if an element is present in the tree:\n");
    printf("Press 0 to exit:\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: printf("Enter the value of element to be searched:\n");
              scanf("%d",&k);
              search(root,k);
              break;
    }
  }
  return 0;
}
