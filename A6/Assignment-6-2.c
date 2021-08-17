//Aditya Badayalya, 510819056, Assignment 6-2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//structure to store data and its respective occurence frequency and other information
typedef struct record
{
  char data;
  int frequency;
  int compressedBitsRequired;
  int originalSize;
  int compressedSize;
  int huffmanCode;
  struct record *next;
}record;

//tree node
typedef struct huffmanTreeNode
{
  char data;
  int frequency;
  struct huffmanTreeNode *leftChild,*rightChild;
} HTN;

//tree skeleton consisting of its size and nodes
typedef struct huffmanTree
{
  int size,capacity;
  HTN **arrayOfNodes;
} HT;

//function to create a new node for huffman tree with given character and its respective frequency
HTN *new(char data,int frequency)
{
  HTN *temp=(HTN*)malloc(sizeof(HTN));
  temp->leftChild=temp->rightChild=NULL;
  temp->data=data;
  temp->frequency=frequency;
  return temp;
}

//function to create a new tree skeleton / minheap (collection of nodes of a tree) of required capacity
HT *create(int capacity)
{
  HT *tmp=(HT*)malloc(sizeof(HT));
  tmp->size=0;
  tmp->capacity=capacity;
  tmp->arrayOfNodes=(HTN**)malloc(capacity*sizeof(HTN*));
  return tmp;
}

//function to interchange position of two given nodes of the tree
void swapNode(HTN **a,HTN **b)
{
  HTN*k=*a;
  *a=*b;
  *b=k;
}

//function to make the minimum heap binary tree
void makeTree(HT *tree,int id)
{
  //the array contains the collection of the nodes of the tree
  //the tree made is in the sorted order of the frequencies therefore these values are used for comaparison
  int smallest =id;
  int left=2*id+1;//left child of node at index id
  int right = 2*id+2;//right child of node at index id
  if((left < tree->size)&&(tree->arrayOfNodes[left]->frequency < tree->arrayOfNodes[smallest]->frequency))
  smallest=left;
  if((right < tree->size)&&(tree->arrayOfNodes[right]->frequency < tree->arrayOfNodes[smallest]->frequency))
  smallest=right;//incase the node does not exist smallest is equal to id automatically => refer to the build tree function as the values allotted are NULL or garbage values which are much larger in comparison to the frequency
  if(smallest!=id)
  {
    //if the element at initially given id is not the smallest then it is swapped with the smallest element and recursion is called to do the process again witht the nex smallest index
    swapNode(&tree->arrayOfNodes[smallest],&tree->arrayOfNodes[id]);
    makeTree(tree,smallest);
  }
}

//function to check if there is only one node left in the tree
int isSizeOne(HT* node)
{
  return (node->size==1);
}

//function to obtain minimum i.e bottomost value from the minimum heap binary tree as the tree is being made in the sorted order with largest at top
HTN* extractMinimumValue(HT *node)
{
  HTN* temp=node->arrayOfNodes[0];//minimum value is extracted
  node->arrayOfNodes[0]=node->arrayOfNodes[node->size-1];//largest value is assigned at the zeroth index and then size is reduced by one
  node->size--;
  makeTree(node,0);//the tree is remade properly again according to the sorted order
  return temp;
}

//function to add a new node in the tree
void insertNewNodeInTree(HT*tree,HTN*node)
{
  tree->size++;
  int i=tree->size-1;
  while(i&&(node->frequency < tree->arrayOfNodes[(i-1)/2]->frequency))
  {
    //comapring with root of index i ie (i-1)/2
    //since children of a node at index i are obtained at the indicex 2*i+1 and 2*i+2
    //loop to determine the position in the tree which would be taken up by the new node as per the value of the frequency
    tree->arrayOfNodes[i]=tree->arrayOfNodes[(i-1)/2];
    i=(i-1)/2;//taking a different node now
  }
  tree->arrayOfNodes[i]=node;//position allotted by process of elimination i.e removing all other not possible places
}

//function to build the min heap binary tree
void buildTree(HT *tree)
{
  int n=tree->size-1;
  for(int i=(n-1)/2;i>=0;i--)
  makeTree(tree,i);//ultimately n data objects are added to the trr
}

//function to check if the node is a tail node i.e a leaf
int isLeaf(HTN* node)
{
  return !(node->leftChild)&&!(node->rightChild);//if both are NULL then it is a leaf therefore !NULL is returned which means true is returned
}

//function to create a minimum heap binary tree of required size and data is also added accordingly in the tree
HT *createAndBuildTree(record *node, int size)
{
  HT *tree=create(size);//tree of given size is created. size here means number of different character(data)
  int i=0;
  while(node!=NULL)
  {
    tree->arrayOfNodes[i]=new(node->data,node->frequency);//data(character) and respective frequencies are provided to the function to create a new node which is then stored in the array of nodes
    i++;
    node=node->next;
  }
  tree->size=size;
  buildTree(tree);//tree is now built with all the proper  ad also sorted automatically => refer to the build tree function
  return tree;
}

//function to build the huffman tree of required size and also giving reuired data
HTN* buildHuffmanTree(record *node,int size)
{
  HTN *left,*right,*top;
  HT *tree=createAndBuildTree(node,size);
  while(!isSizeOne(tree))
  {
    left=extractMinimumValue(tree);//left child
    right=extractMinimumValue(tree);//right child
    top=new('#',left->frequency+right->frequency);//new node is made for tree here
    //'#' is allotted to the nodes where we do not require characters
    top->leftChild=left;
    top->rightChild=right;
    insertNewNodeInTree(tree,top);//the new node made is added to the final i.e huffman tree which is required
  }
  return extractMinimumValue(tree);//used later for the huffman codes
}

