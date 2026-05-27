// wapt to find the maximum consecutive 1's or zeros in a binary array using stl
#include <bits/stdc++.h>
using namespace std;

int main()
{
     // take the size of vector by user
     int n;
     cout << "enter the size of vector";
     cin >> n;
     vector<int> v;
     for (int i = 0; i < n; i++)
     {
          int x;
          cin >> x;
          v.push_back(x);
     }
     int c = 0;
     int output = 0;
     for (int i = 0; i < n; i++)
     {
          if (v[i] == 1)
          {
               c++;
          }
          else
          {
               output = max(output, c);
               c = 0;
          }
     }
     cout << output << endl;
     return 0;
}

// split array into three equal sum segments