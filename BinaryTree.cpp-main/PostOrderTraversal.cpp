//Postorder Traversal
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
void post(struct Node*root)
{
    if(root==NULL)
    {
        return;
    }
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}
int main()
{
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->left=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    post(root);
    return 0;
}
