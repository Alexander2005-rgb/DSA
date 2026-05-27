// find first and scond maximum element  of the array
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int arr[] = {10, 3, 4, 2, 5, 35, 36, 35, 345, 234, 23, 45, 67};
     int n = sizeof(arr) / sizeof(arr[0]);
     int max = arr[0];
     int secmax = arr[0];
     int thirdmax = arr[0];
     int min = arr[0];
     int secmin = arr[0];
     int thirdmin = arr[0];
     for (int i = 0; i < n; i++)
     {
          if (arr[i] > max)
          {
               thirdmax = secmax;
               secmax = max;
               max = arr[i];
          }
          else if (arr[i] > secmax)
          {
               thirdmax = secmax;
               secmax = arr[i];
          }
          else if (arr[i] > thirdmax)
          {
               thirdmax = arr[i];
          }
     }
     for (int i = 0; i < n; i++)
     {
          if (arr[i] < min)
          {
               thirdmin = secmin;
               secmin = min;
               min = arr[i];
          }
          else if (arr[i] < secmin)
          {
               thirdmin = secmin;
               secmin = arr[i];
          }
          else if (arr[i] < thirdmin)
          {
               thirdmin = arr[i];
          }
     }

     cout << max << endl;
     cout << secmax << endl;
     cout << thirdmax << endl;
     cout << min << endl;
     cout << secmin << endl;
     cout << thirdmin << endl;

     return 0;
}
