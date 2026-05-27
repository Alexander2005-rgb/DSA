// find the prefix common array of two arrays
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C;
        int n = A.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j <= i; j++){
                for(int k = 0; k <= i; k++){
                    if(A[j] == B[k]){
                        count++;
                        break;
                    }
                }
            }
            C.push_back(count);
        }
        return C;
    }
};
class Solution2 {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        // We need to find the number of common elements in the prefix of A and B
        // For each index i, we need to find the number of common elements in A[0...i] and B[0...i] . so we use frequency array of size n+1
        // if freq[A[i]] == 2 or freq[B[i]] == 2 then it means that the element is common

        vector<int> C(n,0);// create the vector C of size n initialized with 0 
        vector<int>freq(n + 1 ,0);// create the frequency array of size n+1 initialized with 0
        int count =0;// initialize the count of common elements to 0
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            freq[B[i]]++;
            if(freq[A[i]] == 2){
                count++;
            }
            if(freq[B[i]] == 2){
                count++;
            }
            C[i] = count;
        }
        return C;
    }
};



int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int> B(n);
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    vector<int> C = s.findThePrefixCommonArray(A,B);
    for(int i=0;i<C.size();i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
    return 0;
}
