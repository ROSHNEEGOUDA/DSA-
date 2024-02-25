#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->left=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    return 0;
}

--------------------------------------------------------

//PREORDER
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void pre(struct Node*root)
{
    if(root!=NULL)
    {
        cout<<(root->data)<<" ";
        pre(root->left);
        pre(root->right);
    }
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

---------------------------------------------

//INORDER
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void in(struct Node*root)
{
    if(root!=NULL)
    {
        in(root->left);
        cout<<(root->data)<<" ";
        in(root->right);
    }
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

------------------------------------------------

//POSTORDER
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void post(struct Node*root)
{
    if(root!=NULL)
    {
        post(root->left);
        cout<<(root->data)<<" ";
        post(root->right);
    }
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

----------------------------------------------------

//BUILD TREE FROM PREORDER AND INORDER
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
int search(int in[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
Node *buildtree(int pre[],int ino[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int curr=pre[idx];
    idx++;
    Node *node=new Node(curr);
    if(start==end)
    {
        return node;
    }
    int pos=search(ino,start,end,curr);
    node->left=buildtree(pre,ino,start,pos-1);
    node->right=buildtree(pre,ino,pos+1,end);
    return node;
}
void inoprint(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    inoprint(root->left);
    cout<<(root->data)<<" ";
    inoprint(root->right);
}
int main()
{
    int pre[]={1,2,4,3,5};
    int ino[]={4,2,1,5,3};
    Node*root=buildtree(pre,ino,0,4);
    inoprint(root);
    return 0;
}

------------------------------------------------------------

//BUILD TREE FROM POSTORDER AND INORDER
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
int search(int in[],int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==val)
        {
            return i;
        }
    }
    return -1;
}
Node *buildtree(int post[],int ino[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int val=post[idx];
    idx--;
    Node *node=new Node(val);
    if(start==end)
    {
        return curr;
    }
    int pos=search(ino,start,end,val);
    curr->right=buildtree(post,ino,pos+1,end);
    curr->left=buildtree(post,ino,start,pos-1);
    return curr;
}
void inoprint(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    inoprint(root->left);
    cout<<(root->data)<<" ";
    inoprint(root->right);
}
int main()
{
    int post[]={4,2,1,5,3};
    int ino[]={4,2,1,5,3}
    Node*root=buildtree(post,ino,0,4);
    inoprint(root);
    return 0;
}

--------------------------------------------------------------