// wap which will find if there any pair exist to the given element sum
#include <bits/stdc++.h>
using namespace std;

void pairsum(int arr[], int n)
{
     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (arr[i] + arr[j] == 9)
               {
                    cout << "pair found: " << arr[i] << " " << arr[j] << endl;
                    return;
               }
          }
     }
     cout << "pair not found" << endl;
}
int main()
{
     int arr[] = {1, 2, 3, 4, 5};
     int n = sizeof(arr) / sizeof(arr[0]);
     int sum = 9;
     pairsum(arr, n);
     return 0;
}