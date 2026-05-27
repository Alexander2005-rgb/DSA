// presents
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cin >> n;
     int arr[101];
     int ans[101];
     for (int i = 1; i <= n; i++)
     {
          cin >> arr[i];
     }
     for (int i = 1; i <= n; i++)
     {
          ans[arr[i]] = i;
     }
     for (int i = 1; i <= n; i++)
          cout << ans[i] << " ";
     return 0;
}
