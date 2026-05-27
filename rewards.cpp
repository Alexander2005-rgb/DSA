// reward any shelf cannot contain both cups and medals at the same time;
// no shelf can contain more than five cups;
// no shelf can have more than ten medals.
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int a1, a2, a3;
     int b1, b2, b3;
     cin >> a1 >> a2 >> a3;
     cin >> b1 >> b2 >> b3;
     int n;
     cin >> n;
     int total_cup = a1 + a2 + a3;
     int total_medal = b1 + b2 + b3;
     int x = total_cup / 5;
     if (total_cup % 5 != 0)
     {
          x++;
     }
     int y = total_medal / 10;
     if (total_medal % 10 != 0)
     {
          y++;
     }

     if (x + y > n)
     {
          cout << "NO" << endl;
     }
     else
     {
          cout << "YES" << endl;
     }

     return 0;
}