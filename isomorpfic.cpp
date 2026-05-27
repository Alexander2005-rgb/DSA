// wap to chech two stirng isomorphic or not
#include <bits/stdc++.h>
using namespace std;
bool isomorphic(string s1, string s2)
{
     map<char, char> m1, m2;
     for (int i = 0; i < s1.size(); i++)
     {
          if (m1.find(s1[i]) == m1.end() && m2.find(s2[i]) == m2.end())
          {
               m1[s1[i]] = s2[i];
               m2[s2[i]] = s1[i];
          }
          else
          {
               if (m1[s1[i]] != s2[i] || m2[s2[i]] != s1[i])
               {
                    cout << "Not Isomorphic" << endl;
                    return false;
               }
          }
     }
     cout << "Isomorphic" << endl;
     return true;
}
bool isomorphic1(string s1, string s2)
{
     int arr[256] = {0};
     int arr1[256] = {0};
     for (int i = 0; i < s1.size(); i++)
     {
          if (arr[s1[i]] != arr1[s2[i]])
          {
               cout << "Not Isomorphic" << endl;
               return false;
          }
          arr[s1[i]] = i + 1;
          arr1[s2[i]] = i + 1;
     }
     cout << "Isomorphic" << endl;
     return true;
}
int main()
{
     string s1, s2;
     cin >> s1 >> s2;
     isomorphic(s1, s2);
     return 0;
}