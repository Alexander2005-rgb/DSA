// reverse the digits of an integer
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int reverse(int x)
     {
          long long q = 0;

          while (x != 0)
          {
               int b = x % 10;
               q = q * 10 + b;
               x /= 10;

               if (q > INT_MAX || q < INT_MIN)
                    return 0;
          }

          return (int)q;
     }
};
int main()
{
     int x;
     cin >> x;
     Solution s;
     cout << s.reverse(x) << endl;
     return 0;
}