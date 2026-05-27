// cheap travel
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n, m, a, b;
     cin >> n >> m >> a >> b;
     int full = n / m;
     int remaining = n % m;
     int cost = full * b + min(remaining * a, b);
     int single = n * a;
     cout << min(cost, single) << endl;
     return 0;
}