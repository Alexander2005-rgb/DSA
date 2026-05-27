#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin >> n;

     long long time[100000]; // since n ≤ 1e5
     for (int i = 0; i < n; i++)
     {
          cin >> time[i];
     }

     long long minTime = time[0];
     int minIndex = 1; // towns are numbered from 1
     bool multiple = false;

     for (int i = 1; i < n; i++)
     {
          if (time[i] < minTime)
          {
               minTime = time[i];
               minIndex = i + 1; // +1 because towns are 1-indexed
               multiple = false;
          }
          else if (time[i] == minTime)
          {
               multiple = true;
          }
     }

     if (multiple)
     {
          cout << "Still Rozdil" << endl;
     }
     else
     {
          cout << minIndex << endl;
     }

     return 0;
}
