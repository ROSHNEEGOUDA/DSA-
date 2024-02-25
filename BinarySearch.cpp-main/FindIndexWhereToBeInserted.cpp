#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int searchInsert(vector<int>& arr, int m)
{
	int n=arr.size();
	int lo=0,hi=n-1;
	int ans=n;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		if(arr[mid]>=m)
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}return ans;
	
}
int main()
{
    int t,m;
    cin>>t>>m;
    vector<int> arr(t);
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    int x = searchInsert(arr , m);
    cout<<x<<endl;
    return 0;
    
}