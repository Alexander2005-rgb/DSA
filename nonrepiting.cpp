// wap which will print the non repeting character of the string
#include <bits/stdc++.H>
using namespace std;
int nonRepiting(string s)
{
     int n = s.length();
     int arr[26] = {0};
     for (int i = 0; i < n; i++)
     {
          arr[s[i] - 'a']++;
     }
     for (int i = 0; i < n; i++)
     {
          if (arr[s[i] - 'a'] == 1)
          {
               cout << s[i];
               return 0;
          }
     }
}
void repeting(string s)
{
     map<char, int> mp;
     for (int i = 0; i < s.length(); i++)
     {
          mp[s[i]]++;
     }
     for (auto &x : mp)
     {
          if (x.second == 1)
          {
               cout << x.first;
               return;
          }
     }
}

int main()
{
     string s;
     cin >> s;
     // nonRepiting(s);
     // return 0;
     repeting(s);
     return 0;
}