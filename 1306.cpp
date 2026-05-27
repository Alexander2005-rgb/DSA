// jump game 3
// Understanding the Problem: We need to determine if there's a path from a starting index to an index with value 0. The array values dictate the jumps.

// Choosing the Algorithm:

// BFS: Explores the array level by level, ensuring that we find the closest 0 first (in terms of the number of jumps).
// DFS: Explores each branch as far as possible before backtracking.
// Since we're only interested in whether a 0 can be reached, either BFS or DFS would work. However, the provided solution uses BFS, so we'll stick with that approach.

// Data Structures:

// queue: For BFS, to hold the indices to visit.
// vector<bool> visited: To keep track of visited indices to prevent cycles and redundant exploration.
// Algorithm Steps (BFS):
// a. Initialize a queue with the starting index.
// b. Mark the starting index as visited.
// c. While the queue is not empty:
// i. Dequeue an index from the queue.
// ii. If the value at that index is 0, return true.
// iii. Calculate the next possible indices by jumping forward and backward.
// iv. If a next index is valid (within array bounds) and not visited:
// a. Enqueue the next index.
// b. Mark the next index as visited.
// d. If the queue becomes empty without finding a 0, return false.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        // create a bollean vector to keep track of visited indices to prevent cycles 
        vector<bool> visited(n, false);
        // create a queue q to astore the indics to b visited during bfs 
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (arr[curr] == 0) {
                return true;
            }
            
            int next1 = curr + arr[curr];
            int next2 = curr - arr[curr];
            
            if (next1 >= 0 && next1 < n && !visited[next1]) {
                q.push(next1);
                visited[next1] = true;
            }
            
            if (next2 >= 0 && next2 < n && !visited[next2]) {
                q.push(next2);
                visited[next2] = true;
            }
        }
        
        return false;
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start;
    cin>>start;
    cout<<s.canReach(arr,start)<<endl;
    return 0;
}