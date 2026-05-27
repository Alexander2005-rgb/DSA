// wap to remove duplicate element form the string using map
#include <bits/stdc++.h>
using namespace std;
void removeDuplicate(string s)
{
     map<char, int> mp;
     for (int i = 0; i < s.size(); i++)
     {
          mp[s[i]]++;
     }

     for (int i = 0; i < s.size(); i++)
     // give output everyone = evryon
     {
          if (mp[s[i]] == 1)
          {
               cout << s[i];
          }
     }
     cout << endl;
     return;
}
void removeDuplicate1(string s)
{
     map<char, int> mp;
     string result = "";
     for (char c : s)
     {
          if (mp[c] == 0)
          {
               result += c;
               mp[c] = 1;
          }
     }
     cout << result << endl;
     return;
}

int main()
{
     string s;
     cin >> s;
     removeDuplicate(s);
     return 0;
}