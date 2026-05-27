
// which will take an input array as a user and reverse and than print that of array
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];

//     make function for loop to reverse the array
int ReverseArrayByLopp()
{

     cout << "Reversed array is: ";
     for (int i = n - 1; i >= 0; i--)
     {
          cout << arr[i] << " ";
     }
     return 0;
};
void ReverseBySwap()
{

     int start = 0;
     int end = n - 1;
     while (start < end)
     {
          int temp = arr[start];
          arr[start] = arr[end];
          arr[end] = temp;
          start++;
          end--;
     }
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
};

int main()
{
     // make all variable to global
     cout << "Enter the size of array: ";
     cin >> n;

     cout << "Enter the elements of array: ";
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }
     //   reverseArrayByLopp();
     ReverseBySwap();
}
