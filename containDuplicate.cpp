// wap to find the diuplicate element  int the array
#include <bits/stdc++.h>
using namespace std;
bool containDuplicate(int arr[], int n)
{

     for (int i = 0; i < n; i++)
     {
          for (int j = 1; j < n; j++)
          {
               if (arr[i] == arr[j])
               {
                    return true;
               }
               return false;
          }
     }
     return false;
}
bool containDuplicate1(int arr[], int n)
{
}
int main()
{
     int arr[] = {1, 2, 3, 4, 4, 5, 6};
     int n = sizeof(arr) / sizeof(arr[0]);
     containDuplicate(arr, n) ? cout << "true" << endl : cout << "false" << endl;
     return 0;
}
