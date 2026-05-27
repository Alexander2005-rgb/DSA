// vanya and fench
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n, h;
     cin >> n >> h;
     int arr[n];
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }
     for (int i = 0; i < n; i++)
     {
          if (arr[i] > h)
          {
               arr[i] = 2;
          }
          else
          {
               arr[i] = 1;
          }
     }
     int cnt = 0;

     for (int i = 0; i < n; i++)
     {
          cnt += arr[i];
     }
     cout << cnt << endl;
     return 0;
}