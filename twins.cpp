// twins mean 1 has more money to other with minimal count of coins
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cin >> n;
     int a[100]; // since n ≤ 100
     int total = 0;
     for (int i = 0; i < n; i++)
     {
          cin >> a[i];
          total += a[i];
     }
     sort(a, a + n);
     reverse(a, a + n);
     int mySum = 0, count = 0;
     for (int i = 0; i < n; i++)
     {
          mySum += a[i];
          count++;
          if (mySum > total - mySum)
          {
               cout << count << endl;
               break;
          }
     }
     return 0;
}
