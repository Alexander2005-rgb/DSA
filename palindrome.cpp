#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string s)
{
     int left = 0;
     int right = s.length() - 1;

     while (left < right)
     {
          if (s[left] != s[right])
          {
               return false;
          }
          left++;
          right--;
     }
     return true;
}

int main()
{
     string s;
     cin >> s;
     cout << (isPalindrome(s) ? "true" : "false") << endl;
     return 0;
}