// reverse string like ex = how are you give output you are how
#include <bits/stdc++.h>
using namespace std;
int reverseString(string s, int n)
{
     for (int i = n; i >= 0; i--)
     {
          cout << s[i];
     }
     return 0;
}


int main()
{
     string s;
     cin >> s;
     int n = s.length();
     reverseString(s, n);
}