//To display transpose of matrix entered by user
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int ar[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
    int trnspose[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            trnspose[i][j]=ar[j][i];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<trnspose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


//Pascal's Tri
//int =4
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>pscltri(int n)
{
    vector<vector<int>>pscl(n);
    for(int i=0;i<n;i++)
    {
        pscl[i].resize(i+1);
        for(int j=0;j<i+1;j++)
        {
            if(j==0 or j==i)
            {
                pscl[i][j]=1;
            }
            else
            {
                pscl[i][j]=pscl[i-1][j]+pscl[i-1][j-1];
            }
        }
    }
    return pscl;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ans;
    ans=pscltri(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


//Given a boolean 2Darray where each row is sorted. Find row with maximum number of 1s
//hint is to find the first occurance of 1 in a column of any row tht row will have the max 1s
//eg  0 1 1 1
//    0 0 0 1
//    0 0 1 1
#include<iostream>
#include<vector>
using namespace std;
int mx1row(vector<vector<int>>&V)
{
    int mx1s=INT_MIN;
    int mx1rows=-1;
    int col=V[0].size();//v[0] is 0th row or the 0th vectore so v[0].size() will tell the no. of columns each row has as its a 2Dvector 
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V.size();j++)
        {
            if(V[i][j]==1)
            {
                int numof1=col-j;
                if(numof1>mx1s)
                {
                    mx1s=numof1;
                    mx1rows=i;
                }
            }
        }
    }
    return mx1rows;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    int res=mx1row(vec);
    cout<<res<<endl;
    return 0;
}
//OR By finding the leftmost 1 of any row (traversing from behind){alternated approach}


//Rotation operation Matrix
//Given a square matrix, turn it by 90 degrees in a clockwisw direction without using any extrz space
// 1 2 3      7 4 1
// 4 5 6  =>  8 5 2
// 7 8 9      9 6 3
//  i/p        o/p
//step1 is transpose step2 is reverse the rows ie r1-->r3
#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<vector<int>>&vec)
{//transpose
    int n=vec.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(vec[i][j],vec[j][i]);
        }
    }
    //reverse every row
    for(int i=0;i<n;i++)
    {
        reverse(vec[i].begin(),vec[i].end());
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    rotate(vec);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[i][j]<<" ";
        }
    }
}


//Given an nxm matrix 'a' , return all elements of the matrix in spiral order
// 1 2 3
// 4 5 6   -->  1 2 3 6 9 8 7 4 5
// 7 8 9
// left-->right    top-->bottom   right-->left    bottom-->top
//   top++            right--        bottom--        left++
#include<iostream>
#include<vector>
using namespace std;
void spiral(vector<vector<int>>&matrix)
{
    int left=0;
    int right=matrix[0].size()-1;
    int top=0;
    int bottom=matrix.size()-1;
    int direction=0;
    while(left<=right && top<=bottom)
    {
        //left->right
        if(direction==0)
        {
            for(int col=left;col<=right;col++)
            {
                cout<<matrix[top][col]<<" ";
            }
            top++;
        }
        //top->bottom
        else if(direction==1)
        {
            for(int row=top;row<=bottom;row++)
            {
                cout<<matrix[row][right]<<" ";
            }
            right--;
        }
        //right->left
        else if(direction==2)
        {
            for(int col=right;col>=left;col--)
            {
                cout<<matrix[bottom][col]<<" ";
            }
            bottom--;
        }
        //bottom->top
        else{
            for(int row=bottom;row>=top;row--)
            {
                cout<<matrix[row][left]<<" ";
            }
            left++;
        }
        direction=(direction+1)%4;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    spiral(matrix);
}


//Given a positive integers n, Generate an nxn matrix filled with elements from 1 to n in spiral order
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>createspirl(int n)
{
    vector<vector<int>>matrix(n,vector<int>n);
    int lft=0;
    int ryt=n-1;
    int tp=0;
    int btm=n-1;
    int direction=0;
    int value=1;
    while(lft<=ryt && tp<=btm)
    {
        if(direction==0)
        {
            for(int i=lft;i<=ryt;i++)
            {
                matrix[tp][i]=value++;
            }
            tp++;
        }
        else if(direction==1)
        {
            for(int j=tp;j<=btm;j++)
            {
                matrix[j][ryt]=value++;
            }
            ryt--;
        }
        else if(direction==2)
        {
            for(int i=ryt;i>=lft;i--)
            {
                matrix[btm][i]=value++;
            }
            btm--;
        }
        else{
            for(int j=btm;j>=tp;j++)
            {
                matrix[j][lft]=value++;            
            }
            btm--;
        }
        direction=(direction+1)%4;
    }
    return matrix;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    matrix=createspirl(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


//