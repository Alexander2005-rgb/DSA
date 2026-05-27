// check anagram
#include <bits/stdc++.h>
using namespace std;
// int anagram(string s1, string s2)
// {
//      int n1 = s1.length();
//      int n2 = s2.length();
//      if (n1 != n2)
//      {
//           return false;
//      }
//      sort(s1.begin(), s1.end());
//      sort(s2.begin(), s2.end());
//      for (int i = 0; i < n1; i++)

int anagram1(string s1, string s2)
{
     int arr[26] = {0};
     for (int i = 0; i < s1.size(); i++)
     {
          arr[s1[i] - 'a']++;
          arr[s2[i] - 'a']--;
     }
     for (int i = 0; i < 26; i++)
     {
          if (arr[i] != 0)
          {
               cout << "not a anagram ";
               return 0;
          }
     }
     cout << "anagram";
     return 0;
}
bool isAnagram(string s, string t)
{
     int arr[26] = {0};
     for (int i = 0; i < s.size(); i++)
     {
          arr[s[i] - 'a']++;
          arr[t[i] - 'a']--;
     }
     for (int i = 0; i < 26; i++)
     {
          if (arr[i] != 0)
          {
               return false;
          }
     }
     return true;
}

int main()
{
     string s1, s2;
     cin >> s1 >> s2;
     // anagram1(s1, s2);
     isAnagram(s1, s2);

     return 0;
}