// team olypiad
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin >> n;

     int t[5001];                          // store skills
     int prog[5001], math[5001], pe[5001]; // store indices
     int pCount = 0, mCount = 0, peCount = 0;

     for (int i = 1; i <= n; i++)
     {
          cin >> t[i];
          if (t[i] == 1)
               prog[pCount++] = i;
          else if (t[i] == 2)
               math[mCount++] = i;
          else
               pe[peCount++] = i;
     }

     int w = min(pCount, min(mCount, peCount));
     cout << w << "\n";

     for (int i = 0; i < w; i++)
     {
          cout << prog[i] << " " << math[i] << " " << pe[i] << "\n";
     }

     return 0;
}
