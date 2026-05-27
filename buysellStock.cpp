// buy ans sell stock
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int arr[], int n)
{
     int minPrice = INT_MAX;
     int maxProfit = 0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i] < minPrice)
          {
               minPrice = arr[i];
          }
          else if (arr[i] - minPrice > maxProfit)
          {
               maxProfit = arr[i] - minPrice;
          }
     }
     return maxProfit;
}
int main()
{
     int arr[] = {7, 1, 5, 3, 6, 4};
     int n = sizeof(arr) / sizeof(arr[0]);
     cout << maxProfit(arr, n) << endl;
     return 0;
}