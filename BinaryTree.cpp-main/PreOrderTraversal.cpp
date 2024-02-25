//Preorder Traversal 
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
void pre(struct Node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    pre(root->left);
    pre(root->right);
}
int main()
{
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->left=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    pre(root);
    return 0;
}
