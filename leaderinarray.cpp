// leader in array
#include <bits/stdc++.h>>
using namespace std;
void leader(int arr[], int n)
{
     int curr_lead = arr[n - 1];
     cout << curr_lead << " ";
     for (int i = n - 2; i >= 0; i--)
     {
          if (arr[i] > curr_lead)
          {
               curr_lead = arr[i];
               cout << curr_lead << " ";
          }
     }
}
void lead1(int *arr, int n)
{
     for (int i = n - 2; i >= 0; i--)
     {
          arr[i] > arr[i + 1] ? arr[i] = arr[i] : arr[i] = arr[i + 1];
     }
     for (int i = 0; i < n; i++)
     {
          if (arr[i] != arr[i + 1])
               cout << arr[i] << " ";
     }
}
void leaderloop(int arr[], int n)
{
     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (arr[i] < arr[j])
               {
                    break;
               }
               if (j == n - 1)
               {
                    cout << arr[i] << " ";
               }
          }
     }
     cout << arr[n - 1] << " ";
}

int main()
{
     int arr[] = {9, 18, 16, 17, 4, 3, 5, 2};
     int n = sizeof(arr) / sizeof(arr[0]);
     // leader(arr, n);
     lead1(arr, n);
     // leaderloop(arr, n);

     return 0;
}
