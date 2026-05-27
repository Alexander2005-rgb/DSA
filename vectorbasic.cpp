#include <bits/stdc++.h>
using namespace std;
int main()
{
     // crreate vector
     vector<int> v;
     vector<int> v1(5); // all element are 0 of and sixe is 5
     vector<int> v2(5, 42);
     vector<int> v3 = {1, 2, 3, 4, 5};
     // access
     cout << v2[2] << " " << v3[3] << endl;
     cout << v2.at(2) << endl; // it gice the error out of range vector
     cout << v3.front() << endl;
     cout << v3.back() << endl;
     cout << v3.size() << endl;
     cout << v3.empty() << endl;
     // modifired  the element
     v3.push_back(6);
     // specific position
     v3.insert(v3.begin() + 2, 10);

     v3.pop_back();
}