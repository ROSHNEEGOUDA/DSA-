//Ordered Set


//Insertion and Print

#include<iostream>
#include<set>
using namespace std;
set<int>s;
s.insert(1);
s.insert(2);
s.insert(2);
s.insert(3);
//printing elements in set
for(auto i:s)
cout<<i<<" ";
cout<<"\n";
//op- 1 2 3

for(auto i=s.begin();i!=s.end();i++)
cout<<*i<<" ";
cout<<endl;
//op- 1 2 3

//size of the set
cout<<s.size();
//op- 3

//print in reverse
for(auto i=s.rbegin();i!=s.rend();i++)
cout<<*i<<" ";
cout<<endl;


//Custom comparator

#include<iostream>
#include<set>
using namespace std;
set<int, greater <int>>s;
s.insert(1);
s.insert(2);
s.insert(2);
s.insert(3);
//printing elements in set
for(auto i:s)
cout<<i<<" ";
cout<<"\n";
//op- 3 2 1


//Lower/Upper_bound()

#include<iostream>
#include<set>
using namespace std;
set<int>s;
s.insert(1);
s.insert(3);
s.insert(5);
cout<<*s.lower_bound(2)<<endl;
cout<<*s.lower_bound(3)<<endl;
cout<<*s.lower_bound(3)<<endl;
cout<<(s.upper_bound(5)==s.end())<<endl;
//op- 3
//    3
//    5
//    1 (signifies true)

//Erase
#include<iostream>
#include<set>
using namespace std;
set<int>s;
s.insert(1);
s.insert(3);
s.insert(2);
s.insert(5);
s.erase(2);
s.erase(s.begin());
for(auto i:s)
cout<<i<<" ";
//op- 3 5

//There can be set of pair , set of vectors...

//MULTISET
