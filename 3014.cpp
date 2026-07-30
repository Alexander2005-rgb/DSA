//minimum number of pushesh to type word 1

// just like phone kaypad 

#include<bits/stdc++.h>
using namespace std; 


class Solution{
    public: 
    int minimumPushes(string word){
        int n = word.size();    
        int ans = 0; 
        for(int i =0 ; i<n ;++i){
             
            ans += (i/8 + 1) ; 
        } 
        return ans; 
         
    }
};
class Solution1 {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0;
        
        if (n > 0)  ans += min(n, 8) * 1;
        if (n > 8)  ans += min(n - 8, 8) * 2;
        if (n > 16) ans += min(n - 16, 8) * 3;
        if (n > 24) ans += (n - 24) * 4;
        
        return ans;
    }
};

int main(){

    
    string word; 
    cin>> word;
    Solution s;
    cout<< s.minimumPushes(word)<< endl;
    return 0; 
}