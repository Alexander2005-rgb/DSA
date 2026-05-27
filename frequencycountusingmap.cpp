// wap which will print the frequency of all the character in a given string
#include <bits/stdc++.h>
using namespace std;
int main()
{
     map<char, int> str;
     // insert
     string s;
     cin >> s;
     for (auto &x : s)
     {

          str[x]++;
     }
     for (auto &x : str)
     {
          cout << x.first << "-->" << x.second << endl;
     }
     // print character which is maximum in the srtring
     int max = 0;
     char ch;
     for (auto &x : str)
     {
          if (x.second > max)
          {
               max = x.second;
               ch = x.first;
          }
          }
     cout << ch << endl;
     cout << max << endl;

     return 0;
}