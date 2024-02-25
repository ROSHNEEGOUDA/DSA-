//Given 2 strings return true if its an anagram of it else false
//anagram means rearranging letters of a word to get another word
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>                                                                                                                                                                                                                                                                                                
using namespace std;
bool isana(string s1, string s2)
{
    //create freq array
    vector<int>freq(26,0);
    if(s1.length()!=s2.length())
    {
        return false;
    }
    for(int i=0;i<s1.length();i++)
    {
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(isana(s1,s2))
    {
        cout<<"strings r anagrams"<<endl;
    }
    else{
        cout<<"strings r nt anagrams"<<endl;
    }
}


//Given 2 strings s and t determine if they are isomorphic
//isomorphic means one to one mapping
// eg egg -> add  are isomorphic 
//eg egg ->ada  not isomorphic as g is mapping with a and d its many one mapping not one one
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>                                                                                                                                                                                                                                                                                                
using namespace std;
bool isisomorphic(string s1, string s2)
{
    vector<int> v1(128,-1);
    vector<int> v2(128,-1);
    if(s1.size()!=s2.size())
    {
        return false;
    }
    for(int i=0;i<s1.size();i++)
    {
        if(v1[s1[i]]!=v2[s2[i]])
        {
            return false;
        }
        v1[s1[i]]=v2[s2[i]]=i;
    }
    return true;
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(isisomorphic(s1,s2))
    {
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}


//Given an array of strings Write a program to find the longest common prefix string amongst an array of strings
//for eg  arr=[ "flower", "flight", "flask"]
// ans is "fl"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>                                                                                                                                                                                                                                                                                                
using namespace std;
string longstprfx(vector<string> &str)
{
    string s1=str[0];
    int anslen=s1.size();
    for(int i=1;i<str.size();i++)
    {
        int j=0;
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j])
        {
            j++;
            anslen=min(anslen,j);

        }
        string ans=s1.substr(0,anslen);
        return ans;
    }
}
 int main()
 {
    int n;
    cin>>n;
    vector<string> str(n);
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    cout<<longstprfx(vector<string> &str)
    {
        sort(str.begin(),str.end());
        string s1=str[0];
        int i=0;
        string s2=str[str.size()-1];
        int j=0;
        string ans=" ";
        while(i<s1.size() && j<s2.size())
        {
            if(s1[i]==s2[j])
            {
                ans+=s1[i];
                i++;
                j++;
            }
            else{
                break;
            }
        }
        return ans;
    }
 }


 
 //An encoded string(s) is given and task is to decode it. Encoding pattern is that occurance of string is given at starting of sting and each string is enclosed by square brackets
 // eg ip s=3[b2[ca]]
 //op is bcacabcacabcaca
 //ie (bcaca)(bcaca)(bcaca)
 #include<iostream>
#include<string>
#include<vector>
#include<algorithm>                                                                                                                                                                                                                                                                                                
using namespace std;
string decodestr(string s)
{
    string result="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=']')
        {
            result.push_back(s[i]);
        }
        else{
            string str="";
            while(!result.empty() && result.back()!='[')
            {
                str.push_back(result.back());
                result.pop_back();
            }
            reverse(str.begin(),str.end());
            result.pop_back();
            string num="";
            while(!result.empty() && (result.back()>='0' && result.back()<='9'))
            {
                num.push_back(result.back());
                result.pop_back();

            }
            reverse(num.begin(),num.end());
            int  intnum=stoi(num);
            //insert str in result intnum times
            while(intnum)
            {
                result+=str;
                intnum--;
            }

        }
    }
    return result;
}
int main()
{
    string str;
    cin>>str;
    cout<<decodestr(str)<<endl;
    return 0;
} 


//Given a binary string and an integer k return maximum number of consecutive 1s in the string if you can flip at most k 0s
//eg  "0001101011"  k=2
// op -> 7