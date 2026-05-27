// jump game 4


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        // Build adjacency: value -> list of indices
        unordered_map<int, vector<int>> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[arr[i]].push_back(i);
        }
        
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            // Check neighbors
            // i + 1
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                if (i + 1 == n - 1) return dist[i + 1];
                q.push(i + 1);
            }
            // i - 1
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }
            // Same value jumps
            if (valToIdx.count(arr[i])) {
                for (int j : valToIdx[arr[i]]) {
                    if (j != i && dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        if (j == n - 1) return dist[j];
                        q.push(j);
                    }
                }
                // Key optimization: clear the list so we never reprocess
                valToIdx.erase(arr[i]);
            }
        }
        
        return dist[n - 1];
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<s.minJumps(arr);
    return 0;

    

}