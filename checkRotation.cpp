// wap which wil  take two input as a user and check it is a rotation of each other or not
#include <bits/stdc++.h>
using namespace std;

int rotate(int arr1[], int arr2[], int n)
{
     for (int i = 0; i < n; i++)
     {
          bool flag = true;
          for (int j = 0; j < n; j++)
          {
               if (arr1[(i + j) % n] != arr2[j])
               {
                    flag = false;
                    break;
               }
          }
          if (flag)
          {
               return 1; // They are rotations of each other
          }
     }
     return 0; // They are not rotations of each other
}
int checkRotated(int arr[], int arr1[], int n)
{
     int temp[n + n];
     int index = 0;
     for (int i = 0; i < n; i++)
     {
          temp[index++] = arr1[i];
          // index++
     }
     for (int i = 0; i < n; i++)
     {
          temp[index++] = arr1[i];
     }

     for (index = 0; index < n + n; index++)
     {
          if (arr[0] == temp[index])
          {
               break;
          }
     }
     for (int i = 0; i < n; i++)
     {
          if (arr[i] != temp[index++])
          {
               return -1;
          }
     }
     return 1;
}

// int main()
// {
//      int arr1[] = {1, 2, 3, 4, 5};
//      int arr2[] = {4, 5, 2, 1, 3};
//      int n = sizeof(arr1[n]) / sizeof(arr1[0]);
//      int n = sizeof(arr2[n]) / sizeof(arr2[0]);
//      cout << rotate(arr1, arr2, n);
//      return 0;
// }
int main()
{
     int n;
     cout << "Enter the size of the arrray " << endl;
     cin >> n;
     int arr[n];
     cout << "Enter the next array element " << endl;
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }
     int arr1[n];
     cout << "Enter the array element" << endl;
     for (int i = 0; i < n; i++)
     {
          cin >> arr1[i];
     }

     int ans = checkRotated(arr, arr1, n);
     if (ans == 1)
     {
          cout << "itis rotated";
     }
     else
     {
          cout << "it is not roated";
     }
}
