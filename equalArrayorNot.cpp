// wap which will take two input array form user and check both array are same or not

#include <bits/stdc++.h>
using namespace std;
void equalArray(int arr1[], int arr2[])
{
     map<int, int> same;
     for (int i = 0; i < 5; i++)
     {
          same[arr1[i]]++;
          same[arr2[i]]--;
     }

     for (auto &x : same)
     {
          cout << x.first << "-->" << x.second << endl;
     }
}
int main()
{
     int arr1[5];
     int arr2[5];
     cin >> arr1[5] >> arr2[5];
     equalArray(arr1, arr2);
     return 0;
}