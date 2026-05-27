#include <bits/stdc++.h>
using namespace std;
void sum(int arr[], int n, int target)
{
     int i = 0;
     int j = n - 1;
     while (i < j)
     {
          int ans = arr[i] + arr[j];
          if (ans == target)
          {
               cout << "yes" << endl;
               return; // Exit the function since a pair is found
          }
          else if (ans < target)
          {
               i++;
          }
          else
          {
               j--;
          }
     }
     // This line is only reached if the loop completes without finding a pair.
     cout << "no found" << endl;
}
int main()
{
     int arr[] = {1, 2, 4, 6, 8};     
     int n = sizeof(arr) / sizeof(arr[0]);
     int target = 8;
     sum(arr, n, target);
     return 0;
}