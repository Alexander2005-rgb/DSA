// add sum of elment of the array
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6};
     int n = sizeof(arr) / sizeof(arr[0]);
     int total = 0;
     for (int i = 0; i < n; i++)
     {
          total += i;
     }
     cout << total << endl;
     if (total % 2 == 0)
     {
          cout << "even number";
     }
     else
     {
          cout << "odd number";
     }
     return 0;
}
