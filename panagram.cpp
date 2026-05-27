// wap to check in given string is panagram or not

#include <bits/stdc++.h>
using namespace std;
int panagramString(string s, int n)
{
     int arr[26] = {0};
     for (int i = 0; i < n; i++)
     {
          arr[s[i] - 'a']++;
     }
     for (int i = 0; i < 26; i++)
     {
          if (arr[i] != 0)
          {
               cout << "String is panagram";
               return 0;
          }
          else
          {
               cout << "String is not panagram;";
               return 0;
          }
     }
}

int main()
{
     string s;
     getline(cin, s);
     // cin >> s;
     int n = s.length();
     panagramString(s, n);
     return 0;
}