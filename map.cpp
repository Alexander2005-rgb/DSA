#include <bits/stdc++.h>
using namespace std;
int main()
{
     map<int, string> student;

     // insert
     student[5] = "Aman";
     student.insert({2, "shivani"});
     student.insert({4, "Aditya"});
     student[10] = "shivendra";
     // Access the value of the array
     cout << student[10];

     // check if the given element exist
     if (student.find(4) != student.end())
     {
          cout << "\n found\n";
     }
     else
     {
          cout << "\nnot found\n";
     }

     // traverse the map
     for (auto &x : student)
     {
          cout << x.first << "-->" << x.second << endl;
     }
}
