#include <iostream>
#include <string>
using namespace std;

int main()
{
     string s;
     cin >> s;

     int upper = 0, lower = 0;

     // Count uppercase and lowercase letters
     for (int i = 0; i < s.size(); i++)
     {
          if (s[i] >= 'A' && s[i] <= 'Z')
               upper++;
          else
               lower++;
     }

     // Decide conversion
     if (upper > lower)
     {
          for (int i = 0; i < s.size(); i++)
          {
               if (s[i] >= 'a' && s[i] <= 'z')
                    s[i] = s[i] - 'a' + 'A'; // convert to uppercase
          }
     }
     else
     {
          for (int i = 0; i < s.size(); i++)
          {
               if (s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = s[i] - 'A' + 'a'; // convert to lowercase
          }
     }

     cout << s << endl;
     return 0;
}
