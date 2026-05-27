// drinks and make coctail out should be in 12 digit after decimal
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cin >> n;
     int arr[n];
     double total = 0;
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }
     for (int i = 0; i < n; i++)
     {
          total += arr[i];
     }

     double avg = total / n;

     cout << avg << setprecision(12);
     return 0;
}