//Build Tree from Preorder and Inorder traversal
//Preorder 1,2,4,3,5  &  Inorder 4,2,1,5,3
//output  4 2 1 5 3 
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;

    Node (int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int search(int inorder[],int start,int end,int cur_pos)
{
    for (int i=start;i<=end;i++)
    {
        if(inorder[i]==cur_pos)
        {
            return i;
        }
    }return -1;
}
Node * buildtree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int cur_pos=preorder[idx];
    idx++;
    Node*node=new Node(cur_pos);
    if(start==end)
    {
        return node;
    }
    int pos=search(inorder,start,end,cur_pos);
    node->left=buildtree(preorder,inorder,start,pos-1);
    node->right=buildtree(preorder,inorder,pos+1,end);
    return node;
}
void inop(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    inop(root->left);
    cout<<root->data<<" ";
    inop(root->right);
}
int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node*root=buildtree(preorder,inorder,0,4);
    inop(root);
    return 0;
}
