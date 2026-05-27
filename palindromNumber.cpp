// check the palindrom number or not
#include <iostream>
using namespace std;
class Solution
{
public:
     bool isPalindrome(int x)
     {
          if (x < 0)
               return false;
          int reverse = 0, original = x;
          while (x > 0)
          {
               int lastDigit = x % 10;
               reverse = reverse * 10 + lastDigit;
               x /= 10;
          }
          if (reverse == original)
               return true;
          else
               return false;
     }
};
int main()
{
     int x;
     cin >> x;
     Solution s;
     cout << s.isPalindrome(x) << endl;
     return 0;
}