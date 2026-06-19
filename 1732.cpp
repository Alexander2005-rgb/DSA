// find the highest altitude
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_altitude = 0;
        int max_altitude = 0;

        for (int g : gain) {
            current_altitude += g;
            if (current_altitude > max_altitude) {
                max_altitude = current_altitude;
            }
        }
        return max_altitude;
    }
};


int main(){
    Solution s;
    vector<int> gain = {-5,1,5,0,-7};
    cout << s.largestAltitude(gain) << endl;
    return 0;
}
