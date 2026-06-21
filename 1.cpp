// Problem Statement : 
// 2 sum problem 
/**
after anlysing problem first we think the method we can use for it
1. Brute Force  time complexity o(n^2) and space complexity o(1)
2. By using the two pointer method time complexity o(n) and space complexity o(1)
3. By using the unorderd map  time complexity o(n) and space complexity o(n)  



*/ 


#include <bits/stdc++.h>
using namespace std;

// burit force method 
void sum1(int arr[], int n, int target)
{
     for(int i = 0; i < n; i++)
     {
          for(int j = i + 1; j < n; j++)
          {
               int ans = arr[i] + arr[j];
               if(ans == target)
               {
                    cout << "yes" << endl;
                    return; 
               }
          }
     }
     cout << "no found" << endl;
}

// by using the unordered map method 
void sum2(int arr[], int n, int target)
{
     // first create a unordered map 
     unordered_map<int, int> map;
     for(int i = 0; i < n; i++)
     {
          int complement = target - arr[i];
          if(map.find(complement) != map.end())
          {
               cout << "yes" << endl;
               return; 
          }
          map[arr[i]] = i;
     }
     cout << "no found" << endl;
}

// two pointer method 
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