//function to printf the huffman codes of the elements in the huffman tree
void printHuffmanCodes(HTN*root,int arr[],int top,record* dope)
{
  if(root->leftChild)
  {
    arr[top]=0;//left side branch is given the value zero as per the convention
    printHuffmanCodes(root->leftChild,arr,top+1,dope);
  }
  if(root->rightChild)
  {
    arr[top]=1;//right side branch is given the value 1 as per the convention
    printHuffmanCodes(root->rightChild,arr,top+1,dope);
  }
  if(isLeaf(root))
  {
    record *temp=dope;
    while(temp!=NULL)
    {
      if(temp->data==root->data)
      {
        temp->compressedBitsRequired = top;
        temp->huffmanCode=0;
        int x=1;
        for(int i=top-1;i>=0;i--)
        {
          temp->huffmanCode+=(x*arr[i]);
          x*=10;
        }
        break;
      }
      temp=temp->next;
    }
  }
}

//fucntion to assign huffman codes to a particular element of the tree
void huffmanCodes(record* node,int size)
{
  HTN *root=buildHuffmanTree(node,size);//root of the huffman tree is extracted and thus is then used for printing the codes
  int arr[size+100],top=0;
  printHuffmanCodes(root,arr,top,node);
}

//function to sort the data according to the occurence frequency
void sortit(record *node)
{
  if(node->frequency > node->next->frequency)
  {
    char k=node->data;
    int f=node->frequency;
    node->data=node->next->data;
    node->frequency=node->next->frequency;
    node=node->next;
    node->data=k;
    node->frequency=f;
  }
}

//function to take the occuring data and modyify its frequency accordingly
void append(record **tr,char c)
{
  if(*tr==NULL)
  {
    record *node=(record*)malloc(sizeof(record));
    node->data=c;
    node->frequency=1;
    node->next=NULL;
    *tr=node;
  }
  else
  {
    record *node = *tr;
    while(node->next!=NULL)
    {
      if(node->data==c)
      {
        node->frequency++;
        if(node->next!=NULL)
        {
          sortit(node);
        }
        return;
      }
      node=node->next;
    }
    if(node->data==c)
    {
      node->frequency++;
      if(node->next!=NULL)
      {
        sortit(node);
      }
      return;
    }
    if(node->next==NULL)
    {
        node->next=(record*)malloc(sizeof(record));
        node->next->data=c;
        node->next->frequency=1;
        sortit(node);
        node=node->next;
        node->next=NULL;
    }
  }
}

//function to display complete data analysis
void display(record *n,int x)
{
  FILE *fp=fopen("output-2.txt","w");
  record*k=n;
  int y=0;
  if(n==NULL)
  fprintf(fp,"!!!Error no data found!!!\n");
  else
  {
    while(n!=NULL)
    {
      fprintf(fp,"|Character: %c|-->|Frequency: %d|-->|Originally Size required: %d|-->|Huffman Code: %d|-->|Compressed Size: %d|\n\n",n->data,n->frequency,n->originalSize,n->huffmanCode,n->compressedSize);
      n=n->next;
    }
    n=k;
    while(n!=NULL)
    {
      y+=n->compressedSize;
      n=n->next;
    }
    fprintf(fp,"\nAs all elements are stored in their binary form in the memory, the characters are originally ");
    fprintf(fp,"stored in the form of their\n\nASCII values which in turn are stored in binary format taking ");
    fprintf(fp,"up 8 bits in the memory for each character.\n");
    fprintf(fp,"\nTherefore the total original length(number of bits) of all %d characters(total frequency) ");
    fprintf(fp,"is equal to || %d ||\n",8*x);
    fprintf(fp,"\nThe required length(size) is compressed by using Huffman Codes which are unique and take up less space.\n");
    fprintf(fp,"\nThe total modified length(number of bits) after using Huffman Codes is equal to || %d ||\n",y);
    float change=(float)(8*x)-(float)y;
    change/=(float)(8*x);
    change*=100;
    char tt='%';
    fprintf(fp,"\nThe percentage reduction in the length is || %0.2f%c ||\n",change,tt);
    fclose(fp);
  }
}

//main
int main()
{
  record *dat=NULL;
  FILE * fp;//taking data input from the file
  fp=fopen("input.txt","r");
  if(fp==NULL)
  {
    printf("!!!Error file not found!!!\n");
    return 0;
  }
  char c;
  while(c!=EOF)
  {
    c=getc(fp);
    if(isalpha(c))
    append(&dat,c);//appending data in the linked list structure
  }
  fclose(fp);
  int size=0,totalFrequency=0;
  record *xyz=dat;
  while(xyz!=NULL)//determining the total number of different characters provided by the user
  {
    totalFrequency+=xyz->frequency;
    size++;
    xyz=xyz->next;
  }
  huffmanCodes(dat,size);
  xyz=dat;
  int totalBefore=0,totalAfter=0;
  while(xyz!=NULL)
  {
    xyz->originalSize=xyz->frequency*8;
    xyz->compressedSize=xyz->frequency*xyz->compressedBitsRequired;
    totalBefore+=xyz->originalSize;
    totalAfter+=xyz->compressedSize;
    xyz=xyz->next;
  }
  display(dat,totalFrequency);
  return 0;
}
